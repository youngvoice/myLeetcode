/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void qsort(char v[], int left, int right)
{
		int i, last;
		void swap(char v[], int i, int j);
		if (left >= right)
				return;
		swap(v, left, (left + right)/2);
		last = left;
		for (i = left + 1; i <= right; i++)
				if (v[i] < v[left])
						swap(v, ++last, i);
		swap(v, left, last);
		qsort(v, left, last -1);
		qsort(v, last + 1, right);
}

void swap(char v[], int i, int j)
{
		char temp;

		temp = v[i];
		v[i] = v[j];
		v[j] = temp;
}

#define MAXSTRLEN 20
struct hash_map {
		char key[MAXSTRLEN];
		//single list
		UT_hash_handle hh;



};
char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
		char *s, *t;
		for (i = 0; i < strsSize; i++) {
				s = strs[i];
				t = (char *)malloc((strlen(s) + 1)*sizeof(char));
				strcpy(t, s);
				qsort(t, 0, strlen(t) - 1);
				HASH_FIND_STR();
		}



}

