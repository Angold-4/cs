.globl main
main:
  mov $1, %rax
  push %rax
  mov $2, %rax
  pop %rdi
  cmp %rdi, %rax
  setle %al
  movzb %al, %rax
  ret
