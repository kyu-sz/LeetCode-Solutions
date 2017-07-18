class Solution(object):
    def maximalRectangle(self, matrix):
        """
        :type matrix: List[str]
        :rtype: int
        """
        m = len(matrix)
        if m == 0:
            return 0
        n = len(matrix[0])
        if n == 0:
            return 0

        best = 0
        stacks = []
        heights = [1] * n
        continuous_cnt = 0
        for i in xrange(n):
            stack = [()] * m
            if matrix[0][i] == '1':
                continuous_cnt += 1
            else:
                continuous_cnt = 0
            stack[0] = (continuous_cnt, 0)
            stacks.append(stack)

        for i in xrange(1, m):
            continuous_cnt = 0
            for j in xrange(n):
                if matrix[i][j] == '1':
                    continuous_cnt += 1
                else:
                    continuous_cnt = 0

                stack = stacks[j]
                top = heights[j] - 1
                rec = stack[top]
                if rec[0] > continuous_cnt:
                    while rec[0] > continuous_cnt:
                        if best < rec[0] * (i - rec[1]):
                            best = rec[0] * (i - rec[1])
                        if top <= 0 or stack[top - 1][0] < continuous_cnt:
                            stack[top] = (continuous_cnt, rec[1])
                            break
                        else:
                            heights[j] -= 1
                            top -= 1
                            rec = stack[top]
                else:
                    if continuous_cnt > rec[0]:
                        stack[heights[j]] = (continuous_cnt, i)
                        heights[j] += 1

        for i in xrange(n):
            stack = stacks[i]
            for j in xrange(heights[i]):
                rec = stack[j]
                if best < rec[0] * (m - rec[1]):
                    best = rec[0] * (m - rec[1])

        return best


if __name__ == "__main__":
    print Solution().maximalRectangle(["011","101","011","110","000","010"])
    print Solution().maximalRectangle(["101101","111111","011011","111010","011111","110111"])
    print Solution().maximalRectangle(["10100", "10111", "11111", "10010"])
