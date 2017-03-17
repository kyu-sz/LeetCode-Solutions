#include <stdio.h>

int longestValidParentheses(char* s) {
	int best = 0, len = 0;

	// from left to right
	{
		int lastValid = 0, segCnt = 0, leftCnt = 0;
		while (*s) {
			++len;
			if (*s++ == '(')
				++leftCnt, ++segCnt;
			else
				// still valid
				if (leftCnt) {
					--leftCnt;
					++segCnt;
					// finished a valid segment
					if (!leftCnt) lastValid = segCnt;
				}
				// invalid
				else {
					if (lastValid > best) best = lastValid;
					lastValid = segCnt = 0;
				}
		}

		if (lastValid > best) best = lastValid;
	}

	// from right to left
	{
		int lastValid = 0, segCnt = 0, rightCnt = 0;
		while (len--) {
			if (*--s == ')')
				++rightCnt, ++segCnt;
			else
				// still valid
				if (rightCnt) {
					--rightCnt;
					++segCnt;
					// finished a valid segment
					if (!rightCnt) lastValid = segCnt;
				}
				// invalid
				else {
					if (lastValid > best) best = lastValid;
					lastValid = segCnt = 0;
				}
		}

		if (lastValid > best) best = lastValid;
	}

	return best;
}

int main() {
	printf("%d\n", longestValidParentheses(")(((((()())()()))()(()))("));
	printf("%d\n", longestValidParentheses("()()"));
	printf("%d\n", longestValidParentheses(")"));
	printf("%d\n", longestValidParentheses("(()(((()"));
	return 0;
}