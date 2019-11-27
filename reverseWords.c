#define OUT 0
#define IN 1
void swap(int i, int j, char *s);
char * reverseWords(char * s)
{
		int i, j;
		int size = 0;
		char temp;
		int state;
		int k;
		char *ss = s;
		char *rets;
		char pre;
		while (*ss) {
				size++;
				ss++;
		}
		rets = (char *)malloc((size+1)*sizeof(char));
		if (size == 0) {
				rets[0] = '\0';
				return rets;
		}
		for (i = 0; i < size; i++) {
				if (s[i] != ' ')
						break;
				if (i == (size - 1)) {

						rets[0] = '\0';
						return rets;
				}


		}
		

		for (i = 0, j = size - 1; i < j; i++, j--) {
				temp = s[i];
				s[i] = s[j];
				s[j] = temp;
		}


		state = OUT;
		for (k = 0; k < size; k++) {
				if (s[k] != ' ' && state == OUT) {
						i = k;
						state = IN;
				}
				if ((s[k] == ' ' || (k + 1 == size) )&& state == IN) {
						if (s[k] == ' ')
								j = k - 1;
						else
								j = k;
						swap(i, j, s);
						state = OUT;
				}

		}

		i = 0;
		pre = ' ';
		for (k = 0; k < size; k++) {
				if (s[k] != ' ') {
						rets[i] = s[k];
						i++;
				}
				else {
						if (pre != ' ') {
								rets[i] = s[k];
								i++;
						}


				}
				pre = s[k];

		}
		if (rets[i - 1] == ' ')
				rets[i - 1] = '\0';
		rets[i] = '\0';

		return rets;


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
