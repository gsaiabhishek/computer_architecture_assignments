.data

.text

main:

li $t1 0x00010010

li $v0 1
move $a0 $t1
syscall

li $v0 10
syscall