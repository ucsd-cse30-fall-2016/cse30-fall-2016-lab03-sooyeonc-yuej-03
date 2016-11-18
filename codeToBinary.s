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
    
    @ r5 is copy of input file
    MOV r5, r0
    @ r6 is copy of output file
    MOV r6, r1
    @ r7 is index
    MOV r7, r2
    @ r8 holds bit
    MOV r8, #0
    @ r9 holds char
    MOV r9, #0
    @ r0 is pointer
    MOV r0, #1
    BL malloc
    @ move address of pointer to r4
    MOV r4, r0
loop: 
    @ get input file (once more)
    MOV r0, r5
    BL fgetc
    @ mov char to r9
    MOV r9, r0
    @ check EOF
    CMP r9, #-1
    BLE end
    @ move char to r0
    LDRB r0, [r9]
    @ index at r1
    MOV r1, r7
    BL extractBit
    @ compare bit to '0'
    CMP r0, #48
    BEQ assignZero
    @ assign 1
    MOV r10, #49
    STRB r10, [r4]
    B skipAssignZero
assignZero:
    @ assign 0
    MOV r10, #48
    STRB r10, [r4]
skipAssignZero:
    @ move pointer to r0
    MOV r0, r4
    @ moving other necessary values for fwrite
    MOV r1, #1
    MOV r2, #1
    MOV r3, r6
    BL fwrite
    @ back to top of loop
    B loop
    
end:
    MOV r0, r4
    BL free

    @-----------------------
return:
    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

.end
