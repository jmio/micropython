    .section .text
    .globl _start
_start:
	/* Clearing .bss */
	la	t0, __bss_start
	la	t1, _end
_loop_clear_bss:
	bge	t0, t1, _end_clear_bss
	sw	x0, 0(t0)
	addi	t0, t0, 4
	j	_loop_clear_bss
_end_clear_bss:
    j main

    // int r = syscall0(int num);
	.globl syscall0
syscall0:
	addi	sp,sp,-16
	sw	ra,12(sp)
	sw	s0,8(sp)
	mv	a7,a0
	ecall
	lw	ra,12(sp)
	lw	s0,8(sp)
	addi	sp,sp,16
	ret

