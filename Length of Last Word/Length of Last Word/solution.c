int lengthOfLastWord(char* s) {
	int len = 0, flag = 0;
	while (*s)
		if (*(s++) == ' ')
			flag = 1;
		else
			if (flag)
				flag = 0, len = 1;
			else
				++len;
	return len;
}