#include <stdio.h>
#include <arch/instruction.h>
#include <arch/bus.h>

int main(){
    setup_instructions();
    init_bus();
    write_to_bus(0x0, 0x19);
    printf("%d\n", read_from_bus(0x0));
    for(;;){
    }
}