#ifdef _WIN32
#define bool int
#define true 1
#define false 0
#endif

struct Interval {
	int start;
	int end;
};

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

inline bool overlap(const struct Interval* a, const struct Interval* b) {
	return !(a->end < b->start || a->start > b->end);
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct Interval* merge(struct Interval* intervals, int intervalsSize, int* returnSize) {
	bool* dead = (bool*)malloc(intervalsSize * sizeof(bool));
	memset(dead, 0, intervalsSize * sizeof(bool));
	*returnSize = intervalsSize;
	for (int i = intervalsSize - 1; i > 0; --i)
		for (int j = 0; j < i; ++j) {
			if (overlap(intervals + i, intervals + j)) {
				dead[i] = true;
				--*returnSize;
				intervals[j].start = min(intervals[i].start, intervals[j].start);
				intervals[j].end = max(intervals[i].end, intervals[j].end);
				break;
			}
		}

	struct Interval* ans = (struct Interval*) malloc(sizeof(struct Interval) * *returnSize);
	int cnt = 0;
	for (int i = 0; i < intervalsSize; ++i)
		if (!dead[i])
			ans[cnt++] = intervals[i];
	free(dead);
	return ans;
}