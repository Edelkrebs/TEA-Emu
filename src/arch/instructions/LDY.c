#include <arch/instruction.h>
#include <arch/cpu.h>
#include <stdio.h>
#include <arch/bus.h>

void executeLDYInstruction(Addressing_mode mode){
    switch(mode){
        case IMMEDIATE:{
            y_register = read_from_bus(program_counter + 1);
            return;
        }default:{
            return;
        }
    }
}