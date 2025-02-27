.global isGreaterThanS16
.global isGreaterThanU16
.global shiftU16
.global maxU32
.global maxS16
.global isBitSetU32
.global isMultOf4U32
.global isEqualU16

.text

isGreaterThanS16:
    cmp r0, r1
    mov r0, #0
    movgt r0, #1
    bx lr

isGreaterThanU16:
    cmp r0, r1      @ compare r0 and r1 (r0 - r1)
    mov r0, #1      @ Move immediate 0 to r0
    movls r0, #0    @ if C is clear, Z is set move immediate 1 to r0
    bx lr

shiftU16:
    tst r1, #0x80
    bmi negativeShift
    lsl r0, r1
    bx lr

negativeShift:
    mvn r1, r1
    add r1, #1
    lsr r0, r1
    bx lr

maxU32:
    cmp r0, r1      @ compare r0 and r1
    movcc r0, r1    @ if r0 < r1 move r1 to r0
    bx lr

maxS16:
    cmp r0, r1      @ compare r0 and r1 (r0 - r1)
    movlt r0, r1    @ if r0 < r1 move r1 to r0
    bx lr

isBitSetU32:
    lsr r0, r1      @ shift r0 right by (r1 - 1)
    and r0, r0, #0x01   @ and r0 with 0x01 and put into r0
    bx lr

isMultOf4U32:
    ands r0, #0x03   @ checking bit 0 and 1
    mov r0, #0x01    @ force r0 to 1
    movne r0, #0     @ if z flag is 0 set r0 to 0
    bx lr

isEqualU16:
    cmp r0, r1      @ Comparing two inputs
    mov r0, #0x01   @ force r0 to 1
    movne r0, #0    @ if z flag is 0 set r0 to 0
    bx lr
