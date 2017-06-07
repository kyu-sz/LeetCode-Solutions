#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char* multiply(char* num1, char* num2) {
	int len1 = strlen(num1);
	int len2 = strlen(num2);
	int res_len = len1 + len2;
	char* res = malloc((res_len + 2) * sizeof(char));
	memset(res, 0, (res_len + 2) * sizeof(char));

	for (int j = 0; j < len2; ++j)
		num2[j] -= '0';
	for (int i = len1; i; --i) {
		num1[i - 1] -= '0';
		for (int j = len2; j; --j) {
			res[i + j] += num1[i - 1] * num2[j - 1];
			if (res[i + j] >= 10) {
				int carry = res[i + j] / 10;
				res[i + j - 1] += carry;
				res[i + j] -= carry * 10;
			}
		}
	}

	int num_zeros = 0;
	while (!res[num_zeros] && num_zeros < res_len)
		++num_zeros;
	for (int i = 0; i <= res_len - num_zeros; ++i)
		res[i] = res[i + num_zeros] + '0';
	res[res_len - num_zeros + 1] = '\0';

	return res;
}

int main() {
	{
		char num1[] = "9", num2[] = "9";
		char *res = multiply(num1, num2);
		printf("%s\n", res);
		free(res);
	}
	{
		char num1[] = "0", num2[] = "0";
		char *res = multiply(num1, num2);
		printf("%s\n", res);
		free(res);
	}
	{
		char num1[] = "99", num2[] = "9";
		char *res = multiply(num1, num2);
		printf("%s\n", res);
		free(res);
	}
	{
		char num1[] = "99", num2[] = "99";
		char *res = multiply(num1, num2);
		printf("%s\n", res);
		free(res);
	}
	system("PAUSE");
	return 0;
}