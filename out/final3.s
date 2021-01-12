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
        li $v0, 0
        sw $v0, 0($t0)
        li $v0, 0
        sw $v0, 4($t0)
        li $v0, 0
        sw $v0, 8($t0)
        li $v0, 0
        sw $v0, 12($t0)
        li $v0, 1
        sw $v0, 16($t0)
$LOOP0:
        lw $t1, 16($t0)
        nop
        li $t3, 31
        slt $t2, $t1, $t3
        beq $t2, $zero, $EXIT0
        nop
        lw $t1, 16($t0)
        nop
        li $t3, 15
        div $t1, $t3
        mflo $v0
        add $t1, $v0, $zero
        li $t3, 15
        mult $t1, $t3
        mflo $v0
        add $t1, $v0, $zero
        lw $t3, 16($t0)
        nop
        bne $t1, $t3, $L0
        lw $t1, 8($t0)
        nop
        li $t3, 1
        add $v0, $t1, $t3
        sw $v0, 8($t0)
        j $END0
$L0:
        lw $t1, 16($t0)
        nop
        li $t3, 3
        div $t1, $t3
        mflo $v0
        add $t1, $v0, $zero
        li $t3, 3
        mult $t1, $t3
        mflo $v0
        add $t1, $v0, $zero
        lw $t3, 16($t0)
        nop
        bne $t1, $t3, $L1
        lw $t1, 0($t0)
        nop
        li $t3, 1
        add $v0, $t1, $t3
        sw $v0, 0($t0)
        j $END0
$L1:
        lw $t1, 16($t0)
        nop
        li $t3, 5
        div $t1, $t3
        mflo $v0
        add $t1, $v0, $zero
        li $t3, 5
        mult $t1, $t3
        mflo $v0
        add $t1, $v0, $zero
        lw $t3, 16($t0)
        nop
        bne $t1, $t3, $L2
        lw $t1, 4($t0)
        nop
        li $t3, 1
        add $v0, $t1, $t3
        sw $v0, 4($t0)
        j $END0
$L2:
        lw $t1, 12($t0)
        nop
        li $t3, 1
        add $v0, $t1, $t3
        sw $v0, 12($t0)
$END0:
        lw $t1, 16($t0)
        nop
        li $t3, 1
        add $v0, $t1, $t3
        sw $v0, 16($t0)
        j $LOOP0
        nop
$EXIT0:
        jr $ra
        nop

        .data 0x10004000
RESULT:
