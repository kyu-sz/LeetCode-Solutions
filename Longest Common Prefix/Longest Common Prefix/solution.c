#include <assert.h>

#include <string.h>
char* longestCommonPrefix(char** strs, int strsSize) {
	if (strsSize == 0) return "";
	char* res = (char *)malloc(strlen(strs[0]));
	int offset = -1;
	while (strs[0][++offset] != '\0') {
		int ok = 1;
		char c = strs[0][offset];
		for (int i = 1; i < strsSize; ++i) {
			if (strs[i][offset] != c) {
				ok = 0;
				break;
			}
		}
		if (!ok) break;
		res[offset] = c;
	}
	res[offset] = '\0';
	return res;
}

int main() {
	{
		char *strs[] = { "abc", "abd", "ab", "abcd" };
		assert(!strcmp("ab", longestCommonPrefix(strs, 4)));
	}
	{
		char *strs[] = { "a" };
		assert(!strcmp("a", longestCommonPrefix(strs, 1)));
	}
	{
		char *str = NULL;
		assert(!strcmp("", longestCommonPrefix(&str, 0)));
	}
	return 0;
}