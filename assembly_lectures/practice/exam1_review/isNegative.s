.global isNegative

.text 

isNegative:
    tst r0, #0x80000000
    bmi is_negative
    mov r0, #0
    bx lr
    
is_negative:
    mov r0, #1
    bx lr
    