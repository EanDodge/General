.macro print (%problem)
	li $v0 4
        la $a0 %problem             #Macro to print
        syscall
        .end_macro
.data
	intro: .asciiz "Enter numbers you would like to add together, end with a 0\n"
	input_int: .space 10
	
.text

	print(intro) #prinnt intro prompt
	Loop: #will loop back here everytime
	li $v0 5
	la $a0 input_int    #get input
	syscall
	
	add $s0, $v0, $s0 #add input to sum
	
	add $s1, $v0, $zero #used to check if zero
	bne $s1, $zero, Loop #loop until zero
	
	add $a0, $s0, $zero
	li $v0 1              #print out s
	syscall
	
