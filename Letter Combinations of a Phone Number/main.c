#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_BUTTON 12

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize)
{
	const static char rep[NUM_BUTTON + 1][5] =
	{ "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz", "*", " ",
			"#" };	// The characters each digit can represent.
	int i;
	int dup;
	int num_digits = strlen(digits);
	int num_rep[NUM_BUTTON];	// Number of characters each digit can represent.
	char** res = NULL;
	for (i = 1; i <= NUM_BUTTON; ++i)
		num_rep[i] = strlen(rep[i]);

	*returnSize = (num_digits != 0);
	for (i = 0; i < num_digits; ++i)
		*returnSize *= num_rep[digits[i] - '0'];

	res = malloc(sizeof(char*) * *returnSize);
	for (i = 0; i < *returnSize; ++i)
		res[i] = malloc(sizeof(char) * (num_digits + 1));

	dup = 1;
	for (i = 0; i < num_digits; ++i)
	{
		int num = digits[i] - '0';
		const char* p = rep[num];
		int j = 0;
		while (j < *returnSize)
		{
			int k;
			for (k = 0; k < dup; ++k)
				res[j++][i] = *p;
			putchar(*p);
			++p;
			if (!*p)
				p = rep[num];
		}
		dup *= num_rep[num];
	}

	for (i = 0; i < *returnSize; ++i)
		res[i][num_digits] = '\0';

	return res;
}

int main()
{
	char digits[10] = "";
	int ret_size = 0;
	char** res = letterCombinations(digits, &ret_size);
	int i;

	printf("Return Size=%d\n", ret_size);
	for (i = 0; i < ret_size; ++i)
	{
		printf("|%s|\n", res[i]);
		free(res[i]);
	}
	free(res);
	return 0;
}
