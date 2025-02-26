.global compare

.text 

compare:
    cmp r0, r1
    mov r0, #0
    moveq r0, #1
    bx lr
