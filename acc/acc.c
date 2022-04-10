#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


//
// Tokenizer
// 

typedef enum {
    TK_PUNCT, // Puntuators 0
    TK_NUM,   // Numeric Literals 1
    TK_EOF,   // End-of-file markers 2
} TokenKind;

// Token type
typedef struct Token Token;

struct Token {
    TokenKind kind; // Token kind
    Token *next;    // Next token (linked list)
    int val;        // If kind is TK_NUM, its value
    char *loc;      // Token location (pointer)
    int len;        // Token length
};

// Input string
static char *current_input;

// Reports an error and exit.
static void error(char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  vfprintf(stderr, fmt, ap);
  fprintf(stderr, "\n");
  exit(1);
}

// Reports an error location and exit
static void verror_at(char *loc, char *fmt, va_list ap) {
    // only one line
    int pos = loc - current_input;
    fprintf(stderr, "%s\n", current_input);
    fprintf(stderr, "%*s", pos, ""); // print pos spaces.
    fprintf(stderr, "^ ");
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, "\n");
    exit(1);
}

static void error_at(char *loc, char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  verror_at(loc, fmt, ap);
}


static void error_tok(Token *tok, char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt); // va_start, retrieve ap after parameter fmt
  verror_at(tok->loc, fmt, ap); // because we do not know the fmt
}


// Consumes the current token if it matches `s`.
static bool equal(Token *tok, char *op) {
  // 1. The same character (memcmp)
  // 2. The same length (\0)
  return memcmp(tok->loc, op, tok->len) == 0 && op[tok->len] == '\0';
}

// Ensure that the current token is `s`.
static Token *skip(Token *tok, char *s) {
  if (!equal(tok, s))
    error_tok(tok, "expected '%s'", s);
  return tok->next;
}

// Ensure that the current token is TK_NUM.
static int get_number(Token *tok) {
  if (tok->kind != TK_NUM)
    error_tok(tok, "expected a number");
  return tok->val;
}

// Create a new token.
static Token *new_token(TokenKind kind, char *start, char *end) {
  Token *tok = calloc(1, sizeof(Token));
  // calloc allocate count objects that are size bytes of memory each
  tok->kind = kind;
  tok->loc = start;
  tok->len = end - start;
  return tok;
}


// Tokenize current input and returns new tokens
static Token *tokenize(void) {
    char *p = current_input;
    Token head = {};
    Token *cur = &head;

    while (*p) {
	// Skip white space characters
	if (isspace(*p)) {
	    p++;
	    continue;
	}

	// Numeric Literal
	if (isdigit(*p)) {
	    cur = cur->next = new_token(TK_NUM, p, p); 
	    // we do not know the len now, and will set later
	    char *q = p;
	    cur->val = strtoul(p, &p, 10); // str -> unsigned long
	    // and it will move the pointer
	    cur->len = p - q;
	    continue;
	}

	// Puntuators
	if (ispunct(*p)) {
	    cur = cur->next = new_token(TK_PUNCT, p, p+1);
	    // we know exactly the len is 1
	    // and the val is record on its tok->loc
	    p++;
	    continue;
	}

	error_at(p, "Invalid token");
    }
    cur = cur->next = new_token(TK_EOF, p, p);
    // move the cur linked list pointer
    return head.next;
}

//
// Parser
// 
 
typedef enum {
  ND_ADD, // +
  ND_SUB, // -
  ND_MUL, // *
  ND_DIV, // /
  ND_NEG, // unary
  ND_NUM, // integer
  ND_ERR,
} NodeKind;

// AST node type
typedef struct Node Node;
struct Node {
  NodeKind kind; // Node kind
  Node *lhs;     // Left-hand side
  Node *rhs;     // Right-hand side
  int val;       // Used if kind == ND_NUM
};

static Node *new_node(NodeKind kind) {
  // helper function
  Node *node = calloc(1, sizeof(Node));
  node->kind = kind;
  return node;
}

static Node *new_unary(NodeKind kind, Node *expr) {
  Node *node = new_node(kind);
  node->lhs = expr;
  return node;
}

