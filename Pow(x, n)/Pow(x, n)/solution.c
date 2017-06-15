#include <limits.h>

double myPow(double x, int n) {
	double ans = 1.;
	int flag = (n < 0);
	if (flag) {
		if (n == INT_MIN)
			++n, ans = x;
		n = -n;
	}

	double v = x;
	while (n) {
		if (n & 1)
			ans *= v;
		n >>= 1;
		v *= v;
	}

	if (flag)
		ans = 1. / ans;

	return ans;
}