int removeElement(int* nums, int numsSize, int val) {
	int *p1 = nums - 1, *p2 = nums, *end = nums + numsSize;
	while (++p1 < end)
		if (*p1 != val)
			*p2++ = *p1;
	return p2 - p1;
}