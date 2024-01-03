#ifndef STACK_H
#define STACK_H

#include <stdint.h>
#include <stdio.h>

typedef uint8_t u8;
typedef uint32_t u32;

#define MAX_SIZE 10

typedef struct {
    u8 stack_items[MAX_SIZE];
    u8 top;
} Stack_info;


void Stack_push(Stack_info *stack, u8 value);
int Stack_pop(Stack_info *stack);

#endif
