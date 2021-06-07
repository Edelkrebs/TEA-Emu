#include <arch/instruction.h>
#include <stddef.h>
#include <arch/cpu.h>
#include <arch/bus.h>

#define REGISTER_INSTRUCTION(w, x, y, z) extern void execute##w##Instruction(Addressing_mode, uint16_t); \
                                      Instruction w##y##instruction = {.name = x, .execute_instruction = &execute##w##Instruction, .opcode = y, .mode = z}; \
                                      instruction_set[y] = w##y##instruction;

Instruction instruction_set[0x100];

uint8_t get_instruction_value(Addressing_mode mode){
    switch(mode){
        case ACCUMULATOR:{
            return 0;
        } case IMPLIED:{
            return 0;
        } case INDIRECT:{
            uint16_t temp = read_from_bus(program_counter + 1) | (read_from_bus(program_counter + 2) << 8);
            return read_from_bus(temp + 1) | (read_from_bus(program_counter + 2) << 8);
        } case RELATIVE:{
            return read_from_bus(program_counter + 1);
        }case IMMEDIATE:{
            return read_from_bus(program_counter + 1);
        } case ZEROPAGE:{
            return read_from_bus(read_from_bus(program_counter + 1));
        } case ZEROPAGE_X:{
            return read_from_bus(read_from_bus(read_from_bus(program_counter + 1) + x_register));
        } case ZEROPAGE_Y:{
            return read_from_bus(read_from_bus(read_from_bus(program_counter + 1) + y_register));
        } case ABSOLUTE:{
            return read_from_bus(((uint16_t)read_from_bus(program_counter + 2) << 8) | read_from_bus(program_counter + 1));
        } case ABSOLUTE_X:{
            return read_from_bus((((uint16_t)read_from_bus(program_counter + 2) << 8) | read_from_bus(program_counter + 1)) + x_register);
        } case ABSOLUTE_Y:{
            return read_from_bus((((uint16_t)read_from_bus(program_counter + 2) << 8) | read_from_bus(program_counter + 1)) + y_register);
        } case X_INDEXED:{
            return read_from_bus(((uint16_t)read_from_bus(program_counter + 2 + x_register) << 8) | read_from_bus(program_counter + 1 + x_register));
        } case Y_INDEXED:{
            return read_from_bus((((uint16_t)read_from_bus(program_counter + 2) << 8) | read_from_bus(program_counter + 1)) + y_register);
        }
    }
    return 0;
}

uint8_t get_instruction_size(Addressing_mode mode){
    switch(mode){
        case ACCUMULATOR: return 1;
        case ABSOLUTE: return 3;
        case ABSOLUTE_X: return 3;
        case ABSOLUTE_Y: return 3;
        case IMMEDIATE: return 2;
        case IMPLIED: return 1; 
        case INDIRECT: return 3;
        case X_INDEXED: return 2;
        case Y_INDEXED: return 2;
        case RELATIVE: return 2;
        case ZEROPAGE: return 2;
        case ZEROPAGE_X: return 2;
        case ZEROPAGE_Y: return 2;
    }
    return 0;
}

