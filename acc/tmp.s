.section	__TEXT,__text,regular,pure_instructions
.build_version macos, 12, 0	sdk_version 12, 0
.globl _main
_main:
  mov $2, %rax
  push %rax
  mov $2, %rax
  pop %rdi
  add %rdi, %rax
  push %rax
  mov $8, %rax
  pop %rdi
  cqo
  idiv %rdi
  ret
