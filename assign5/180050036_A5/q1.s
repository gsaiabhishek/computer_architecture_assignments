.data
inp: .space 15
inp1: .space 3
txt1: .asciiz "Enter modulus:​ "
txt2: .asciiz "Enter string of 12 decimal digits: "
txt3: .asciiz " mod "
txt4: .asciiz " = "
txt5: .asciiz "Wish to continue?:​ "
txt6: .asciiz "\n"

.text

FUNC:
	li $t1 -1 #counter for 12
	la $t3 inp #pointer to inp
	li $v0 0
	li $t8 10
	ITER:
		addi $t1 $t1 1
		addi $t2 $0 12
		beq $t1 $t2 FINISH
		add $t2 $t1 $t3
		lbu $t4 0($t2)
		addi $t4 $t4 -48
		mul $t5 $t8 $v0
		add $t5 $t5 $t4
		div $t5 $a0
		mfhi $v0
		j ITER
	FINISH:
		jr $ra

main:
DO:
	
	li $v0 4
	la $a0 txt1
	syscall
	li $v0 5
	syscall
	move $t0 $v0
	# $t0 is n(max 4 decimal digits, i.e, no need of accumulator)

	li $v0 4
	la $a0 txt2
	syscall
	li $v0 8
	la $a0 inp
	li $a1 15
	syscall

	move $a0 $t0
	jal FUNC
	move $t9 $v0

	DONE:
		sb $0 12($t3)

		li $v0 4
		la $a0 inp
		syscall

		li $v0 4
		la $a0 txt3
		syscall

		li $v0 1
		move $a0 $t0
		syscall

		li $v0 4
		la $a0 txt4
		syscall

		li $v0 1
		move $a0 $t9
		syscall

		li $v0 4
		la $a0 txt6
		syscall

		li $v0 4
		la $a0 txt5
		syscall

		li $v0 8
		la $a0 inp1
		li $a1 3
		syscall

		la $t3 inp1
		lbu $t4 0($t3)
		li $t5 89
		beq $t4 $t5 DO 



EXIT:

li $v0 10
syscall