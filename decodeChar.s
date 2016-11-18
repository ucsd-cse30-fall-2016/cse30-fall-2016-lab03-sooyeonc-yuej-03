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
    
    @ r4 and r5 = 0 (loopCount and total)
    MOV r4, #0
    MOV r5, #0
    @ moving r0 aka char *b to r1 
    MOV r8, r0
    
loop:
    @ check r4 vs 6
    CMP r4, #6
    @ branching out if r4 >= 6 aka continue if r4 < 6
    BGE end
    @ making r0 into a char pointer
    MOV r0, #1
    BL malloc 
    @ getting char in array to r0
    LDR r0, [r8, r4]
    @ check r0 vs '1'
    CMP r0, #49
    @ skip if r0 != '1' aka continue if r0 == '1'
    BNE skip
    @ get 32 >> loopCount
    MOV r6, #32
    LSR r6, r6, r4
    @ total = total + r5
    ADD r5, r5, r6
    
skip:
    @ freeing the pointer
    BL free
    @ incrementing loopCount
    ADD r4, r4, #1
    @ check loop again
    B loop
    
end:    
    @ r0 is MAPPING array
    LDR r0, =MAPPING
    @ r0 is MAPPING[ total ]
    LDR r0, [r0, r5]
    
    @-----------------------
return:
    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

.end
