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
        addi $sp, $sp, -44
        sw   $ra, 0($sp)
        li $v0, 10
        addi $t1, $zero, 0
        addi $t1, $t1, 4
        add $t1, $t1, $sp
        sw $v0, 0($t1)
        li $v0, 4
        addi $t1, $zero, 4
        addi $t1, $t1, 4
        add $t1, $t1, $sp
        sw $v0, 0($t1)
        li $v0, 2
        addi $t1, $zero, 8
        addi $t1, $t1, 4
        add $t1, $t1, $sp
        sw $v0, 0($t1)
        li $v0, 7
        addi $t1, $zero, 12
        addi $t1, $t1, 4
        add $t1, $t1, $sp
        sw $v0, 0($t1)
        li $v0, 3
        addi $t1, $zero, 16
        addi $t1, $t1, 4
        add $t1, $t1, $sp
        sw $v0, 0($t1)
        li $v0, 5
        addi $t1, $zero, 20
        addi $t1, $t1, 4
        add $t1, $t1, $sp
        sw $v0, 0($t1)
        li $v0, 9
        addi $t1, $zero, 24
        addi $t1, $t1, 4
        add $t1, $t1, $sp
        sw $v0, 0($t1)
        li $v0, 10
        addi $t1, $zero, 28
        addi $t1, $t1, 4
        add $t1, $t1, $sp
        sw $v0, 0($t1)
        li $v0, 1
        addi $t1, $zero, 32
        addi $t1, $t1, 4
        add $t1, $t1, $sp
        sw $v0, 0($t1)
        li $v0, 8
        addi $t1, $zero, 36
        addi $t1, $t1, 4
        add $t1, $t1, $sp
        sw $v0, 0($t1)
        addi $t1, $sp, 4
        add $v0, $t1, $zero
        add $a0, $v0, $zero
        li $v0, 0
        add $a1, $v0, $zero
        li $v0, 9
        add $a2, $v0, $zero
        jal _quicksort
        nop
        lw   $ra, 0($sp)
        addi $sp, $sp, 44
        jr   $ra
_quicksort:
        addi $sp, $sp, -32
        sw   $ra, 0($sp)
        sw   $a0, 4($sp)
        sw   $a1, 8($sp)
        sw   $a2, 12($sp)
        lw $v0, 12($sp)
        nop
        add $t4, $v0, $zero
        lw $v0, 8($sp)
        nop
        add $t1, $t4, $zero
        add $t3, $v0, $zero
        slt $t2, $t3, $t1
        beq $t2, $zero, $L0
        nop
        lw $t1, 12($sp)
        nop
        li $t3, 4
        mult $t1, $t3
        mflo $t1
        lw $t3, 4($sp)
        nop
        add $t3, $t1, $t3
        lw $v0, 0($t3)
        nop
        sw $v0, 16($sp)
        lw $v0, 8($sp)
        nop
        sw $v0, 20($sp)
        lw $t1, 12($sp)
        nop
        sw $t1, 52($t0)
        li $t3, 1
        sw $t3, 56($t0)
        lw $t1, 52($t0)
        lw $t3, 56($t0)
        nop
        sub $v0, $t1, $t3
        sw $v0, 48($t0)
        nop
        sw $v0, 24($sp)
$LOOP0:
$LOOP1:
        lw $t1, 20($sp)
        nop
        li $t3, 4
        mult $t1, $t3
        mflo $t1
        lw $t3, 4($sp)
        nop
        add $t3, $t1, $t3
        lw $v0, 0($t3)
        nop
        add $t4, $v0, $zero
        lw $v0, 16($sp)
        nop
        add $t1, $t4, $zero
        add $t3, $v0, $zero
        slt $t2, $t1, $t3
        beq $t2, $zero, $EXIT1
        nop
        lw $t1, 20($sp)
        nop
        sw $t1, 52($t0)
        li $t3, 1
        sw $t3, 56($t0)
        lw $t1, 52($t0)
        lw $t3, 56($t0)
        nop
        add $v0, $t1, $t3
        sw $v0, 48($t0)
        nop
        sw $v0, 20($sp)
        j $LOOP1
        nop
