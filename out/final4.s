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
        li $v0, 1000
        sw $v0, 0($t0)
        li $v0, 1
        sw $v0, 4($t0)
$LOOP0:
        lw $t1, 4($t0)
        nop
        lw $t3, 0($t0)
        nop
        slt $t2, $t1, $t3
        beq $t2, $zero, $EXIT0
        bne $t1, $t3, $EXIT0
        nop
        li $v0, 1
        sw $v0, 0($t0)
        lw $t1, 4($t0)
        nop
        li $t3, 1
        add $v0, $t1, $t3
        sw $v0, 4($t0)
        j $LOOP0
        nop
$EXIT0:
        li $v0, 2
        sw $v0, 4($t0)
$LOOP1:
        lw $t1, 4($t0)
        nop
        lw $t1, 0($t0)
        nop
        li $t3, 2
        div $t1, $t3
        mflo $v0
        add $t3, $v0, $zero
        slt $t2, $t1, $t3
        beq $t2, $zero, $EXIT1
        bne $t1, $t3, $EXIT1
        nop
        li $v0, 2
        sw $v0, 8($t0)
$LOOP2:
        lw $t1, 8($t0)
        nop
        lw $t1, 0($t0)
        nop
        lw $t3, 4($t0)
        nop
        div $t1, $t3
        mflo $v0
        add $t3, $v0, $zero
        slt $t2, $t1, $t3
        beq $t2, $zero, $EXIT2
        bne $t1, $t3, $EXIT2
        nop
        lw $t1, 4($t0)
        nop
        lw $t3, 8($t0)
        nop
        mult $t1, $t3
        mflo $v0
        sw $v0, 12($t0)
        li $v0, 0
        sw $v0, 0($t0)
        lw $t1, 8($t0)
        nop
        li $t3, 1
        add $v0, $t1, $t3
        sw $v0, 8($t0)
        j $LOOP2
        nop
$EXIT2:
        lw $t1, 4($t0)
        nop
        li $t3, 1
        add $v0, $t1, $t3
        sw $v0, 4($t0)
        j $LOOP1
        nop
$EXIT1:
        jr $ra
        nop

        .data 0x10004000
RESULT:
