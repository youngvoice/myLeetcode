void swap(int i, int j, char *s);
char * reverseWords(char * s)
{
		int size = 0;
		char *ss = s;
		int i, j, k;
		while (*ss++)
				size++;
		i = 0;
		j = -2;
		for (k = 0; k < size; k++) {
				if (s[k] == ' ' || k == size - 1) {
						i = j + 2;
						if (k == size - 1)
								j = k;
						else 
								j = k - 1;
						swap(i, j, s);
				}



		}
		return s;
}

void swap(int i, int j, char *s)
{
		char temp;
		for (; i < j; i++, j--) {
				temp = s[i];
				s[i] = s[j];
				s[j] = temp;
		}
}
