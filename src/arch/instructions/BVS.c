#include <arch/instruction.h>
#include <arch/cpu.h>
#include <stdio.h>
#include <arch/bus.h>

void executeBVSInstruction(Addressing_mode mode){
    switch(mode){
        case RELATIVE:{
            if(!(status_register & Overflow)) return;
            int8_t offset = read_from_bus(program_counter + 1);
            cycles += 1 + ((program_counter + offset) / PAGE_SIZE != current_page);
            program_counter += offset;
            break;
        }default:{
            return;
        }
    }
}