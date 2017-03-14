#include <stdio.h>

void dfs(char* buf, int idx, int leftCnt, char*** pRes, int* pBufSize, int n, int* returnSize) {
	if (idx == (n << 1)) {
		(*pRes)[*returnSize] = (char*)malloc(sizeof(char) * (n << 1 | 1));
		memcpy((*pRes)[(*returnSize)++], buf, sizeof(char) * (n << 1 | 1));
		if (*returnSize >= *pBufSize) {
			char** temp = (char**)malloc(sizeof(char*) * ((*pBufSize) <<= 1));
			memcpy(temp, *pRes, sizeof(char*) * *returnSize);
			free(*pRes);
			*pRes = temp;
		}
	}
	else {
		if (leftCnt < n && (n << 1) - idx > leftCnt) {
			buf[idx] = '(';
			dfs(buf, idx + 1, leftCnt + 1, pRes, pBufSize, n, returnSize);
		}
		if (leftCnt) {
			buf[idx] = ')';
			dfs(buf, idx + 1, leftCnt - 1, pRes, pBufSize, n, returnSize);
		}
	}
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** generateParenthesis(int n, int* returnSize) {
	int bufSize = 1000;
	char* buf = (char*)malloc(sizeof(char) * (n << 1 | 1));
	char** res = (char**)malloc(sizeof(char*) * bufSize);
	buf[(n << 1)] = '\0';
	*returnSize = 0;
	dfs(buf, 0, 0, &res, &bufSize, n, returnSize);
	return res;
}

int main() {
	int retSize;
	char** res = generateParenthesis(3, &retSize);
	for (int i = 0; i < retSize; ++i) {
		printf("%s\n", res[i]);
		free(res[i]);
	}
	free(res);
	return 0;
}