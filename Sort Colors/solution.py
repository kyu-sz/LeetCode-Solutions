class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        r = 0
        w = 0
        for x in nums:
            if x == 0:
                r += 1
            elif x == 1:
                w += 1
        nums[:r] = [0] * r
        nums[r: r + w] = [1] * w
        nums[r + w:] = [2] * (len(nums) - r - w)


if __name__ == "__main__":
    nums = [1, 0]
    Solution().sortColors(nums)
    print nums
