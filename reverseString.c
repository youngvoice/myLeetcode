void reverseString(char* s, int sSize)
{
		int i = 0, j = sSize - 1;
		int temp;
		if (sSize <= 0)
				return;
		for (i = 0, j = sSize - 1; i < j; i++, j--) {
				temp = s[i];
				s[i] = s[j];
				s[j] = temp;
		}
		return;
}

