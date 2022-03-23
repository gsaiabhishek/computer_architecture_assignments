.text



main:

li $v0 5
syscall
move $t0 $v0
addi $t1 $0 1

FACTORIAL:
	beq $t0 0 EXIT 
	mul $t1 $t1 $t0
	addi $t0 $t0 -1
	j FACTORIAL



EXIT:
	li $v0 1
	move $a0 $t1
	syscall
	li $v0 10
	syscall