#include <arch/bus.h>
#include <arch/cpu.h>

uint8_t bus_gen_cycles = 0; 

Bus_Device* devices[MAX_BUS_DEVICES];

Bus_Device RAM = {.start_addr = 0x0, .size = 0xFFFF, .redirect = (uint8_t*)0};

void init_bus(){

    for(uint16_t device = 0; device < MAX_BUS_DEVICES; device++){
       devices[device] = NULL;
    }

    RAM.redirect = malloc(0xFFFF);
    devices[MAX_BUS_DEVICES - 1] = &RAM;
}

uint8_t read_from_bus(uint16_t addr){
    for(uint16_t device = 0; device < MAX_BUS_DEVICES; device++){
        if(devices[device] != NULL){
            if(addr >= devices[device]->start_addr && addr <= devices[device]->start_addr + devices[device]->size && devices[device] != NULL){
                cycles += bus_gen_cycles + (addr / PAGE_SIZE != current_page);
                return devices[device]->redirect[addr];
            }
        }
    }
    printf("ERROR: Trying to read from non existant device attached on the bus!\n");
    exit(0);
    return 0;
}

void write_to_bus(uint16_t addr, uint8_t value){
    for(uint16_t device = 0; device < MAX_BUS_DEVICES; device++){
        if(devices[device] != NULL){
            if(addr >= devices[device]->start_addr && addr <= devices[device]->start_addr + devices[device]->size){
                devices[device]->redirect[addr] = value;
                cycles += bus_gen_cycles;
                return;
            }
        }
    }
    printf("ERROR: Trying to write to non existant device attached on the bus!\n");
    exit(0);
}