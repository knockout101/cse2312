.global addU32_U64

.text

addU32_U64:
    adds r0, r0, r1
    mov r1, #0 @ clear register  r1 before handling the carry
    adc r1, r1, #0
    bx lr
