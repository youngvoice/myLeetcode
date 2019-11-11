#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int strStr(char * haystack, char * needle){
		int haystack_len, needle_len, diff_len;
		int i, j;
		haystack_len = strlen(haystack);
		needle_len = strlen(needle);
		diff_len = haystack_len - needle_len;

		
		if (diff_len < 0)
				return -1;
		if (*needle == '\0')
				return 0;

		for (i = 0; i <= diff_len; i++) {
				for (j = 0; j < needle_len; j++)
						if (*(haystack + i + j) != *(needle + j))
								break;
				if (j == needle_len)
						break;
		}
		if (i == diff_len + 1)
				return -1;
		else
				return i;
    

}

