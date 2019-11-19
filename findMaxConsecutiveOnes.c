#define OUT 0
#define IN 1
int findMaxConsecutiveOnes(int* nums, int numsSize)
{
		int i, j;
		int state = OUT;
		int max_count = 0;
		i = 0;
		int p, q;
		for (i = 0; i < numsSize; i++) {
				if ((nums[i] == 1) && ((state == OUT) || (i == 0))) {
						p = i;
						state = IN;

				}

				if (((nums[i] == 0) || (i == (numsSize - 1))) && (state == IN)) {
						if (i == (numsSize - 1) && (nums[i] == 1))
								i++;
						q = i;
						state = OUT;
						if ((q - p) > max_count)
								max_count = q - p;
				}
		}
		return max_count;

}
/*
int main()
{
		int numsSize = 1;
		int nums[1];
		int i, j;
		int state = OUT;
		int max_count = 0;
		i = 0;
		int p, q;
		nums[0] = 1;
		for (i = 0; i < numsSize; i++) {
				if ((nums[i] == 1) && ((state == OUT) || (i == 0))) {
						p = i;
						state = IN;

				}

				if (((nums[i] == 0) || (i == (numsSize - 1))) && (state == IN)) {
						if (i == (numsSize - 1))
								i++;
						q = i;
						state = OUT;
						if ((q - p) > max_count)
								max_count = q - p;
				}
		}
		return max_count;

}
*/
