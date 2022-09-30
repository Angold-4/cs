.globl main
main:
  mov $3, %rax
  push %rax
  mov $1, %rax
  pop %rdi add %rdi, %rax
  ret
