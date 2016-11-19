@ Sooyeon E. Chough (A92093139)
@ Yue Jiang (A92095681)

.syntax unified

.text

.align 3
.global binaryToText
.func binaryToText, binaryToText
.type binaryToText, %function

@ void binaryToText(FILE *in, FILE *out)
binaryToText:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}

    @-----------------------
    
   MOV r4, r0 @r4 stores in file
   MOV r5, r1 @r5 stores out file
   MOV r6, #0 @char c
   MOV r7, #0 @bin
   
   BL fgetc @ now c is at r0
   MOV r6, r0

while:
   CMP r6, #-1 @check EOF
   BLE end
   MOV r0, #6 
   BL malloc
   MOV r7, r0 @r7 stores bin's address
   MOV r8, #0
   
   CMP r8, #5
   BLE loop
   
back:

   MOV r0, r7
   BL decodeChar
   
   STRB r0, [r7]
   MOV r0, r7
   MOV r1, #1
   MOV r2, #1
   MOV r3, r6
   BL fwrite
   
   MOV r0, r7
   BL free
   B while
   
loop: STRB r6, [r7, r8]
   MOV r0, r4
   BL fgetc
   MOV r6, r0
   ADD r8, r8, #1
   CMP r8, #5
   BLE loop
   B back
   
end:

    @-----------------------
return:
    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

.end