static Node *new_binary(NodeKind kind, Node *lhs, Node *rhs) {
  Node *node = new_node(kind);
  node->lhs = lhs;
  node->rhs = rhs;
  return node;
}

static Node *new_num(int val) {
  Node *node = new_node(ND_NUM);
  node->val = val;
  return node;
}

static Node *expr(Token **rest, Token *tok);
static Node *mul(Token **rest, Token *tok);
static Node *unary(Token **rest, Token *tok);
static Node *primary(Token **rest, Token *tok);



// expr = mul ("+" mul | '-' mul)* 
static Node *expr(Token **rest, Token *tok) { 
  // rest -> move the pointer after finish
  Node *node = mul(&tok, tok);
  for (;;) { // *
    if (equal(tok, "+")) {
      node = new_binary(ND_ADD, node, mul(&tok, tok->next));
      continue;
    }
    if (equal(tok, "-")) {
      node = new_binary(ND_SUB, node, mul(&tok, tok->next));
      continue;
    }
    *rest = tok; // update pointer
    return node;
  }
}

// mul = unary ("*" unary | "/" unary)*
static Node *mul(Token **rest, Token *tok) {
  Node *node = unary(&tok, tok);

  for (;;) { // *
    if (equal(tok, "*")) {
      node = new_binary(ND_MUL, node, unary(&tok, tok->next));
      continue;
    }

    if (equal(tok, "/")) {
      node = new_binary(ND_DIV, node, unary(&tok, tok->next));
      continue;
    }

    *rest = tok; // update pointer
    return node;
  }
}

// unary = ("+" | "-") unary
// 	 | primary
static Node *unary(Token **rest, Token *tok) {
  if (equal(tok, "+")) {
    // ignore this
    return unary(rest, tok->next);
  }

  if (equal(tok, "-")) {
    return new_unary(ND_NEG, unary(rest, tok->next));
  }

  return primary(rest, tok);
}


// primary = "(" expr ")" | num
static Node *primary(Token **rest, Token *tok) {
  if (equal(tok, "(")) {
    Node *node = expr(&tok, tok->next);
    *rest = skip(tok, ")");
    return node;
  }

  if (tok->kind == TK_NUM) {
    Node *node = new_num(tok->val);
    *rest = tok->next; // also update the pointer
    return node;
  }

  error_tok(tok, "Unexpected an expression");
  return new_node(ND_ERR); // never go to there
}


//
// Code Generator
//

static int depth;

static void push(void) {
  printf("  push %%rax\n");
  depth++;
}

static void pop(char *arg) {
  printf("  pop %s\n", arg);
  depth--;
}

static void gen_expr(Node *node) {
  // unary / primary
  switch (node->kind) {
  case ND_NUM:
    printf("  mov $%d, %%rax\n", node->val);
    return;
  case ND_NEG:
    gen_expr(node->lhs);
    printf("  neg %%rax\n");
    return;
  default:
    break;
  }

  gen_expr(node->rhs);
  push();
  gen_expr(node->lhs); // rax
  pop("%rdi"); // we do not touch rax

  switch (node->kind) {
  // store in rax
  case ND_ADD:
    printf("  add %%rdi, %%rax\n");
    return;
  case ND_SUB:
    printf("  sub %%rdi, %%rax\n");
    return;
  case ND_MUL:
    printf("  imul %%rdi, %%rax\n");
    return;
  case ND_DIV:
    printf("  cqo\n");
    printf("  idiv %%rdi\n");
    return;
  default:
    return;
  }

  error("invalid expression");
}


int main(int argc, char **argv) {
  if (argc != 2) {
      error("%s: invalid number of arguments", argv[0]);
  }

  current_input = argv[1];

  // Tokenizer
  Token *tok = tokenize();

  // Parser
  Node *node = expr(&tok, tok);

  if (tok->kind != TK_EOF) {
    error_tok(tok, "Extra token");
  }

  // Code Generator
  printf(".section	__TEXT,__text,regular,pure_instructions\n");
  printf(".build_version macos, 12, 0	sdk_version 12, 0\n");
  printf(".globl _main\n");
  printf("_main:\n");

  gen_expr(node);

  printf("  ret\n");
  assert(depth == 0);

  return 0;
}
