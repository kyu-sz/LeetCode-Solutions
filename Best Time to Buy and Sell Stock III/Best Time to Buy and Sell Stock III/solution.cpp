#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int durTran1 = INT_MIN;
		int betw12 = 0;
		int durTran2 = INT_MIN;
		int afterTran2 = 0;
		int num_days = prices.size();
		for (int i = 0; i < num_days; ++i) {
			if (-prices[i] > durTran1)
				durTran1 = -prices[i];
			if (durTran1 + prices[i] > betw12)
				betw12 = durTran1 + prices[i];
			if (betw12 - prices[i] > durTran2)
				durTran2 = betw12 - prices[i];
			if (durTran2 + prices[i] > afterTran2)
				afterTran2 = durTran2 + prices[i];
		}
		return max(0, afterTran2);
	}
};