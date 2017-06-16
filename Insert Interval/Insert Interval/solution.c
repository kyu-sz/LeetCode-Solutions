
struct Interval {
	int start;
	int end;
};

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct Interval* insert(struct Interval* intervals, int intervalsSize, struct Interval newInterval, int* returnSize) {
	if (!intervalsSize) {
		*returnSize = 1;
		struct Interval* ans = (struct Interval*)malloc(sizeof(struct Interval) * *returnSize);
		ans[0] = newInterval;
		return ans;
	}

	if (newInterval.end < intervals[0].start) {
		*returnSize = intervalsSize + 1;
		struct Interval* ans = (struct Interval*)malloc(sizeof(struct Interval) * *returnSize);
		ans[0] = newInterval;
		for (int i = 0; i < intervalsSize; ++i)
			ans[i + 1] = intervals[i];
		return ans;
	}

    for (int i = 0 ; i < intervalsSize; ++i)
		if (newInterval.start <= intervals[i].end)
			if (newInterval.end < intervals[i].start) {
				*returnSize = intervalsSize + 1;
				struct Interval* ans = (struct Interval*)malloc(sizeof(struct Interval) * *returnSize);
				for (int j = 0; j < i; ++j)
					ans[j] = intervals[j];
				ans[i] = newInterval;
				for (int j = i; j < intervalsSize; ++j)
					ans[j + 1] = intervals[j];
				return ans;
			}
			else {
				int last_overlapped = i;
				while (++last_overlapped < intervalsSize)
					if (intervals[last_overlapped].start > newInterval.end)
						break;

				int num_overlapped = last_overlapped - i;
				*returnSize = intervalsSize + 1 - num_overlapped;

				struct Interval* ans = (struct Interval*)malloc(sizeof(struct Interval) * *returnSize);
				for (int j = 0; j < i; ++j)
					ans[j] = intervals[j];

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))
				ans[i].start = min(newInterval.start, intervals[i].start);
				ans[i].end = max(intervals[last_overlapped - 1].end, newInterval.end);

				for (int j = 0; j < intervalsSize - last_overlapped; ++j)
					ans[i + 1 + j] = intervals[last_overlapped + j];

				return ans;
			}

	*returnSize = intervalsSize + 1;
	struct Interval* ans = (struct Interval*)malloc(sizeof(struct Interval) * *returnSize);
	for (int i = 0; i < intervalsSize; ++i)
		ans[i] = intervals[i];
	ans[intervalsSize] = newInterval;
	return ans;
}

#include <stdio.h>

int main() {
	{
		struct Interval intervals[] = {
			{ 1,2 },{ 3,5 },{ 6,7 },{ 8,10 },{ 12,16 }
		};
		struct Interval newInterval = { 4, 9 };
		int returnSize;
		struct Interval* ans = insert(intervals, sizeof(intervals) / sizeof(struct Interval), newInterval, &returnSize);
		for (int i = 0; i < returnSize; ++i)
			printf("[%d,%d] ", ans[i].start, ans[i].end);
		puts("");
	}
	system("PAUSE");
	return 0;
}