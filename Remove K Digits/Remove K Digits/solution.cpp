#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	string removeKdigits(string num, int k) {
		int num_digit_left = num.length() - k;
		if (!num_digit_left)
			return string("0");
		char* buf = new char[num.length() + 1];
		buf[0] = num[0];
		int cnt = 1;

		for (int i = 1; i < num.length(); ++i) {
			int left = max(i - k, 0);
			int right = max(left, cnt - 1);
			while (left < right) {
				int mid = (left + right) >> 1;
				if (num[i] < buf[mid])
					right = mid;
				else
					left = mid + 1;
			}
			if (num[i] < buf[right]) {
				buf[right] = num[i];
				cnt = right + 1;

				if (num_digit_left - cnt == num.length() - i - 1) {
					while (cnt < num_digit_left)
						buf[cnt++] = num[++i];
					break;
				}
			}
			else if (cnt < num_digit_left)
				buf[cnt++] = num[i];
		}

		buf[num_digit_left] = '\0';
		char* start = buf;
		while (*start == '0' && start[1] != '\0')
			++start;
		string ans(start);
		delete[] buf;
		return ans;
	}
};