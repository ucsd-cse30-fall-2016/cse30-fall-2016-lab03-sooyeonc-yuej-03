@ Sooyeon E. Chough (A92093139)
@ Yue Jiang (A92095681)

.syntax unified

.text

.align 3
.global codeToBinary
.func codeToBinary, codeToBinary
.type codeToBinary, %function

@void codeToBinary(FILE *in, FILE *out, int index);

codeToBinary:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}

    @-----------------------
    
    @ r4 is copy of input file
    MOV r4, r0
    @ r5 is copy of output file
    MOV r5, r1
    @ r6 is index
    MOV r6, r2
    @ r7 holds bit
    MOV r7, #0
    @ holds char
    MOV r8, #0
    @ r0 is pointer
    MOV r0, #4
    BL malloc
    @ move pointer to r9
    MOV r9, r0
loop: 
    @ get input file once more
    MOV r0, r4
    BL fgetc
    @ mov char to r8
    MOV r8, r0
    @ check EOF
    CMP r8, #0
    BEQ end
    @ move char to r0
    MOV r0, r8
    @ index at r1
    MOV r1, r6
    BL extractBit
    @ compare bit to '0'
    CMP r0, #48
    BEQ assignZero
assignOne:
    @ assign 1
    MOV r9, #49
assignZero:
    @ assign 0
    MOV r9, #48
    @ move pointer to r9
    MOV r0, r9
    @ moving other necessary values for fwrite
    MOV r1, #1
    MOV r2, #1
    MOV r3, r5
    BL fwrite
    @ back to top of loop
    B loop
end:
    MOV r0, r9
    BL free

    @-----------------------
return:
    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

.end
