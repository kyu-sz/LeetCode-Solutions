#include <stdio.h>

// In VS2013, bool is not a type of C.
typedef int bool;

bool isValid(char* s) {
	char* stack = malloc(sizeof(char) * 100000);
	int stackTop = 0;
	RESTART:
	switch (*s) {
	case '\0':
		free(stack);
		return !stackTop;
	case '{':
	case '(':
	case '[':
		stack[stackTop++] = *s;
		break;
	case '}':
		if (!stackTop || stack[--stackTop] != '{') return 0;
		break;
	case ')':
		if (!stackTop || stack[--stackTop] != '(') return 0;
		break;
	case ']':
		if (!stackTop || stack[--stackTop] != '[') return 0;
		break;
	}
	++s;
	goto RESTART;
}