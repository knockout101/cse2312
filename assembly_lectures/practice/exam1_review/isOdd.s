.global isOdd

.text 

isOdd:
    and r0, r0, #0x01
    bx lr