char * longestCommonPrefix(char ** strs, int strsSize){
		char sameFlag;
		int minStrLen;
		int j, i;
		char *comStr;
		int *strsLen;
		char *empty;
		if (!(strsSize > 0)) {
				empty = (char *)malloc(sizeof(char));
				*empty = '\0';
				return empty;
		}
	    strsLen	= (int *)malloc(strsSize*sizeof(int)); 
		for (i = 0; i < strsSize; i++) {
				strsLen[i] = strlen(strs[i]);
		}
		minStrLen = strsLen[0];
		for (i = 0; i < strsSize; i++) {
				if (minStrLen > strsLen[i])
						minStrLen = strsLen[i];
		}
		comStr = (char *)malloc((minStrLen + 1)*sizeof(char));

		for (i = 0; i < (minStrLen + 1); i++)
				comStr[i] = '\0';

		for (i = 0; i < minStrLen; i++) {
				sameFlag = 1;
				for (j = 1; j < strsSize; j++) {
						if (strs[0][i] != strs[j][i]) {
								sameFlag = 0;
								break;
						}
				}
				if (sameFlag) {
						comStr[i] = strs[0][i];
				}
				else 
						break;
		}
		return comStr;



}

