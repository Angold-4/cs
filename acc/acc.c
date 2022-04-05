#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Args Err!\n");
    return 1;
  }

  char *p = argv[1]; // char pointer

  printf(".intel_syntax noprefix\n");
  printf(".globl _main\n");
  printf("_main:\n");
  printf("  mov rax, %ld\n", strtol(p, &p, 10)); // base 10

  while (*p) {
      if (*p == '+') {
	  p++;
	  printf("  add rax, %ld\n", strtol(p, &p, 10));
	  continue;
      }

      if (*p == '-') {
	  p++;
	  printf("  sub rax, %ld\n", strtol(p, &p, 10));
	  continue;
      }

      fprintf(stderr, "invalid input: %c\n", *p);
      return 1;
  }

  printf("  ret\n");
  return 0;
}
