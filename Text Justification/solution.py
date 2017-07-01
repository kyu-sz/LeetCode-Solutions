class Solution(object):
    def fullJustify(self, words, maxWidth):
        """
        :type words: List[str]
        :type maxWidth: int
        :rtype: List[str]
        """
        res = []
        buf = []
        word_cnt = 0
        len_cnt = 0
        for word in words:
            l = len(word)
            if len_cnt + word_cnt + l <= maxWidth:
                buf.append(word)
                word_cnt += 1
                len_cnt += l
            else:
                total_interval = maxWidth - len_cnt
                if word_cnt > 1:
                    min_interval = total_interval / (word_cnt - 1)
                    padding_cnt = total_interval - min_interval * (word_cnt - 1)
                    line = ''
                    for i in xrange(0, padding_cnt):
                        line += buf[i] + ' ' * (min_interval + 1)
                    for i in xrange(padding_cnt, word_cnt - 1):
                        line += buf[i] + ' ' * min_interval
                    line += buf[word_cnt - 1]
                    res.append(line)
                else:
                    res.append(buf[0] + ' ' * total_interval)
                buf = [word]
                word_cnt = 1
                len_cnt = l

        line = buf[0]
        for i in xrange(1, word_cnt):
            line += ' ' + buf[i]
        line += ' ' * (maxWidth - max(0, word_cnt - 1) - len_cnt)
        res.append(line)

        return res

if __name__ == "__main__":
    print Solution().fullJustify(["Here","is","an","example","of","text","justification."], 14)