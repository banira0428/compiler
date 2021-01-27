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
        li $t1, 1
        sw $t1, 12($t0)
        li $t1, 2
        sw $t1, 20($t0)
        li $t3, 3
        sw $t3, 24($t0)
        lw $t1, 20($t0)
        lw $t3, 24($t0)
        nop
        mult $t1, $t3
        mflo $v0
        sw $v0, 16($t0)
        nop
        lw $t1, 12($t0)
        lw $t3, 16($t0)
        nop
        add $v0, $t1, $t3
        sw $v0, 8($t0)
        nop
        sw $v0, 0($t0)
        jr $ra
        nop

        .data 0x10004000
RESULT:
