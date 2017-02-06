#include <cstdio>
#include <cassert>

bool isMatch(char* s, char* p) {
	// Match from left.
	while (true) {
		// Both strings have reached the end.
		if (*p == '\0' && *s == '\0') return true;
		// p has reached the end but s hasn't.
		if (*p == '\0') return false;
		// s has reached the end but p hasn't.
		if (*s == '\0') {
			// If only sequences remain in p, s and p can match.
			while (*p != '\0' && p[1] == '*') p += 2;
			return (*p == '\0');
		}
		// Meets wildcard character sequence.
		if (*p == '.' && p[1] == '*') {
			p += 2;
			// Skip all following wildcard characters and character sequences.
			while ((*p == '.' && (p[1] == '*' || *s != '\0')) || (*p != '\0' && p[1] == '*'))
				if (p[1] == '*') p += 2;
				else ++p, ++s;
			if (*p == '\0') return true;
			// Some isolate ordinary characters are left in p to match.
			while (*s != '\0') {
				// Find a possible starting position in s.
				while (*s != *p && *s != '\0') ++s;
				// Try matching.
				if (isMatch(s, p)) return true;
				// Failed. Find a next starting position.
				++s;
			}
			// All tempts failed.
			return false;
		}
		// Meets a single wildcard character.
		else if (*p == '.') ++s, ++p;
		// *p is determined to be an ordinary character.
		// Meets a sequence of ordinary characters.
		else if (p[1] == '*') {
			char c = *p;
			// Find the end of the current sequence of c in s.
			char* end_s = s;
			while (*end_s == c) ++end_s;
			while (true) {
				// Skip the following same characters in p.
				while (*p == c) {
					// Meets another sequence. Skip simply.
					if (p[1] == '*') p += 2;
					// Meets a single character. Need to match one in s.
					else if (*s != c) return false;
					else ++p, ++s;
				}

				// Now *p is not c.
				// Meets a sequence of another character.
				if (p[1] == '*') {
					// If this is a sequence of wildcard characters, make it handled somewhere else.
					if (*p == '.') break;
					// Still able to skip and continue to match c.
					// But let's first check if it is ok if we finish matching c in s.
					if (isMatch(end_s, p)) return true;
					// If it is not ok, skip this sequence and try continuing matching c.
					p += 2;
				}
				// Meets isolated wildcard characters.
				else if (*p == '.') {
					// Still able to skip and continue to match c.
					// But let's first check if it is ok if we finish matching c in s.
					if (isMatch(end_s, p)) return true;
					// If it is not ok, try matching this character with one c in s.
					if (*s == c) ++p, ++s;
					else return false;
				}
				// Meets an isolated character different from c. Finish matching c.
				else {
					s = end_s;
					break;
				}
			}
		}
		// Meets a single ordinary character.
		// Simply matching.
		else if (*s == *p) ++s, ++p;
		// Fail to match p and s.
		else return false;
	}

	return true;
}

int main() {
	assert(!isMatch("aa", "a"));
	assert(isMatch("aa", "aa"));
	assert(!isMatch("aaa", "aa"));
	assert(isMatch("aa", "a*"));
	assert(isMatch("aa", ".*"));
	assert(isMatch("ab", ".*"));
	assert(isMatch("aab", "c*a*b"));
	assert(!isMatch("ab", ".*c"));
	assert(isMatch("aaa", "ab*a*c*a"));
	assert(isMatch("a", "ab*"));
	assert(!isMatch("a", ".*..a*"));
	assert(isMatch("aaa", "a*a"));
	assert(!isMatch("acbbcbcbcbaaacaac", "ac*.a*ac*.*ab*b*ac"));
	assert(!isMatch("ababababaacabaabbb", "..*ac*a.a*.c*b*.*bc"));
	assert(isMatch("ab", ".*..c*"));
	assert(isMatch("bbbaccbbbaababbac", ".b*b*.*...*.*c*."));
	assert(isMatch("aaabaaaababcbccbaab", "c*c*.*c*a*..*c*"));
	assert(isMatch("bbbacbaacacaaaba", "b*c*b*.a.*a*.*.*b*"));
	assert(isMatch("a", "c*."));
	assert(!isMatch("aabcacb", ".*ac*a*a*.a..*.*"));
	assert(!isMatch("bbcbbcbcbbcaabcacb", "a*.*ac*a*a*.a..*.*"));

	return 0;
}