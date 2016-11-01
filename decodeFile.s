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
