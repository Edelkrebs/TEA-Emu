#include <stdio.h>
#include <arch/instruction.h>
#include <arch/bus.h>
#include <arch/cpu.h>

int main(){
    setup_instructions();
    init_bus();
    bus_gen_cycles = 0;
    write_to_bus(0x0, LDA_IMM);
    write_to_bus(0x1, 0x10);
    write_to_bus(0x2, LDY_IMM);
    write_to_bus(0x3, 0x20);
    write_to_bus(0x4, CPY_IMM);
    write_to_bus(0x5, 0x20);
    bus_gen_cycles = 1;
    start_execution(0x0);
}