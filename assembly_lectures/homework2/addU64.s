.global addU64 

.text 

addU64:
    adds r0, r0, r2
    adc r1, r1, r3 
    bx lr
    