#include <stdio.h>
#include <arch/instruction.h>
#include <arch/bus.h>
#include <arch/cpu.h>

int main(){
    setup_instructions();
    init_bus();
    bus_gen_cycles = 0;
    write_to_bus(0x0, 0xA9);
    write_to_bus(0x1, 0x10);
    write_to_bus(0x2, 0x0);
    bus_gen_cycles = 1;
    start_execution(0x0);
}