.data

arr: .word 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
inp1: .asciiz "Enter No. of integers in list\n"
inp2: .asciiz "Enter list\n"
inp3: .asciiz "Enter k\n"
#intmin: .asciiz "-2147483648\n"

.text

main:
	li $v0 4
	la $a0 inp1
	syscall
	li $v0 5
	syscall
	move $t0 $v0 #n
	li $v0 4
	la $a0 inp2
	syscall
	move $t1 $0 #counter
	la $t2 arr
	move $t9 $0 #boolean for first value in $t4
	INPUT:
		beq $t1 $t0 K
		add $t3 $t1 $t1
		add $t3 $t3 $t1
		add $t3 $t3 $t1
		add $t3 $t2 $t3
		li $v0 5
		syscall
		move $t5 $v0
		sw $t5 0($t3)
		movz $t4 $t5 $t9
		addi $t9 $t9 1
		slt $t6 $t4 $t5
		movn $t4 $t5 $t6 
		addi $t1 $t1 1
		j INPUT
	K:
		li $v0 4
		la $a0 inp3
		syscall
		li $v0 5
		syscall
		move $t3 $v0 #k
	move $t1 $0 # k counter
	# $t4 is ans
	move $t9 $t4
	FUNC:
		slt $t8 $0 $t1
		addi $t8 $t8 -1
		bgezal $t8 CHECK
		move $t4 $t9
		addi $t1 $t1 1
		beq $t1 $t3 EXIT
		li $t5 -1 # n counter
		move $t8 $0 #boolean for 1st search(which is < $t4) happening
		# $t9 is temp for ITER to store max in that ITER which is < $t4
		ITER:
			addi $t5 $t5 1
			beq $t5 $t0 FUNC
			add $t6 $t5 $t5
			add $t6 $t6 $t5
			add $t6 $t6 $t5
			add $t6 $t6 $t2
			lw $t7 0($t6)
			slt $t6 $t7 $t4
			beqz $t6 ITER
			movz $t9 $t7 $t8 
			addi $t8 $t8 1
			slt $t6 $t9 $t7
			movn $t9 $t7 $t6
			j ITER
	CHECK:
		beq $t4 $t9 INTMIN
		jr $ra 
	INTMIN:
		addi $t4 $0 1
		sll $t4 $t4 31
		#la $a0 intmin
		move $a0 $t4
		li $v0 1
		syscall
		li $v0 10
		syscall
	EXIT:
		move $a0 $t4
		li $v0 1
		syscall
		li $v0 10
		syscall

