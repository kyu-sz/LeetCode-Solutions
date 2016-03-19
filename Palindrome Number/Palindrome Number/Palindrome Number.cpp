#include <stdio.h>

bool isPalindrome(int x) {
	if (x < 0)
		return false;

	int units[10];
	int len = 0;
	int temp;
	int i;
	int half_len;

	while (x) {
		temp = x / 10;
		units[len++] = x - temp * 10;
		x = temp;
	}

	half_len = len >> 1;
	for (i = 0; i < half_len; ++i)
		if (units[i] != units[len - 1 - i])
			return false;
	return true;
}

int main() {
	printf("%d\n", isPalindrome(1));
	printf("%d\n", isPalindrome(11));
	printf("%d\n", isPalindrome(12));
	printf("%d\n", isPalindrome(101));
	printf("%d\n", isPalindrome(10001));
	printf("%d\n", isPalindrome(10011));
	return 0;
}