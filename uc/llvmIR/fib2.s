  .globl fib
  .text
fib:
  push %rbp
  mov %rsp, %rbp
  sub $16, %rsp
  mov %rdi, -8(%rbp)
  mov $2, %rax
  push %rax
  lea -8(%rbp), %rax
  mov (%rax), %rax
  pop %rdi
  cmp %rdi, %rax
  setl %al
  movzb %al, %rax
  cmp $0, %rax
  je .L.else.1
  lea -8(%rbp), %rax
  mov (%rax), %rax
  jmp .L.return.fib
  jmp .L.end.1
.L.else.1:
.L.end.1:
  mov $2, %rax
  push %rax
  lea -8(%rbp), %rax
  mov (%rax), %rax
  pop %rdi
  sub %rdi, %rax
  push %rax
  pop %rdi
  mov $0, %rax
  call fib
  push %rax
  mov $1, %rax
  push %rax
  lea -8(%rbp), %rax
  mov (%rax), %rax
  pop %rdi
  sub %rdi, %rax
  push %rax
  pop %rdi
  mov $0, %rax
  call fib
  pop %rdi
  add %rdi, %rax
  jmp .L.return.fib
.L.return.fib:
  mov %rbp, %rsp
  pop %rbp
  ret

  .globl main
  .text
main:
  push %rbp
  mov %rsp, %rbp
  sub $0, %rsp
  mov $10, %rax
  push %rax
  pop %rdi
  mov $0, %rax
  call fib
  jmp .L.return.main
.L.return.main:
  mov %rbp, %rsp
  pop %rbp
  ret
