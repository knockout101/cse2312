.global _start

.text

_start:
    mov r7, #4      @ syscall number
    mov r0, #1      @ Stdout is monitor
    mov r2, #19     @ string is 19 chars long
    ldr r1, =string @ string located at string:
    swi 0

_exit:

    mov r7, #1      @ exit syscall 
    swi 0 

.data
string:
.ascii "Hello World String\n"