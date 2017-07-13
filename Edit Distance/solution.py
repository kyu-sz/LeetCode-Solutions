class Solution(object):
    def minDistance(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        len1 = len(word1)

        # "steps" records the least steps at a stage.
        # the worst solution is replace all characters and add the rest characters.
        steps = [max(len1, len(word2))] * (len1 + 1)
        steps[0] = 0

        for c in word2:
            last_matching_idx = -1
            # if reaching the last word of word1, a char should be added to match this char in word2.
            steps[len1] += 1
            # assuming we are using the i-th character in word1 to match 'c'
            for i in reversed(xrange(len1)):
                # if the i-th char matches 'c'
                if word1[i] == c:
                    # use the next char in word1 to match the next char in word2 without cost
                    if steps[i + 1] > steps[i]:
                        steps[i + 1] = steps[i]
                    # if in the next step, we still want to use this character to match, we have to add one char here.
                    steps[i] += 1

                    last_matching_idx = i
                else:
                    # consider deleting the following chars until find one matching.
                    if last_matching_idx >= 0 and steps[last_matching_idx + 1] > steps[i] + last_matching_idx - i:
                        steps[last_matching_idx + 1] = steps[i] + last_matching_idx - i

                    # if in the next step, we still want to use this character to match, we have to add one char here.
                    steps[i] += 1

                    # use the next char in word1 to match the next char in word2 by replacing the i-th char
                    if steps[i + 1] > steps[i]: # we have already added 1 to steps[i] ahead
                        steps[i + 1] = steps[i]

        # now that we have matched all chars in word2.
        # we need to delete the redundant chars in word1.
        best = steps[len1]
        for i in xrange(len1):
            if steps[i] + len1 - i < best:
                best = steps[i] + len1 - i

        return best


if __name__ == "__main__":
    print Solution().minDistance("a", "b")
    print Solution().minDistance("", "abcda")
    print Solution().minDistance("abbcda", "abcda")