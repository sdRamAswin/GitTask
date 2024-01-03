// SPDX-License-Identifier: UNLICENSED
#include "Evaluation.h"
#include <ctype.h>
#include "stack.h"


/* Function to check the character is an operator */
static int is_operator(char term)
{
	return (term == '+' || term == '-' || term == '*' || term == '/' || term == '^');
}

/* Function to perform the operations */
static int Perform_operation(u8 operand_1, u8 operand_2, char term)
{
	switch (term) {
	case '+':
		return operand_1 + operand_2;
	case '-':
		return operand_1 - operand_2;
	case '*':
		return operand_1 * operand_2;
	case '/':
		return operand_1 / operand_2;
	case '^':
		return operand_2 ^ operand_1;
	default:
		return 0;
	}
}
/* Function to evaluate the postfix expressions */
int Evaluate_postfix_expression(char *Postfix_expression)
{
	Stack_info stack;

	for (u8 i = 0; Postfix_expression[i] != '\0'; i++) {
		char term = Postfix_expression[i];

		if (isalpha(term))
			Stack_push(&stack, term - 'A' + 1);
		else if (isdigit(term))
			Stack_push(&stack, term - '0');
		else if (is_operator(term)) {
			u8 Operand_2 = Stack_pop(&stack);

			stack.stack_items[stack.top] = 0;
			u8 Operand_1 = Stack_pop(&stack);

			stack.stack_items[stack.top] = 0;
			Stack_push(&stack, Perform_operation(Operand_1, Operand_2, term));
		}
	}
	return Stack_pop(&stack);
}
