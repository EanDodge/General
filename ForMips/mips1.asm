.text

	add $s3, $s3, $zero
	loop:
		#getting F
		li $v0, 4 #print Question for F
		la $a0, fprint # arguments
		syscall 
		
		li $v0, 5#get f
		la $a0, finput#arguments
		li $a1, 6
		syscall
		move $s0, $v0
		
		#getting G
		li $v0, 4 #print Question for G
		la $a0, gprint #argument
		syscall 
		
		li $v0, 5#get g
		la $a0, ginput#arguments
		li $a1, 6
		syscall
		add $s1, $v0, $zero
		#f = g - (f + 5)
		
		addi $t0, $s0, 5 #f+5
		sub $t1, $s1, $t0 #g-(f+5)
		li $v0, 4 #print result message
		la $a0, result #arguments
		syscall
		
		add $a0, $t1, $zero #move result value into argument register
		li $v0, 1 #print result value
		syscall
		addi $s3, $s3, 1
		bne $s3, 3, loop
		
		
		exit:
			
		
.data


	fprint: .asciiz "\nWhat is F?\n"
	gprint: .asciiz "What is G?\n"
	finput: .space 10
	ginput: .space 10
	result: .asciiz "Your result to f= g-(f+5): "