#ifndef __BUS_H
#define __BUS_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUS_DEVICES 0x100

typedef struct{
    uint16_t start_addr;
    uint16_t size;
    uint8_t* redirect;
} Bus_Device;

extern Bus_Device* devices[];
extern Bus_Device RAM;

void init_bus();
uint8_t read_from_bus(uint16_t addr);
void write_to_bus(uint16_t addr, uint8_t value);

#endif