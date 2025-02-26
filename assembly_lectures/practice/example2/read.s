.global _start

.text

_start:

_read:
    mov r7, #3      @ read syscall 
    mov r0, #0      @ stdin is a keyboard
    mov r2, #5      @ read first 5 characters
    ldr r1, =string @ string placed at string:
    swi 0

_write:
    mov r7, #4      @ write syscall
    mov r0, #1      @ stdout is monitor 
    mov r2, #19     @ string is 19 chars long
    ldr r1, =string @ string placed at string:
    swi 0

_exit:
    mov r7, #1      @ exit syscall
    swi 0

.data
string:
.ascii "Hello World String\n"
