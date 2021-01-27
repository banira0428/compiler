        INITIAL_GP = 0x10008000
        INITIAL_SP = 0x7ffffffc
        stop_service = 99

        .text
init:
        la $gp, INITIAL_GP
        la $sp, INITIAL_SP
        jal main
        nop
        li $v0, stop_service
        syscall
        nop
stop:
        j stop
        nop

        .text 0x00001000
main:
        la $t0, RESULT
        li $v0, 1
        add $a0, $v0, $zero
        li $v0, 2
        add $a1, $v0, $zero
        li $v0, 3
        add $a2, $v0, $zero
        jal _abcde
        jr $ra
        nop

        .data 0x10004000
RESULT:
