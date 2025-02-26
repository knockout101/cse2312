.global maxU32

.text

maxU32:
    cmp r0, r1      @ compare r0 and r1
    movcc r0, r1    @ if r0 < r1 move r1 to r0
    bx lr
