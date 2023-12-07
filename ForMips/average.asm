.macro print (%problem)
	li $v0 4
        la $a0 %problem             #Macro to print
        syscall
        .end_macro
        
.data
	float_print: .asciiz "\nPlease enter a 3 digit decimal d.dd: "
	float_input: .space 10
	intro_print: .asciiz "How many numbers would you like to average? "
	how_many:    .space 10
	result:      .asciiz "The average is: "
.text

	print(intro_print) #print intro
	
	li $v0 5
	la $a0 how_many #get the amount of numbers
	syscall
	add $s0, $v0, $zero   #put that number into s0
	
	loop:
		print(float_print)      
		li $v0 6             #read in a float
		la $a0 float_input
		syscall
		
		add.s $f2, $f2, $f0  #add up all of the inputs
		
		        	
		addi $s1,$s1, 1 
		bne $s0, $s1, loop #loop for the amount of numbers the user wanted to input
		mtc1 $s0, $f1 #switch the number of inputs to a float register
		
		
		cvt.s.w $f4, $f1 #switch it to a float number
		
		div.s $f12, $f2, $f4 # divide the sum by the number of inputs
		
		print(result) 
		li $v0 2 #print out the result
		syscall
		
		
		
	
        
	
