.section	__TEXT,__text,regular,pure_instructions
.build_version macos, 12, 0	sdk_version 12, 0
.globl _main
_main:
  mov $1, %rax
  push %rax
  mov $2, %rax
  pop %rdi
  cmp %rdi, %rax
  setle %al
  movzb %al, %rax
  ret
