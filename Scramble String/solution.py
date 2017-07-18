class Solution(object):
    def isScramble(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        n = len(s1)

        unmatched_cnt = 0
        cnt1 = [0] * 128
        cnt2 = [0] * 128
        for i in xrange(n - 1):
            c1 = ord(s1[i])
            c2 = ord(s2[i])
            if c1 != c2:
                if cnt2[c1]:
                    cnt2[c1] -= 1
                    unmatched_cnt -= 1
                else:
                    cnt1[c1] += 1
                    unmatched_cnt += 1
                if cnt1[c2]:
                    cnt1[c2] -= 1
                    unmatched_cnt -= 1
                else:
                    cnt2[c2] += 1
                    unmatched_cnt += 1
            if not unmatched_cnt:
                if self.isScramble(s1[:i + 1], s2[:i + 1]) and self.isScramble(s1[i + 1:], s2[i + 1:]):
                    return True

        c1 = ord(s1[n - 1])
        c2 = ord(s2[n - 1])
        if c1 != c2:
            if cnt2[c1]:
                cnt2[c1] -= 1
                unmatched_cnt -= 1
            else:
                cnt1[c1] += 1
                unmatched_cnt += 1
            if cnt1[c2]:
                cnt1[c2] -= 1
                unmatched_cnt -= 1
            else:
                cnt2[c2] += 1
                unmatched_cnt += 1
        if unmatched_cnt:
            return False
        elif n <= 3:
            return True

        for i in xrange(n - 1):
            c1 = ord(s1[i])
            c2 = ord(s2[n - 1 - i])
            if c1 != c2:
                if cnt2[c1]:
                    cnt2[c1] -= 1
                    unmatched_cnt -= 1
                else:
                    cnt1[c1] += 1
                    unmatched_cnt += 1
                if cnt1[c2]:
                    cnt1[c2] -= 1
                    unmatched_cnt -= 1
                else:
                    cnt2[c2] += 1
                    unmatched_cnt += 1
            if not unmatched_cnt:
                if self.isScramble(s1[:i + 1], s2[n - 1 - i:]) and self.isScramble(s1[i + 1:], s2[:n - 1 - i]):
                    return True

        return False


if __name__ == "__main__":
    print Solution().isScramble("hobobyrqd", "hbyorqdbo")
