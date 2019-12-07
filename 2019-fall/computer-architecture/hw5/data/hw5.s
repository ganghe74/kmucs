.data 0x10008000
.word 5

.text
main:
    lw $8, 0($gp)
    add $9, $8, $0
    beq $8, $9, L 
    lw $10, 4($gp)
L:
    slt $11, $9, $0
