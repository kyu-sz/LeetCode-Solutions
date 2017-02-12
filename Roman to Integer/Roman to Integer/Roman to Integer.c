// Roman to Integer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <assert.h>

int romanToInt(char* s) {
	int res = 0;

#define analyze(lv, lc, sv, sc) \
	while (*s == lc) res += lv, ++s; \
	if (*s == sc && *(s + 1) == lc) res += lv - sv, s += 2;
	
	analyze(1000, 'M', 100, 'C');
	analyze(500, 'D', 100, 'C');
	analyze(100, 'C', 10, 'X');
	analyze(50, 'L', 10, 'X');
	analyze(10, 'X', 1, 'I');
	analyze(5, 'V', 1, 'I');
	analyze(1, 'I', 0, '_');

	return res;
}

int main()
{
	assert(romanToInt("I") == 1);
    return 0;
}

