class Solution(object):
    def __init__(self):
        self.l1 = 0
        self.l2 = 0
        self.s1 = None
        self.s2 = None
        self.s3 = None
        self.furthest = None

    def _isInterleave(self, p1, p2):
        if p2 < self.furthest[p1]:
            return False

        while p1 < self.l1 or p2 < self.l2:
            c = self.s3[p1 + p2]
            if p1 < self.l1 and self.s1[p1] == c:
                if p2 < self.l2 and self.s2[p2] == c:
                    self.furthest[p1] = p2
                    return self._isInterleave(p1 + 1, p2) or self._isInterleave(p1, p2 + 1)
                else:
                    p1 += 1
            elif p2 < self.l2 and self.s2[p2] == c:
                p2 += 1
            else:
                self.furthest[p1] = p2
                return False

        return True

    def isInterleave(self, s1, s2, s3):
        """
        :type s1: str
        :type s2: str
        :type s3: str
        :rtype: bool
        """
        self.l1 = len(s1)
        self.l2 = len(s2)
        self.s1 = s1
        self.s2 = s2
        self.s3 = s3

        if self.l1 + self.l2 != len(s3):
            return False

        p1 = 0
        p2 = 0
        self.furthest = [0] * (self.l1 + 1)

        while p1 < self.l1 or p2 < self.l2:
            c = s3[p1 + p2]
            if p1 < self.l1 and s1[p1] == c:
                if p2 < self.l2 and s2[p2] == c:
                    self.furthest[p1] = p2
                    return self._isInterleave(p1 + 1, p2) or self._isInterleave(p1, p2 + 1)
                else:
                    p1 += 1
            elif p2 < self.l2 and s2[p2] == c:
                p2 += 1
            else:
                self.furthest[p1] = p2
                return False

        return True


if __name__ == "__main__":
    print Solution().isInterleave("a", "", "c")
    print Solution().isInterleave("aabcc", "dbbca", "aadbbcbcac")
    print Solution().isInterleave("a", "b", "a")
    print Solution().isInterleave(
        "bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa",
        "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab",
        "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab")
