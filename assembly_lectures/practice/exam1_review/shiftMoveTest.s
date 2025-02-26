.global shiftMoveTest

.text

shiftMoveTest:
    tst r1, #0x80000000 @ test sign bit
    bmi negative_shift
    mov r0, r0, lsl r1
    bx lr

negative_shift:
    mvn r1, r1
    add r1, #1
    mov r0, r0, asr r1
    bx lr
