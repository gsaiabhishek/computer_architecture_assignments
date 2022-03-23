.data
txt1: .asciiz "Enter m:​ "
txt2: .asciiz "Enter n:​ "
txt3: .asciiz "gcd("
txt4: .asciiz ","
txt5: .asciiz ") = "
txt6: .asciiz "Wish to continue?:​ "
nl: .asciiz "\n"
inp: .space 3

.text

GCD:
	movz $v0 $a0 $a1
	beqz $a1 FINISH
	div $a0 $a1
	mfhi $t7 
	move $a0 $a1
	move $a1 $t7
	addi $sp $sp -4
	sw $ra 0($sp)
	jal GCD
	lw $ra 0($sp)
	addi $sp $sp 4
	j $ra


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
	move $t9 $t0

	li $v0 4
	la $a0 txt2
	syscall

	li $v0 5
	syscall
	move $t1 $v0
	move $t8 $t1
	#need $t0 >= $t1
	slt $t2 $t0 $t1
	move $t3 $t0
	move $t4 $t1
	movn $t0 $t4 $t2
	movn $t1 $t3 $t2

	move $a0 $t0
	move $a1 $t1
	jal GCD
	move $t0 $v0

	# GCD:
	# 	beqz $t1 DONE
	# 	div $t0 $t1
	# 	mfhi $t2
	# 	move $t0 $t1
	# 	move $t1 $t2
	# 	j GCD

	DONE:
		li $v0 4
		la $a0 txt3
		syscall

		li $v0 1
		move $a0 $t9
		syscall

		li $v0 4
		la $a0 txt4
		syscall

		li $v0 1
		move $a0 $t8
		syscall

		li $v0 4
		la $a0 txt5
		syscall

		li $v0 1
		move $a0 $t0
		syscall

		li $v0 4
		la $a0 nl
		syscall

		li $v0 4
		la $a0 txt6
		syscall

		li $v0 8
		la $a0 inp
		li $a1 3
		syscall

		la $t7 inp
		lb $t6 0($t7)
		li $t5 89
		beq $t5 $t6 DO

EXIT:

li $v0 10
syscall



