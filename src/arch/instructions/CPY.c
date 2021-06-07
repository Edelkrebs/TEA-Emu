#include <arch/instruction.h>
#include <arch/cpu.h>
#include <stdio.h>
#include <arch/bus.h>

void executeCPYInstruction(Addressing_mode mode, uint16_t value){
    uint8_t compare_value;
    switch(mode){
        case IMMEDIATE:{
            compare_value = read_from_bus(program_counter + 1);
            break;
        }default:{
            return;
        }
    }
    status_register &= ~(Carry | Zero | Negative);
    if(y_register >= compare_value){
        status_register |= Carry;
    }
    if(y_register == compare_value){
        status_register |= Zero;
    }
}