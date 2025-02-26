.global isGreaterThanS16

.text

isGreaterThanS16:
    cmp r0, r1
    mov r0, #0
    movgt r0, #1
    bx lr
    