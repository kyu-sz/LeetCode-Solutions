#include <stdio.h>
#include <limits.h>

int divide(int dividend, int divisor) {
	if (!divisor) return INT_MAX;

	int neg = (dividend < 0) ^ (divisor < 0);
	if (dividend < 0) dividend = -dividend;
	if (divisor < 0) divisor = -divisor;

	unsigned int quotient = 0;
	unsigned int biMultiple = divisor, coeff = 1;
	while (biMultiple <= ((unsigned int)dividend) >> 1) biMultiple <<= 1, coeff <<= 1;
	while ((unsigned int)dividend >= (unsigned int)divisor) {
		if (((unsigned int)dividend) >= biMultiple)
			dividend -= biMultiple, quotient += coeff;
		biMultiple >>= 1, coeff >>= 1;
	}

	return neg ? -quotient : quotient > INT_MAX ? INT_MAX : quotient;
}

int main() {
	printf("%d\n", divide(-1010369383, -2147483648));
	printf("%d\n", divide(-2147483648, 1));
	printf("%d\n", divide(-2147483648, -1));
	printf("%d\n", divide(9, 3));
	printf("%d\n", divide(9, 2));
	printf("%d\n", divide(9, 1));
	printf("%d\n", divide(-9, 2));
	printf("%d\n", divide(9, -2));
	printf("%d\n", divide(-9, -2));
	printf("%d\n", divide(9, 0));
	system("PAUSE");
	return 0;
}