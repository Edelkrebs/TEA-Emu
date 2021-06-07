#include <arch/instruction.h>
#include <arch/cpu.h>
#include <stdio.h>
#include <arch/bus.h>

void executeASLInstruction(Addressing_mode mode, uint16_t value){
    switch(mode){
        case ACCUMULATOR: accumulator <<= 1;break;
        case ZEROPAGE: write_to_bus(read_from_bus(program_counter + 1), read_from_bus(program_counter + 1) << 1) ; break;
        case ZEROPAGE_X: write_to_bus(read_from_bus(program_counter + 1) + x_register, read_from_bus(program_counter + 1) << 1); break;
        case ABSOLUTE: write_to_bus((read_from_bus(program_counter + 1) << 8) | read_from_bus(read_from_bus(program_counter + 1)), ((read_from_bus(program_counter + 1) << 8) | read_from_bus(program_counter + 1)) << 1); break;
        case ABSOLUTE_X: write_to_bus((read_from_bus(program_counter + 1) << 8) | (read_from_bus(read_from_bus(program_counter + 1)) + x_register), ((read_from_bus(program_counter + 1) << 8) | read_from_bus(program_counter + 1)) << 1); break;
        default: return;
    }
}