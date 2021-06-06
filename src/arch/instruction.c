#include <arch/instruction.h>
#include <stddef.h>

#define REGISTER_INSTRUCTION(w, x, y, z) extern void execute##w##Instruction(Addressing_mode); \
                                      Instruction w##instruction = {.name = x, .execute_instruction = &execute##w##Instruction, .opcode = y, .mode = z}; \
                                      instruction_set[y] = w##instruction;

Instruction instruction_set[0x100];

void setup_instructions(){
    for(uint16_t i = 0; i < 0x100; i++){
        REGISTER_INSTRUCTION(BRK, "BRK", i, IMPLIED);
    }

    REGISTER_INSTRUCTION(BRK, "BRK", 0x0, IMPLIED);
    REGISTER_INSTRUCTION(BPL, "BPL", 0x1, RELATIVE);
    REGISTER_INSTRUCTION(JSR, "JSR", 0x2, ABSOLUTE);
    REGISTER_INSTRUCTION(BMI, "BMI", 0x3, RELATIVE);
    REGISTER_INSTRUCTION(RTI, "RTI", 0x4, IMPLIED);
    REGISTER_INSTRUCTION(BVC, "BVC", 0x5, RELATIVE);
    REGISTER_INSTRUCTION(RTS, "RTS", 0x6, IMPLIED);
    REGISTER_INSTRUCTION(BVS, "BVS", 0x7, RELATIVE);
    REGISTER_INSTRUCTION(BCC, "BCC", 0x9, RELATIVE);
    REGISTER_INSTRUCTION(LDY, "LDY", 0xA, IMMEDIATE);
    REGISTER_INSTRUCTION(BCS, "BCS", 0xB, RELATIVE);
    REGISTER_INSTRUCTION(CPY, "CPY", 0xC, IMMEDIATE);
    REGISTER_INSTRUCTION(BNE, "BNE", 0xD, RELATIVE);
    REGISTER_INSTRUCTION(CPX, "CPX", 0xE, IMMEDIATE);
    REGISTER_INSTRUCTION(BEQ, "BEQ", 0xF, RELATIVE);
    REGISTER_INSTRUCTION(LDA, "LDA", 0xA9, IMMEDIATE);

}