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

    @ YOUR CODE GOES HERE
    @-----------------------
    
    @ (your code)
    @ put your return value in r0 here:

    @-----------------------
return:
    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

.end
