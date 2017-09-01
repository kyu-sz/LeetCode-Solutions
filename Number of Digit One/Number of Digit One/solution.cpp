#include <iostream>
using namespace std;

class Solution {
public:
	int countDigitOne(int n) {
		if (n <= 0)
			return 0;
		// Number of ones in numbers smaller than 0, 10, 100, ...
		int ones_per_lv[50] = { 0, 1 };
		// Level of ten multiples: 1, 10, 100, ...
		int ten_lv = 1;
		// Digits: 0, 1, 2, 3, ...
		int digits = 1;
		while (ten_lv <= n / 10) {
			ones_per_lv[digits + 1] = ones_per_lv[digits] * 10 + (ten_lv *= 10);
			++digits;
		}
		// Number of "1"s at the front of n.
		int ones_ahead = 0;
		// Total counter of "1"s in the numbers smaller than n.
		int total_ones = 0;
		// Take n=1301 for example.
		while (digits > 0) {
			// Coefficient at the current ten multiple level.
			int coeff = n / ten_lv;

			// Take the moment when we are looking at the 3 for example.
			// Add ones from 0 ~ 300.
			total_ones += coeff * ones_per_lv[digits - 1] + ((coeff > 1) ? ten_lv : 0);
			// Add ones coming from the 1000 in all 0 ~ 300.
			total_ones += ones_ahead * coeff * ten_lv;

			if (coeff == 1) ++ones_ahead;

			n %= ten_lv;
			ten_lv /= 10;
			--digits;
		}
		return total_ones + ones_ahead;
	}
};