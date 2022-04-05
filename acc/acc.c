#include <ctype.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

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

// Reports an error and exit.
static void error(char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  vfprintf(stderr, fmt, ap);
  fprintf(stderr, "\n");
  exit(1);
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
    error("expected '%s'", s);
  return tok->next;
}

// Ensure that the current token is TK_NUM.
static int get_number(Token *tok) {
  if (tok->kind != TK_NUM)
    error("expected a number");
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


// Tokenize `p` and returns new tokens
static Token *tokenize(char *p) {
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

	// Puntuator
	if (*p == '+' || *p == '-') {
	    cur = cur->next = new_token(TK_PUNCT, p, p+1);
	    // we know exactly the len is 1
	    // and the val is record on its tok->loc
	    p++;
	    continue;
	}

	error("Invalid token!");
    }
    cur = cur->next = new_token(TK_EOF, p, p);
    // move the cur linked list pointer
    return head.next;
}


int main(int argc, char **argv) {
  if (argc != 2) {
      error("%s: invalid number of arguments", argv[0]);
  }

  Token *tok = tokenize(argv[1]);

  printf(".section	__TEXT,__text,regular,pure_instructions\n");
  printf(".build_version macos, 12, 0	sdk_version 12, 0\n");
  printf(".globl _main\n");
  printf("_main:\n");

  // The first token must be an number
  printf("  mov $%d, %%rax\n", get_number(tok));
  tok = tok->next;


  // ... followed by either `+ <number>` or `- <number>`.
  while (tok->kind != TK_EOF) {
      if (equal(tok, "+")) {
	  printf("  add $%d, %%rax\n", get_number(tok->next));
	  tok = tok->next->next;
	  continue;
      }

      tok = skip(tok, "-"); // will move the pointer here
      printf("  sub $%d, %%rax\n", get_number(tok));
      tok = tok->next;
  }

  printf("  ret\n");
  return 0;
}
