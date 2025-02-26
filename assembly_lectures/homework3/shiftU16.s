.global shiftU16

.text

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
