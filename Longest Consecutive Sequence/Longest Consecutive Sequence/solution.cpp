#include <vector>
#include <iostream>

using namespace std;

class Solution {
	/*! Unrewritable hash map from integers to non-negative integers.
	 */
	class HashSet {
		bool* used_;
		int* storage_;
		int n_;
	public:
		HashSet(int n) {
			n_ = (n << 1) + rand() % (n + 1);
			storage_ = new int[n_];
			used_ = new bool[n_];
			memset(used_, 0, sizeof(bool) * (n_));
		}
		~HashSet() { delete[] storage_; delete[] used_; }
		bool find(int x) {
			int h = x % n_;
			if (h < 0) h += n_;
			int start = h;
			while (used_[h]) {
				if (storage_[h] == x)
					return true;
				else
					++h;
				if (h >= n_) h %= n_;
				if (h == start)
					return false;
			}
			return false;
		}
		void add(int x) {
			int h = x % n_;
			if (h < 0) h += n_;
			while (used_[h] && storage_[h] != x) {
				++h;
				if (h >= n_) h %= n_;
			}
			used_[h] = true;
			storage_[h] = x;
		}
	};
public:
	int longestConsecutive(vector<int>& nums) {
		HashSet checked(nums.size());
		HashSet exist(nums.size());
		for (auto x : nums)
			exist.add(x);

		int longest = 0;
		for (int i = 0; i < nums.size(); ++i)
			if (!checked.find(nums[i]))
			{
				checked.add(nums[i]);
				int cnt = 0;
				int offset = 1;
				while (exist.find(nums[i] + offset))
					checked.add(nums[i] + offset++);
				cnt += offset - 1;
				offset = 1;
				while (exist.find(nums[i] - offset))
					checked.add(nums[i] - offset++);
				if (cnt + offset > longest)
					longest = cnt + offset;
			}

		return longest;
	}
};

int main() {
	cout << Solution().longestConsecutive(vector<int>({ 9, 1, 4, 7, 3, -1, 0, 5, 8, -1, 6 })) << endl;
	cout << Solution().longestConsecutive(vector<int>({ 1,0,-1 })) << endl;
	cout << Solution().longestConsecutive(vector<int>({ 0,-1 })) << endl;
	cout << Solution().longestConsecutive(vector<int>({ 100,4,200,1,3,2 })) << endl;
	cout << Solution().longestConsecutive(vector<int>({ 4,0,-4,-2,2,5,2,0,-8,-8,-8,-8,-1,7,4,5,5,-4,6,6,-3 })) << endl;
	system("PAUSE");
	return 0;
}