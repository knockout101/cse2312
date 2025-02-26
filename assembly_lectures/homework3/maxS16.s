.global maxS16

.text

maxS16:
    cmp r0, r1      @ compare r0 and r1 (r0 - r1)
    movlt r0, r1    @ if r0 < r1 move r1 to r0
    bx lr
