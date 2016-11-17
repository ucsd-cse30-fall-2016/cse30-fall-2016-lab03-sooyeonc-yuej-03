@ Sooyeon E. Chough (A92093139)
@ Yue Jiang (A92095681)

.syntax unified

.text

.align 3
.global decodeChar
.func decodeChar, decodeChar
.type decodeChar, %function

@ char decodeChar(char *b)
decodeChar:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}

    @-----------------------
    
    @ r3 and r4 = 0 (loopCount and total)
    MOV r3, #0
    MOV r4, #0
    @ moving r0 to r1 
    MOV r1, r0
    MOV r0, #1
    @ making r0 into a char pointer
    BL malloc 
loop: 
    @ check r3 vs 6
    CMP r3, #6
    @ branching out if r3 >= 6
    BGE end
    @ getting char in array to r1
    LDR r0, [r1, r3]
    @ check r1 vs '1'
    CMP r0, #49
    @ skip if r1 != '1' aka do if r1 = '1'
    BNE skip
    @ get 32 >> loopCount
    MOV r5, #32
    LSR r5, r5, r3
    @ total = total + r5
    ADD r4, r4, r5
skip:
    @ incrementing loopCount
    ADD r3, r3, #1
    @ freeing the pointer
    BL free
    @ check loop again
    B loop
end:    
    @ r6 = MAPPING array
    LDR r6, =MAPPING
    @ MAPPING[ total ]
    LDR r0, [r6, r5]
    
    @-----------------------
return:
    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

.end
