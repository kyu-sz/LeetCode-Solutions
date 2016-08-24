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
	{ "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz", "*",
			" ", "#" };	// The characters each digit can represent.
	int i, j;
	int num_digits = strlen(digits);
	int num_rep[NUM_BUTTON];// Number of characters each digit can represent.
	char** res = NULL;
	int *selection = malloc(sizeof(char) * num_digits);
	int *toggle = malloc(sizeof(char) * num_digits);

	for (i = 1; i <= NUM_BUTTON; ++i)
		num_rep[i] = strlen(rep[i]);

	*returnSize = (num_digits != 0);
	for (i = 0; i < num_digits; ++i)
		*returnSize *= num_rep[(int)(digits[i] -= '0')];

	res = malloc(sizeof(char*) * *returnSize);
	for (i = 0; i < *returnSize; ++i)
		res[i] = malloc(sizeof(char) * (num_digits + 1));

	memset(selection, 0, sizeof(int) * num_digits);
	memset(toggle, 0, sizeof(int) * num_digits);
	for (i = 0; i < *returnSize; ++i)
	{
		for (j = 0; j < num_digits; ++j)
			res[i][j] = rep[(int)digits[j]][selection[j]];

		if (i + 1 < *returnSize)
		{
			j = 0;
			while (1)
			{
				if (toggle[j])
				{
					if (selection[j])
					{
						--selection[j];
						break;
					}
				}
				else
				{
					if (selection[j] + 1 < num_rep[(int)digits[j]])
					{
						++selection[j];
						break;
					}
				}
				toggle[j] = !toggle[j++];
			}
		}

		res[i][num_digits] = '\0';
	}

	free(selection);
	free(toggle);

	return res;
}

int main()
{
	char digits[10] = "23";
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
