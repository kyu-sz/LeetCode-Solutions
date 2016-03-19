#include <iostream>

using namespace std;

#include <climits>

class Solution {
public:
	int reverse(int x) {
		bool neg;
		if (neg = x < 0)
			x = -x;

		int res = 0;
		int temp;
		const int ten_times_limit = INT_MAX / 10;
		while (x) {
			if (res > ten_times_limit)
				return 0;
			res *= 10;
			temp = x / 10;
			const int unit = x - temp * 10;
			if (INT_MAX - res <= unit)
				return 0;
			else
				res += unit;
			x = temp;
		}

		return neg ? -res : res;
	}
};

int main() {
	Solution solution;
	cout << solution.reverse(0) << endl;
	cout << solution.reverse(-0) << endl;
	cout << solution.reverse(1) << endl;
	cout << solution.reverse(-1) << endl;
	cout << solution.reverse(123) << endl;
	cout << solution.reverse(-123) << endl;
	cout << solution.reverse(1534236469) << endl;
	return 0;
}