#include <stdio.h>
#include <arch/instruction.h>
#include <arch/bus.h>
#include <arch/cpu.h>

int main(){
    setup_instructions();
    init_bus();
    write_to_bus(0x0, 0x0);
    start_execution(0x0);
}