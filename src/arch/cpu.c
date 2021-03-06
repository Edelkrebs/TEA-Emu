#include <arch/cpu.h>
#include <arch/bus.h>
#include <arch/instruction.h>

uint32_t cycles;
uint8_t current_page;

uint8_t accumulator;
uint8_t x_register;
uint8_t y_register;
uint8_t status_register;
uint8_t stack_pointer;
uint16_t program_counter;

void process_instruction(){
    bus_gen_cycles = 0;
    for(uint16_t ins = 0; ins < 0x100; ins++){
        if(instruction_set[ins].opcode == read_from_bus(program_counter)){
            bus_gen_cycles = 1;
            cycles++;
            instruction_set[ins].execute_instruction(instruction_set[ins].mode, get_instruction_value(instruction_set[ins].mode));
            program_counter += get_instruction_size(instruction_set[ins].mode);
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
    current_page = program_counter / PAGE_SIZE;
    for(;;){
        system("clear");
        printf("Accumulator: 0x%x\nX: 0x%x\nY: 0x%x\nStatus: 0x%x\nStack Pointer: 0x%x\nProgram Counter: 0x%x\n", accumulator, x_register, y_register, status_register, stack_pointer, program_counter);
        process_instruction();
        current_page = program_counter / PAGE_SIZE;
    }
}