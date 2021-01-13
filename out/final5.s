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
        addi $t1, $zero, 0
        add $t4, $t1, $zero
        addi $t1, $zero, 0
        add $t1, $t1, $t4
        addi $t1, $t1, 0
        add $t1, $t1, $t0
        sw $v0, 0($t1)
        li $v0, 2
        addi $t1, $zero, 0
        add $t4, $t1, $zero
        addi $t1, $zero, 4
        add $t1, $t1, $t4
        addi $t1, $t1, 0
        add $t1, $t1, $t0
        sw $v0, 0($t1)
        li $v0, 3
        addi $t1, $zero, 8
        add $t4, $t1, $zero
        addi $t1, $zero, 0
        add $t1, $t1, $t4
        addi $t1, $t1, 0
        add $t1, $t1, $t0
        sw $v0, 0($t1)
        li $v0, 4
        addi $t1, $zero, 8
        add $t4, $t1, $zero
        addi $t1, $zero, 4
        add $t1, $t1, $t4
        addi $t1, $t1, 0
        add $t1, $t1, $t0
        sw $v0, 0($t1)
        li $v0, 5
        addi $t1, $zero, 0
        add $t4, $t1, $zero
        addi $t1, $zero, 0
        add $t1, $t1, $t4
        addi $t1, $t1, 16
        add $t1, $t1, $t0
        sw $v0, 0($t1)
        li $v0, 6
        addi $t1, $zero, 0
        add $t4, $t1, $zero
        addi $t1, $zero, 4
        add $t1, $t1, $t4
        addi $t1, $t1, 16
        add $t1, $t1, $t0
        sw $v0, 0($t1)
        li $v0, 7
        addi $t1, $zero, 8
        add $t4, $t1, $zero
        addi $t1, $zero, 0
        add $t1, $t1, $t4
        addi $t1, $t1, 16
        add $t1, $t1, $t0
        sw $v0, 0($t1)
        li $v0, 8
        addi $t1, $zero, 8
        add $t4, $t1, $zero
        addi $t1, $zero, 4
        add $t1, $t1, $t4
        addi $t1, $t1, 16
        add $t1, $t1, $t0
        sw $v0, 0($t1)
        li $v0, 0
        sw $v0, 48($t0)
$LOOP0:
        lw $v0, 48($t0)
        nop
        add $t4, $v0, $zero
        li $v0, 2
        add $t1, $t4, $zero
        add $t3, $v0, $zero
        slt $t2, $t1, $t3
        beq $t2, $zero, $EXIT0
        nop
        li $v0, 0
        sw $v0, 52($t0)
$LOOP1:
        lw $v0, 52($t0)
        nop
        add $t4, $v0, $zero
        li $v0, 2
        add $t1, $t4, $zero
        add $t3, $v0, $zero
        slt $t2, $t1, $t3
        beq $t2, $zero, $EXIT1
        nop
        li $v0, 0
        lw $t1, 48($t0)
        nop
        li $t3, 8
        mult $t1, $t3
        mflo $t1
        add $t4, $t1, $zero
        lw $t1, 52($t0)
        nop
        li $t3, 4
        mult $t1, $t3
        mflo $t1
        add $t1, $t1, $t4
        addi $t1, $t1, 32
        add $t1, $t1, $t0
        sw $v0, 0($t1)
        lw $v0, 52($t0)
        nop
        addi $v0, $v0, 1
        sw $v0, 52($t0)
        j $LOOP1
        nop
$EXIT1:
        lw $v0, 48($t0)
        nop
        addi $v0, $v0, 1
        sw $v0, 48($t0)
        j $LOOP0
        nop
$EXIT0:
        li $v0, 0
        sw $v0, 48($t0)
$LOOP2:
        lw $v0, 48($t0)
        nop
        add $t4, $v0, $zero
        li $v0, 2
        add $t1, $t4, $zero
        add $t3, $v0, $zero
        slt $t2, $t1, $t3
        beq $t2, $zero, $EXIT2
        nop
        li $v0, 0
        sw $v0, 52($t0)
$LOOP3:
        lw $v0, 52($t0)
        nop
        add $t4, $v0, $zero
        li $v0, 2
        add $t1, $t4, $zero
        add $t3, $v0, $zero
        slt $t2, $t1, $t3
        beq $t2, $zero, $EXIT3
        nop
        li $v0, 0
        sw $v0, 56($t0)
$LOOP4:
        lw $v0, 56($t0)
        nop
        add $t4, $v0, $zero
        li $v0, 2
        add $t1, $t4, $zero
        add $t3, $v0, $zero
        slt $t2, $t1, $t3
        beq $t2, $zero, $EXIT4
        nop
        lw $t1, 48($t0)
        nop
        li $t3, 8
        mult $t1, $t3
        mflo $t1
        add $t4, $t1, $zero
        lw $t1, 52($t0)
        nop
        li $t3, 4
        mult $t1, $t3
        mflo $t1
        add $t1, $t1, $t4
        addi $t1, $t1, 32
        add $t1, $t1, $t0
        lw $t1, 0($t1)
        nop
        sw $t1, 68($t0)
        lw $t1, 48($t0)
        nop
        li $t3, 8
        mult $t1, $t3
        mflo $t1
        add $t4, $t1, $zero
        lw $t1, 56($t0)
        nop
        li $t3, 4
        mult $t1, $t3
        mflo $t1
        add $t1, $t1, $t4
        addi $t1, $t1, 0
        add $t1, $t1, $t0
        lw $t1, 0($t1)
        nop
        sw $t1, 76($t0)
        lw $t1, 56($t0)
        nop
        li $t3, 8
        mult $t1, $t3
        mflo $t1
        add $t4, $t1, $zero
        lw $t1, 52($t0)
        nop
        li $t3, 4
        mult $t1, $t3
        mflo $t1
        add $t1, $t1, $t4
        addi $t1, $t1, 16
        add $t1, $t1, $t0
        lw $t3, 0($t1)
        nop
        sw $t3, 80($t0)
        lw $t1, 76($t0)
        nop
        lw $t3, 80($t0)
        nop
        mult $t1, $t3
        mflo $v0
        sw $v0, 72($t0)
        nop
        lw $t1, 68($t0)
        nop
        lw $t3, 72($t0)
        nop
        add $v0, $t1, $t3
        sw $v0, 64($t0)
        nop
        lw $t1, 48($t0)
        nop
        li $t3, 8
        mult $t1, $t3
        mflo $t1
        add $t4, $t1, $zero
        lw $t1, 52($t0)
        nop
        li $t3, 4
        mult $t1, $t3
        mflo $t1
        add $t1, $t1, $t4
        addi $t1, $t1, 32
        add $t1, $t1, $t0
        sw $v0, 0($t1)
        lw $v0, 56($t0)
        nop
        addi $v0, $v0, 1
        sw $v0, 56($t0)
        j $LOOP4
        nop
$EXIT4:
        lw $v0, 52($t0)
        nop
        addi $v0, $v0, 1
        sw $v0, 52($t0)
        j $LOOP3
        nop
$EXIT3:
        lw $v0, 48($t0)
        nop
        addi $v0, $v0, 1
        sw $v0, 48($t0)
        j $LOOP2
        nop
$EXIT2:
        jr $ra
        nop

        .data 0x10004000
RESULT:
