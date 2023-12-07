.macro print (%problem)
	li $v0 4
        la $a0 %problem             #Macro to print
        syscall
        .end_macro
.text

####################################
	print(w_output)
	                           #Getiing W
	li $v0 5
	la $a0 w_input
	li $a1 6
	syscall
	move $s0, $v0
###################################
	
	print(x_output)
	                          #Getting x
	li $v0 5
	la $a0 x_input
	li $a1 6
	syscall
	move $s1, $v0
####################################
	print(y_output)
	                           #Getting y
	li $v0 5
	la $a0 y_input
	li $a1 6
	syscall
	move $s2, $v0
######################################	
	print(z_output)
	                          #Getting z
	li $v0 5
	la $a0 z_input
	li $a1 6
	syscall
	move $s3, $v0
	
#################################
	print(problem1)
        print(problem2)
        print(problem3)  #printing the problem
        print(problem4)
        print(problem5)
        print(problem6)
######################################

sub $t0, $s1, $s2 # x - y
slt $t1, $s0, $t0  #w<(x-y)
bne $t1, $zero, xtoy #if w<(x-y) then x to y
beq $s0, $t0, xtoy #if w == (x-y) then x to y
j xtoz #else x to z
#####################################
xtoz:
	print(resultz)
	add $s4, $s3, $zero #x to y
	j exit
##################################
xtoy:
	print(resulty)
	add $s4, $s2, $zero #x to z
	j exit
###############################
exit:
add $a0, $s4, $zero	#will print out the x value at the end
li $v0 1
syscall
##################################

.data
	w_input: .space 10
	x_input: .space 10
	y_input: .space 10
	z_input: .space 10
	
	w_output: .asciiz "What do you want W to be?\n"
	x_output: .asciiz "What do you want x to be?\n"
	y_output: .asciiz "What do you want y to be?\n"
	z_output: .asciiz "What do you want z to be?\n"
	
	
	problem1: .asciiz "If [(x - y) >= w] then\n"
        problem2: .asciiz "Set x to y\n"
        problem3: .asciiz "Else:\n"
        problem4: .asciiz "Set x to z\n"
        problem5: .asciiz "Endif\n"
        problem6: .asciiz "Print x\n"
        
        resulty: .asciiz "Since it was greater than, or equal to, x will be set to y\n"
        resultz: .asciiz "Since it was less than, x will be set to z\n"
        
	
        	
        
        	

	
	
	
