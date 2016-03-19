#include <stdio.h>

#include <limits.h>

int myAtoi(char* str) {

	int _sign;
	long long res = 0;	//Experiments show that de

	while (*str == ' ') ++str;
	if (_sign = (*str == '-')) {
		++str;
	}
	else if (*str == '+') ++str;

	while (*str == '0') ++str;

	while (*str >= '0' && *str <= '9') {
		res = res * 10 + *str++ - '0';
		if (res > INT_MAX)
			return _sign ? INT_MIN : INT_MAX;
	}
	return _sign ? -res : res;
}

int main() {
	printf("%d\n", myAtoi("1"));
	printf("%d\n", myAtoi("-100"));
	printf("%d\n", myAtoi("000100"));
	printf("%d\n", myAtoi("+"));
	printf("%d\n", myAtoi("+-2"));
	printf("%d\n", myAtoi("    010"));
	printf("%d\n", myAtoi("    010a2379"));
	printf("%d\n", myAtoi("2147483647"));
	printf("%d\n", myAtoi("2147483648"));
	printf("%d\n", myAtoi("-2147483648"));
	printf("%d\n", myAtoi("    10522545459"));
	return 0;
}