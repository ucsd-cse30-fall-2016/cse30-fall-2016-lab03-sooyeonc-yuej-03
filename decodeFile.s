@ Sooyeon E. Chough (A92093139)
@ Yue Jiang (A92095681)

.syntax unified

.text

.align 3
.global decodeFile
.func decodeFile, decodeFile
.type decodeFile, %function
 
@ void decodeFile(char *input, char *bin, char * output, int index)
decodeFile:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}

    @ YOUR CODE GOES HERE
    @-----------------------
    
    @ r5 is input
    MOV r5, r0
    @ r6 is bin
    MOV r6, r1
    @ r7 is output
    MOV r7, r2
    @ r8 is index
    MOV r8, r3
    @ r1 is 'r' aka read
    MOV r1, #114
    BL fopen

    @-----------------------
return:
    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

.end
