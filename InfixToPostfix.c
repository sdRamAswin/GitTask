// SPDX-License-Identifier: UNLICENSED
#include "stack.h"
#include "Conversion.h"
#include "Evaluation.h"


/* Function which is executed at first */
int main(void)
{
	char Postfix_expression[MAX_SIZE], Infix_expression[MAX_SIZE];

	printf("Enter an infix expression to be converted: ");
	scanf("%s", Infix_expression);

	Convert_infix_to_postfix(Infix_expression, Postfix_expression);

	printf("Converted Postfix expression is %s\n", Postfix_expression);

	u32 Evaluated_result = Evaluate_postfix_expression(Postfix_expression);

	printf("The evaluated postfix expression's result is %d\n", Evaluated_result);

	return 0;
}
