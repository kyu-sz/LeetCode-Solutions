#include <vector>

using namespace std;

class Solution {
public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		int* ready = new int[numCourses];
		int num_ready = 0;
		vector<int> *post = new vector<int>[numCourses];
		int *num_pre = new int[numCourses];
		memset(num_pre, 0, sizeof(int) * numCourses);
		vector<int> ans;

		for (auto p : prerequisites) {
			post[p.second].push_back(p.first);
			++num_pre[p.first];
		}
		for (int i = 0; i < numCourses; ++i)
			if (!num_pre[i])
				ready[num_ready++] = i;

		while (num_ready) {
			int x = ready[--num_ready];
			ans.push_back(x);
			for (int p : post[x])
				if (!--num_pre[p])
					ready[num_ready++] = p;
		}

		delete[] ready;
		delete[] num_pre;
		delete[] post;

		if (ans.size() != numCourses)
			ans.clear();
		return ans;
	}
};