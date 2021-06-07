#include <arch/instruction.h>
#include <arch/cpu.h>
#include <stdio.h>
#include <arch/bus.h>

void executeBITInstruction(Addressing_mode mode, uint16_t value){
    switch(mode){
        case ZEROPAGE:{
            x_register = read_from_bus(program_counter + 1);
            return;
        }default:{
            return;
        }
    }
}