#include <stdio.h>
#include <string.h>

int strStr(char* haystack, char* needle) {
	int nLen = strlen(needle);
	int *next = (int*)malloc(sizeof(int) * nLen);
	memset(next, 0, sizeof(int) * nLen);
	next[0] = -1;
	for (int i = 1; i < nLen; i++)
	{
		int k = next[i - 1];
		while (k >= 0)
		{
			if (needle[k] == needle[i - 1])
				break;
			else
				k = next[k];
		}
		next[i] = k + 1;
	}

	int matched = 0;
	char* p = haystack;
	while (matched != nLen) {
		if (!*p) return -1;
		while (matched != -1 && *p != needle[matched])
			matched = next[matched];
		++matched, ++p;
	}

	return p - haystack - matched;
}

int main() {
	printf("%d\n", strStr("", "a"));
	printf("%d\n", strStr("aabcaaabcaabcaaaabcaaa", "aabcaabcaaa"));
	printf("%d\n", strStr("", ""));
	system("PAUSE");
	return 0;
}