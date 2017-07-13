class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        skipped_cnt = 0
        stack = []
        elements = path.split('/')
        for e in reversed(elements):
            if e == "." or e == "":
                pass
            elif e == "..":
                skipped_cnt += 1
            else:
                if skipped_cnt:
                    skipped_cnt -= 1
                else:
                    stack.append(e)

        if len(stack) == 0:
            return '/'
        else:
            res = ''
            for e in reversed(stack):
                res += '/' + e
            return res
