#include <arch/cpu.h>
#include <arch/bus.h>
#include <arch/instruction.h>

uint8_t accumulator;
uint8_t x_register;
uint8_t y_register;
uint8_t status_register;
uint8_t stack_pointer;
uint16_t program_counter;

void process_instruction(){
    for(uint16_t ins = 0; ins < 0x100; ins++){
        if(instruction_set[ins].opcode == read_from_bus(program_counter)){
            instruction_set[ins].execute_instruction(instruction_set[ins].mode);
        }
    }
}

void start_execution(uint16_t addr){
    accumulator = 0;
    x_register = 0;
    y_register = 0;
    status_register = 0;
    stack_pointer = 0xFF;
    program_counter = addr;
    for(;;){
        process_instruction();
    }
}