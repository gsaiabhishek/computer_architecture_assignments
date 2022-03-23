.data
arr:	.space 40

.text
.globl main
main:

# li $t0 0

# li $t1 1
# sw $t1 arr($t0)
# addi $t0 $t0 4

# li $t1 2
# sw $t1 arr($t0)
# addi $t0 $t0 4

# li $t1 3
# sw $t1 arr($t0)
# addi $t0 $t0 4

# li $t1 4
# sw $t1 arr($t0)
# addi $t0 $t0 4

# li $t1 5
# sw $t1 arr($t0)
# addi $t0 $t0 4

# li $t1 6
# sw $t1 arr($t0)
# addi $t0 $t0 4

# li $t1 7
# sw $t1 arr($t0)
# addi $t0 $t0 4

# li $t1 8
# sw $t1 arr($t0)
# addi $t0 $t0 4

# li $t1 9
# sw $t1 arr($t0)
# addi $t0 $t0 4

# li $t1 10
# sw $t1 arr($t0)
# addi $t0 $t0 4
li $t1 0
addi $t1 $t1 0x00002000
EXIT:
li $v0 10
syscall