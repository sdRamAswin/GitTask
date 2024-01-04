// SPDX-License-Identifier: UNLICENSED
#include "Conversion.h"
#include "stack.h"
#include "Evaluation.h"
#include <ctype.h>

/* Function to get the precedence of the operator */
int Get_operator_precedence(char Operator)
{
	switch (Operator) {
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	case '^':
		return 3;
	default:
		return 0;
	}
}

/* Function to convert infix expression into postfix expression */
int Convert_infix_to_postfix(char *Infix_expression, char *Postfix_expression)
{
	u8 j = 0;

	Stack_info stack;

	stack.top = 0;

	for (u8 i = 0; Infix_expression[i] != '\0'; i++) {
		char term = Infix_expression[i];

		if (isalpha(term))
			Postfix_expression[j++] = term;
		else if (isdigit(term))
			Postfix_expression[j++] = term;
		else if (term == '(')
			Stack_push(&stack, term);
		else if (term == ')') {
			while (stack.top != 0 && stack.stack_items[stack.top - 1] != '(') {
				Postfix_expression[j++] = Stack_pop(&stack);
				stack.stack_items[stack.top] = '0';
			}
			if (stack.top != 0)
				Stack_pop(&stack);
			else
				NULL;
		} else if (is_operator(term)) {
			while (stack.top != 0 && Get_operator_precedence(term) <= Get_operator_precedence(stack.stack_items[stack.top - 1]))
				Postfix_expression[j++] = Stack_pop(&stack);
			Stack_push(&stack, term);
		} else
			NULL;
	}
	while (stack.top != 0)
		Postfix_expression[j++] = Stack_pop(&stack);
	Postfix_expression[j] = '\0';

	return 0;
}
