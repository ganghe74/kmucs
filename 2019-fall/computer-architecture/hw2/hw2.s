.text
.globl main
main:
    lui $t0, 0x8000
    addi $t1, $0, 1
    subu $t2, $t0, $t1