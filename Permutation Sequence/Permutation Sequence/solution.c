#include <stdio.h>

#ifdef _WIN32
#define bool int
#define true 1
#define false 0
#endif

char* getPermutation(int n, int k) {
	--k;
	char *ans = (char*)malloc(sizeof(char) * (n + 1));
	ans[n] = '\0';

	bool *used = (bool*)malloc(n * sizeof(bool));
	memset(used, 0, sizeof(bool) * n);

	int to_fill = 0;
	int factorial;
	int base;

	while (k) {
		factorial = 1;
		base = 1;

		while (factorial < k)
			factorial *= ++base;
		if (factorial > k)
			factorial /= base--;

		int last_unused = 0;
		for (int i = to_fill; i < n - base - 1; ++i) {
			while (used[last_unused])
				++last_unused;
			ans[i] = last_unused + '1';
			used[last_unused++] = true;
		}

		for (int i = 0; i < k / factorial; ++i) {
			while (used[last_unused])
				++last_unused;
			++last_unused;
		}
		while (used[last_unused])
			++last_unused;
		ans[n - base - 1] = last_unused + '1';
		used[last_unused] = true;
		to_fill = n - base;

		k %= factorial;
	}

	int last_unused = 0;
	for (int i = to_fill; i < n; ++i) {
		while (used[last_unused])
			++last_unused;
		ans[i] = last_unused + '1';
		used[last_unused++] = true;
	}

	return ans;
}

int main() {
	{
		int n = 4;
		int factor = 1;
		for (int i = 2; i <= n; ++i) factor *= i;
		for (int i = 0; i < factor; ++i) {
			char* res = getPermutation(n, i);
			printf("%s\n", res);
			free(res);
		}
		puts("");
	}
	{
		char* res = getPermutation(8, 8590);
		printf("%s\n", res);
		free(res);
		puts("");
	}
	system("PAUSE");
	return 0;
}