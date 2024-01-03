// SPDX-License-Identifier: UNLICENSED
#include "stack.h"

/* Function to push the character into stack */
void Stack_push(Stack_info *stack, u8 term)
{
	if (stack->top >= MAX_SIZE - 1)
		printf("Stack overflow...\n");
	else
		stack->stack_items[(stack->top)++] = term;
}

/* Function to pop the character from stack */
int Stack_pop(Stack_info *stack)
{
	if (stack->top == 0) {
		printf("Stack underflow...\n");
		return -1;
	}
	else
		return (stack->stack_items[--stack->top]);
}