$EXIT1:
$LOOP2:
        lw $t1, 24($sp)
        nop
        li $t3, 4
        mult $t1, $t3
        mflo $t1
        lw $t3, 4($sp)
        nop
        add $t3, $t1, $t3
        lw $v0, 0($t3)
        nop
        add $t4, $v0, $zero
        lw $v0, 16($sp)
        nop
        add $t1, $t4, $zero
        add $t3, $v0, $zero
        slt $t2, $t3, $t1
        beq $t2, $zero, $EXIT2
        nop
        lw $t1, 24($sp)
        nop
        sw $t1, 52($t0)
        li $t3, 1
        sw $t3, 56($t0)
        lw $t1, 52($t0)
        lw $t3, 56($t0)
        nop
        sub $v0, $t1, $t3
        sw $v0, 48($t0)
        nop
        sw $v0, 24($sp)
        j $LOOP2
        nop
$EXIT2:
        lw $v0, 20($sp)
        nop
        add $t4, $v0, $zero
        lw $v0, 24($sp)
        nop
        add $t1, $t4, $zero
        add $t3, $v0, $zero
        addi $t1, $t1, 1
        slt $t2, $t3, $t1
        beq $t2, $zero, $L1
        nop
        j  $EXIT0
        nop
        j $END0
$L1:
$END0:
        lw $t1, 20($sp)
        nop
        li $t3, 4
        mult $t1, $t3
        mflo $t1
        lw $t3, 4($sp)
        nop
        add $t3, $t1, $t3
        lw $v0, 0($t3)
        nop
        sw $v0, 28($sp)
        lw $t1, 24($sp)
        nop
        li $t3, 4
        mult $t1, $t3
        mflo $t1
        lw $t3, 4($sp)
        nop
        add $t3, $t1, $t3
        lw $v0, 0($t3)
        nop
## 参照渡しの配列に代入
        lw $t1, 20($sp)
        nop
        li $t3, 4
        mult $t1, $t3
        mflo $t1
        lw $t3, 4($sp)
        nop
        add $t3, $t1, $t3
        sw $v0, 0($t3)
## 参照渡しの配列に代入終わり
        lw $v0, 28($sp)
        nop
## 参照渡しの配列に代入
        lw $t1, 24($sp)
        nop
        li $t3, 4
        mult $t1, $t3
        mflo $t1
        lw $t3, 4($sp)
        nop
        add $t3, $t1, $t3
        sw $v0, 0($t3)
## 参照渡しの配列に代入終わり
        j $LOOP0
        nop
$EXIT0:
        lw $t1, 20($sp)
        nop
        li $t3, 4
        mult $t1, $t3
        mflo $t1
        lw $t3, 4($sp)
        nop
        add $t3, $t1, $t3
        lw $v0, 0($t3)
        nop
        sw $v0, 28($sp)
        lw $t1, 12($sp)
        nop
        li $t3, 4
        mult $t1, $t3
        mflo $t1
        lw $t3, 4($sp)
        nop
        add $t3, $t1, $t3
        lw $v0, 0($t3)
        nop
## 参照渡しの配列に代入
        lw $t1, 20($sp)
        nop
        li $t3, 4
        mult $t1, $t3
        mflo $t1
        lw $t3, 4($sp)
        nop
        add $t3, $t1, $t3
        sw $v0, 0($t3)
## 参照渡しの配列に代入終わり
        lw $v0, 28($sp)
        nop
## 参照渡しの配列に代入
        lw $t1, 12($sp)
        nop
        li $t3, 4
        mult $t1, $t3
        mflo $t1
        lw $t3, 4($sp)
        nop
        add $t3, $t1, $t3
        sw $v0, 0($t3)
## 参照渡しの配列に代入終わり
        lw $v0, 4($sp)
        nop
        add $a0, $v0, $zero
        lw $v0, 8($sp)
        nop
        add $a1, $v0, $zero
        lw $t1, 20($sp)
        nop
        sw $t1, 52($t0)
        li $t3, 1
        sw $t3, 56($t0)
        lw $t1, 52($t0)
        lw $t3, 56($t0)
        nop
        sub $v0, $t1, $t3
        sw $v0, 48($t0)
        nop
        add $a2, $v0, $zero
        jal _quicksort
        nop
        lw $v0, 4($sp)
        nop
        add $a0, $v0, $zero
        lw $t1, 20($sp)
        nop
        sw $t1, 52($t0)
        li $t3, 1
        sw $t3, 56($t0)
        lw $t1, 52($t0)
        lw $t3, 56($t0)
        nop
        add $v0, $t1, $t3
        sw $v0, 48($t0)
        nop
        add $a1, $v0, $zero
        lw $v0, 12($sp)
        nop
        add $a2, $v0, $zero
        jal _quicksort
        nop
        j $END1
$L0:
$END1:
        lw   $ra, 0($sp)
        addi $sp, $sp, 32
        jr   $ra
        jr $ra
        nop

        .data 0x10004000
RESULT:
