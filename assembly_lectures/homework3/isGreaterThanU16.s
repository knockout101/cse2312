.global isGreaterThanU16

.text

isGreaterThanU16:
    cmp r0, r1      @ compare r0 and r1 (r0 - r1)
    mov r0, #1      @ Move immediate 0 to r0
    movls r0, #0    @ if C is clear, Z is set move immediate 1 to r0
    bx lr
