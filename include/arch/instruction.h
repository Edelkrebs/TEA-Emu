#ifndef __INSTRUCTION_H
#define __INSTRUCTION_H

#include <stdint.h>

typedef enum{
    ACCUMULATOR = 1,
    ABSOLUTE = 3,
    ABSOLUTE_X = 3,
    ABSOLUTE_Y = 3,
    IMMEDIATE = 2,
    IMPLIED = 1,
    INDIRECT = 3,
    X_INDEXED = 2,
    Y_INDEXED = 2,
    RELATIVE = 2,
    ZEROPAGE = 2,
    ZEROPAGE_X = 2,
    ZEROPAGE_Y = 2    
} Addressing_mode;

typedef enum{
    BRK_IMPL = 0,
    ORA_IND_X = 1,
    ORA_ZPG = 5,
    ASL_ZPG = 6,
    PHP_IMPL = 8,
    ORA_IMM = 9,
    ASL_A = 0xA,
    ORA_ABS = 0xD,
    ASL_ABS = 0xE,
    BPL_REL = 0x10,
    ORA_IND_Y = 0x11,
    ORA_ZPG_X = 0x15,
    ASL_ZPG_X = 0x16,
    CLC_IMPL = 0x18,
    ORA_ABS_Y = 0x19,
    ORA_ABS_X = 0xD,
    ASL_ABS_X = 0xE,
    JSR_ABS = 0x20,
    AND_IND_X = 0x21, 
    BIT_ZPG = 0x24,
    AND_ZPG = 0x25,
    ROL_ZPG = 0x26,
    PLP_IMPL = 0x28,
    AND_IMM = 0x29,
    ROL_A = 0x2A,
    BIT_ABS = 0x2C,
    AND_ABS = 0x2D,
    ROL_ABS = 0x2E,
    BMI_REL = 0x30,
    AND_IND_Y = 0x31,
    AND_ZPG_X = 0x35,
    ROL_ZPG_X = 0x36,
    SEC_IMPL = 0x38,
    AND_ABS_Y = 0x39,
    AND_ABS_X = 0x3D,
    ROL_ABS_X = 0x3E,
    RTI_IMPL = 0x40,
    EOR_IND_X = 0x41,
    EOR_ZPG = 0x45,
    LSR_ZPG = 0x46,
    PHA_IMPL = 0x48,
    EOR_IMM = 0x49,
    LSR_A = 0x4A,
    JMP_ABS = 0x4C,
    EOR_ABS = 0x4D,
    LSR_ABS = 0x4E,
    BVC_REL = 0x50,
    EOR_IND_Y = 0x51,
    EOR_ZPG_X = 0x55,
    LSR_ZPG_X = 0x56,
    CLI_IMPL = 0x58,
    EOR_ABS_Y = 0x59,
    EOR_ABS_X = 0x5D,
    LSR_ABS_X = 0x5E,
    RTS_IMPL = 0x60,
    ADC_IND_X = 0x61,
    ADC_ZPG = 0x65,
    ROR_ZPG = 0x66,
    PLA_IMPL = 0x68,
    ADC_IMM = 0x69,
    ROR_A = 0x6A,
    JMP_IND = 0x6C,
    ADC_ABS = 0x6D,
    ROR_ABS = 0x6E,
    BVS_REL = 0x70,
    ADC_IND_Y = 0x71,
    ADC_ZPG_X = 0x75,
    ROR_ZPG_X = 0x76,
    SEI_IMPL = 0x78,
    ADC_ABS_Y = 0x79,
    ADC_ABS_X = 0x7D,
    ROR_ABS_X = 0x7E,
    STA_IND_X = 0x81,
    STY_ZPG = 0x84,
    STA_ZPG = 0x85,
    STX_ZPG = 0x86,
    DEY_IMPL = 0x88,
    TXA_IMPL = 0x8A,
    STY_ABS = 0x8C,
    STA_ABS = 0x8D,
    STX_ABS = 0x8E,
    BCC_REL = 0x90,
    STA_IND_Y = 0x91,
    STY_ZPG_X = 0x94,
    STA_ZPG_X = 0x95,
    STX_ZPG_Y = 0x96,
    TYA_IMPL = 0x98,
    STA_ABS_Y = 0x99,
    TXS_IMPL = 0x9A,
    STA_ABS_X = 0x9D,
    LDY_IMM = 0xA0,
    LDA_IND_X = 0xA1,
    LDX_IMM = 0xA2,
    LDY_ZPG = 0xA4,
    LDA_ZPG = 0xA5,
    LDX_ZPG = 0xA6,
    TAY_IMPL = 0xA8,
    LDA_IMM = 0xA9,
    TAX_IMPL = 0xAA,
    LDY_ABS = 0xAC,
    LDA_ABS = 0xAD,
    LDX_ABS = 0xAE,
    BCS_REL = 0xB0,
    LDA_IND_Y = 0xB1,
    LDY_ZPG_X = 0xB4,
    LDA_ZPG_X = 0xB5,
    LDX_ZPG_Y = 0xB6,
    CLV_IMPL = 0xB8,
    LDA_ABS_Y = 0xB9,
    TSX_IMPL = 0xBA,
    LDY_ABS_X = 0xBC,
    LDA_ABS_X = 0xBD,
    LDX_ABS_Y = 0xBE,
    CPY_IMM = 0xC0,
    CMP_IND_X = 0xC1,
    CPY_ZPG = 0xC4,
    CMP_ZPG = 0xC5,
    DEC_ZPG = 0xC6,
    INY_IMPL = 0xC8,
    CMP_IMM = 0xC9,
    DEX_IMPL = 0xCA,
    CPY_ABS = 0xCC,
    CMP_ABS = 0xCD,
    DEC_ABS = 0xCE,
    BNE_REL = 0xD0,
    CMP_IND_Y = 0xD1,
    CMP_ZPG_X = 0xD5,
    DEC_ZPG_X = 0xD6,
    CLD_IMPL = 0xD8,
    CMP_ABS_Y = 0xD9,
    CMP_ABS_X = 0xDD,
    DEC_ABS_X = 0xDE,
    CPX_IMM = 0xE0,
    SBC_IND_X = 0xE1,
    CPX_ZPG = 0xE4,
    SBC_ZPG = 0xE5,
    INC_ZPG = 0xE6,
    INX_IMPL = 0xE8,
    SBC_IMM = 0xE9,
    NOP_IMPL = 0xEA,
    CPX_ABS = 0xEC,
    SBC_ABS = 0xED,
    INC_ABS = 0xEE,
    BEQ_REL = 0xF0,
    SBC_IND_Y = 0xF1,
    SBC_ZPG_X = 0xF5,
    INC_ZPG_X = 0xF6,
    SED_IMPL = 0xF8,
    SBC_ABS_Y = 0xF9,
    SBC_ABS_X = 0xFD,
    INC_ABS_X = 0xFE 
} Opcodes;

typedef struct{
    const char* name;
    void (*execute_instruction)(Addressing_mode);
    Addressing_mode mode;
    uint8_t opcode; 
} Instruction;

extern Instruction instruction_set[];

void setup_instructions();

#endif