.macro print (%problem)
	li $v0 4
        la $a0 %problem             #Macro to print
        syscall
        .end_macro
.data
	intro: .asciiz "Give me three integers, i will give back the two biggest ones\n"
	endl: .asciiz "\n"
	x: .space 10
	y: .space 10
	z: .space 10
.text

	print (intro)
	li $v0 5
	la $a0 x
	syscall              #get x, put in s0
	add $s0, $v0, $zero
	
	li $v0 5
	la $a0 y                #get y, put in s1
	syscall
	add $s1, $v0, $zero
	
	li $v0 5
	la $a0 z
	syscall                    #get z, put in s2
	add $s2, $v0, $zero
	
	#x-> $s0
	#y-> $s1
	#z-> $s2
	
	bge $s0, $s1, xgy  #x>y 
	bge $s1, $s0, ygx #y>x 
	
	xgy:
		bge $s1, $s2, pxy #x>y>z
		j pxz             #x>z>y
	
	ygx:
		bge $s2, $s0, pyz #y>z>x
		j pxy             #y>x>z
	
	pxy:
		add $t0, $s0, $s1
		add $a0, $t0, $zero
		li $v0 1             #print out x+y
		syscall
		j exit     #go to exit
	
	pxz:
		add $t0, $s0, $s2
		add $a0, $t0, $zero     #print out x+z
		li $v0 1
		syscall
		j exit     #go to exit
	
	pyz:
		add $t0, $s1, $s2
		add $a0, $t0, $zero      #print out y+z
		li $v0 1
		syscall
		j exit       #go to exit
		
	exit: #do nothing
	
	
