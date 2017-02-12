#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define check(lv, lc, sv, sc) \
while (num >= lv) *p++ = lc, num -= lv; \
if (num >= lv - sv) { \
	*p++ = sc; \
    *p++ = lc; \
	num -= lv - sv; \
}

char* intToRoman(int num) {
	char* res = (char *)malloc(1000);
	char* p = res;
	
	check(1000, 'M', 100, 'C');
	check(500, 'D', 100, 'C');
	check(100, 'C', 10, 'X');
	check(50, 'L', 10, 'X');
	check(10, 'X', 1, 'I');
	check(5, 'V', 1, 'I');
	check(1, 'I', 0, '_');

	*p = '\0';
	return res;
}

int main() {
	assert(!strcmp(intToRoman(1), "I"));
	assert(!strcmp(intToRoman(2), "II"));
	assert(!strcmp(intToRoman(4), "IV"));
	assert(!strcmp(intToRoman(8), "VIII"));
	assert(!strcmp(intToRoman(16), "XVI"));
	assert(!strcmp(intToRoman(99), "XCIX"));
	assert(!strcmp(intToRoman(800), "DCCC"));
	assert(!strcmp(intToRoman(1437), "MCDXXXVII"));
	assert(!strcmp(intToRoman(3333), "MMMCCCXXXIII"));
	return 0;
}