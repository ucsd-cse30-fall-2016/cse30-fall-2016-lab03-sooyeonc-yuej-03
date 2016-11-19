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

    @-----------------------
    
    @ r4 is bin
    MOV r4, r1
    @ r5 is output
    MOV r5, r2
    @ r6 is index
    MOV r6, r3
    
    @ open input file
    @ r1 is 'r' aka read
    MOV r1, #114
    BL fopen
    
    @ input file is at r7
    MOV r7, r0
    
    @ open bin file
    @ r0 is bin char array 
    MOV r0, r4
    @ r1 is 'w' aka write
    MOV r1, #119
    BL fopen
    
    @ bin file is at r8
    MOV r8, r0
    
    @ codeToBinary( input, bin, index )
    @ input is r0
    MOV r0, r7
    @ bin is r1
    MOV r1, r8
    @ index is r2
    MOV r2, r6
    BL codeToBinary
    
    @ bin file is r8
    MOV r8, r1
    
    @ fclose input file
    BL fclose
    
    @ fclose bin file
    MOV r0, r8
    BL fclose
    
    @ open bin file 
    @ bin char array is r0
    MOV r0, r4
    @ 'r' is r1
    MOV r1, #114
    BL fopen
    
    @ bin file is r8
    MOV r8, r0
    
    @ open output file
    @ output char array is r0
    MOV r0, r5
    @ 'w' aka write is r1
    MOV r1, #119
    BL fopen
    
    @ binaryToText( bin, output )
    @ output is r1
    MOV r1, r0
    @ bin is r0
    MOV r0, r8
    BL binaryToText
    
    @ fclose bin file
    MOV r8, r1
    BL fclose
    
    @ fclose output file
    MOV r0, r8
    BL fclose

    @-----------------------
return:
    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

.end
