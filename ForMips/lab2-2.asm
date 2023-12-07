.macro print (%problem)
	li $v0 4
        la $a0 %problem             #Macro to print
        syscall
        .end_macro
.text
	print(intro_print) #prompt
	print(cup_print)   #asking for cup value
	li $v0 5
	la $a0 get_cup     #getting cup vaue
	syscall
	move $s0, $v0
	
	print(mug_print)   #asking for mug value
	li $v0 5
	la $a0 get_mug     #getting mug vaue
	syscall
	move $s1, $v0
	
######################################################

	add $t0, $s0, $zero
	add $s0, $s1, $zero                           #algorithm to swap
	add $s1, $t0, $zero
	
######################################################
	print(result)
	add $a0, $s0, $zero
	li $v0 1
	syscall
	
	print(result1)
	add $a0, $s1, $zero
	li $v0 1
	syscall
	

.data
	intro_print: .asciiz "You will have a cup with an integer in it, a mug with an integer in it, \nand an empty glass. We will use these to swap the values around\n"
	cup_print: .asciiz "What integer value would you like in the cup?\n"
	mug_print: .asciiz "What integer value would you like in the mug?\n"
	
	get_cup: .space 10
	get_mug: .space 10
	
	result: .asciiz "The result is the cup value is "
	result1: .asciiz ", and the mug value is now "
