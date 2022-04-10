.section	__TEXT,__text,regular,pure_instructions
.build_version macos, 12, 0	sdk_version 12, 0
.globl _main
_main:
  mov $10, %rax
  neg %rax
  neg %rax
  ret