void setup_instructions(){
    for(uint16_t i = 0; i < 0x100; i++){
        REGISTER_INSTRUCTION(BRK, "BRK", i, IMPLIED);
    }

    REGISTER_INSTRUCTION(ADC, "ADC", ADC_IMM, IMMEDIATE);
    REGISTER_INSTRUCTION(ADC, "ADC", ADC_ZPG, ZEROPAGE);
    REGISTER_INSTRUCTION(ADC, "ADC", ADC_ZPG_X, ZEROPAGE_X);
    REGISTER_INSTRUCTION(ADC, "ADC", ADC_ABS, ABSOLUTE);
    REGISTER_INSTRUCTION(ADC, "ADC", ADC_ABS_X, ABSOLUTE_X);
    REGISTER_INSTRUCTION(ADC, "ADC", ADC_ABS_Y, ABSOLUTE_Y);
    REGISTER_INSTRUCTION(ADC, "ADC", ADC_IND_X, X_INDEXED);
    REGISTER_INSTRUCTION(ADC, "ADC", ADC_IND_Y, Y_INDEXED);

    REGISTER_INSTRUCTION(AND, "AND", AND_IMM, IMMEDIATE);
    REGISTER_INSTRUCTION(AND, "AND", AND_ZPG, ZEROPAGE);
    REGISTER_INSTRUCTION(AND, "AND", AND_ZPG_X, ZEROPAGE_X);
    REGISTER_INSTRUCTION(AND, "AND", AND_ABS, ABSOLUTE);
    REGISTER_INSTRUCTION(AND, "AND", AND_ABS_X, ABSOLUTE_X);
    REGISTER_INSTRUCTION(AND, "AND", AND_ABS_Y, ABSOLUTE_Y);
    REGISTER_INSTRUCTION(AND, "AND", AND_IND_X, X_INDEXED);
    REGISTER_INSTRUCTION(AND, "AND", AND_IND_Y, Y_INDEXED);

    REGISTER_INSTRUCTION(ASL, "ASL", ASL_A, ACCUMULATOR);
    REGISTER_INSTRUCTION(ASL, "ASL", ASL_ZPG, ZEROPAGE);
    REGISTER_INSTRUCTION(ASL, "ASL", ASL_ZPG_X, ZEROPAGE_X);
    REGISTER_INSTRUCTION(ASL, "ASL", ASL_ABS, ABSOLUTE);
    REGISTER_INSTRUCTION(ASL, "ASL", ASL_ABS_X, ABSOLUTE_X);

    REGISTER_INSTRUCTION(BCC, "BCC", BCC_REL, RELATIVE);
    
    REGISTER_INSTRUCTION(BCS, "BCS", BCS_REL, RELATIVE);
    
    REGISTER_INSTRUCTION(BEQ, "BEQ", BEQ_REL, RELATIVE);

    REGISTER_INSTRUCTION(BIT, "BIT", BIT_ZPG, ZEROPAGE);
    REGISTER_INSTRUCTION(BIT, "BIT", BIT_ABS, ABSOLUTE);

    REGISTER_INSTRUCTION(BMI, "BMI", BMI_REL, RELATIVE);
    
    REGISTER_INSTRUCTION(BNE, "BNE", BNE_REL, RELATIVE);

    REGISTER_INSTRUCTION(BPL, "BPL", BPL_REL, RELATIVE);

    REGISTER_INSTRUCTION(BRK, "BRK", BRK_IMPL, IMPLIED);
 
    REGISTER_INSTRUCTION(BVC, "BVC", BVC_REL, RELATIVE);
 
    REGISTER_INSTRUCTION(BVS, "BVS", BVS_REL, RELATIVE);
 
    REGISTER_INSTRUCTION(CLC, "CLC", CLC_IMPL, IMPLIED);

    REGISTER_INSTRUCTION(CLD, "CLD", CLD_IMPL, IMPLIED);

    REGISTER_INSTRUCTION(CLI, "CLI", CLI_IMPL, IMPLIED);

    REGISTER_INSTRUCTION(CLV, "CLV", CLV_IMPL, IMPLIED);

    REGISTER_INSTRUCTION(CMP, "CMP", CMP_IMM, IMMEDIATE);
    REGISTER_INSTRUCTION(CMP, "CMP", CMP_ZPG, ZEROPAGE);
    REGISTER_INSTRUCTION(CMP, "CMP", CMP_ZPG_X, ZEROPAGE_X);
    REGISTER_INSTRUCTION(CMP, "CMP", CMP_ABS, ABSOLUTE);
    REGISTER_INSTRUCTION(CMP, "CMP", CMP_ABS_X, ABSOLUTE_X);
    REGISTER_INSTRUCTION(CMP, "CMP", CMP_ABS_Y, ABSOLUTE_Y);
    REGISTER_INSTRUCTION(CMP, "CMP", CMP_IND_X, X_INDEXED);
    REGISTER_INSTRUCTION(CMP, "CMP", CMP_IND_Y, Y_INDEXED);

    REGISTER_INSTRUCTION(CPX, "CPX", CPX_IMM, IMMEDIATE);
    REGISTER_INSTRUCTION(CPX, "CPX", CPX_ZPG, ZEROPAGE);
    REGISTER_INSTRUCTION(CPX, "CPX", CPX_ABS, ABSOLUTE);

    REGISTER_INSTRUCTION(CPY, "CPY", CPY_IMM, IMMEDIATE);
    REGISTER_INSTRUCTION(CPY, "CPY", CPY_ZPG, ZEROPAGE);
    REGISTER_INSTRUCTION(CPY, "CPY", CPY_ABS, ABSOLUTE);

    REGISTER_INSTRUCTION(DEC, "DEC", DEC_ZPG, ZEROPAGE);
    REGISTER_INSTRUCTION(DEC, "DEC", DEC_ZPG_X, ZEROPAGE_X);
    REGISTER_INSTRUCTION(DEC, "DEC", DEC_ABS, ABSOLUTE);
    REGISTER_INSTRUCTION(DEC, "DEC", DEC_ABS_X, ABSOLUTE_X);

    REGISTER_INSTRUCTION(DEX, "DEX", DEX_IMPL, IMPLIED);

    REGISTER_INSTRUCTION(DEY, "DEY", DEY_IMPL, IMPLIED);

    REGISTER_INSTRUCTION(EOR, "EOR", EOR_IMM, IMMEDIATE);
    REGISTER_INSTRUCTION(EOR, "EOR", EOR_ZPG, ZEROPAGE);
    REGISTER_INSTRUCTION(EOR, "EOR", EOR_ZPG_X, ZEROPAGE_X);
    REGISTER_INSTRUCTION(EOR, "EOR", EOR_ABS, ABSOLUTE);
    REGISTER_INSTRUCTION(EOR, "EOR", EOR_ABS_X, ABSOLUTE_X);
    REGISTER_INSTRUCTION(EOR, "EOR", EOR_ABS_Y, ABSOLUTE_Y);
    REGISTER_INSTRUCTION(EOR, "EOR", EOR_IND_X, X_INDEXED);
    REGISTER_INSTRUCTION(EOR, "EOR", EOR_IND_Y, Y_INDEXED);

    REGISTER_INSTRUCTION(INC, "INC", INC_ZPG, ZEROPAGE);
    REGISTER_INSTRUCTION(INC, "INC", INC_ZPG_X, ZEROPAGE_X);
    REGISTER_INSTRUCTION(INC, "INC", INC_ABS, ABSOLUTE);
    REGISTER_INSTRUCTION(INC, "INC", INC_ABS_X, ABSOLUTE_X);

    REGISTER_INSTRUCTION(INX, "INX", INX_IMPL, IMPLIED);

    REGISTER_INSTRUCTION(INY, "INY", INY_IMPL, IMPLIED);

    REGISTER_INSTRUCTION(JMP, "JMP", JMP_ABS, ABSOLUTE);
    REGISTER_INSTRUCTION(JMP, "JMP", JMP_IND, INDIRECT);

    REGISTER_INSTRUCTION(JSR, "JSR", JSR_ABS, ABSOLUTE);

    REGISTER_INSTRUCTION(RTI, "RTI", RTI_IMPL, IMPLIED);
    REGISTER_INSTRUCTION(RTS, "RTS", RTS_IMPL, IMPLIED);
    REGISTER_INSTRUCTION(LDY, "LDY", LDY_IMM, IMMEDIATE);

    REGISTER_INSTRUCTION(ORA, "ORA", ORA_IND_X, X_INDEXED);
    REGISTER_INSTRUCTION(ORA, "ORA", ORA_IND_Y, Y_INDEXED);
    REGISTER_INSTRUCTION(STA, "STA", STA_IND_X, X_INDEXED);
    REGISTER_INSTRUCTION(STA, "STA", STA_IND_Y, Y_INDEXED);
    REGISTER_INSTRUCTION(LDA, "LDA", LDA_IND_X, X_INDEXED);
    REGISTER_INSTRUCTION(LDA, "LDA", LDA_IND_Y, Y_INDEXED);

    REGISTER_INSTRUCTION(SBC, "SBC", SBC_IND_X, X_INDEXED);
    REGISTER_INSTRUCTION(SBC, "SBC", SBC_IND_Y, Y_INDEXED);
    
    REGISTER_INSTRUCTION(LDX, "LDX", LDX_IMM, IMMEDIATE);
    
    REGISTER_INSTRUCTION(LDA, "LDA", LDA_IMM, IMMEDIATE);

}