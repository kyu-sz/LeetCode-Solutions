class Solution(object):
    def isNumber(self, s):
        """
        :type s: str
        :rtype: bool
        """

        """
        0: start
        1: number appeared
        2: floating point appeared
        4: 'e' appeared
        8: sign appeared
        16: endable
        32: exponent sign appeared
        64: exponent number appeared
        128: end
        """
        status = 0

        for c in s:
            if c == ' ':
                if status and status != 128:    # anything other than space has appeared and not ended
                    if status & 16:     # endable
                        status = 128
                    else:
                        return False
            else:   # any non-space character
                if status == 128:   # already ended
                    return False
                if '0' <= c <= '9':     # number
                    status |= 1 | 16 | (32 if status & 4 else 0)
                elif c == '-' or c == '+':  # sign
                    if status & 4:  # after an 'e'
                        if status & (32 | 64):  # any number or sign between this sign and the 'e'
                            return False
                        else:
                            status |= 64
                    elif status:    # anything other than space has appeared
                        return False
                    else:
                        status |= 8
                elif c == '.':
                    if status & (2 | 4):
                        return False
                    else:
                        status |= 2
                elif c == 'e':
                    if status & (1 | 4) == 1:
                        status |= 4
                        status &= ~16
                    else:
                        return False
                else:
                    return False

        return bool(status & (16 | 128))

if __name__ == '__main__':
    print Solution().isNumber('-8-')
