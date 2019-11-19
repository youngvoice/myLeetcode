#define OUT 0
#define IN 1
int findMaxConsecutiveOnes(int* nums, int numsSize)
{
		int i;
		int state = OUT;
		int count = 0;
		int max_count = 0;
		for (i = 0; i < numsSize; i++) {
				if ((nums[i] == 1) && (state == IN)) {
						count++;
				}
				else if ((nums[i] == 1) && (state == OUT)) {
						count = 1;
						state = IN;

				}
				else;
					
				if (((nums[i] == 0) || (i == (numsSize - 1))) && (state == IN)) {
						if (max_count < count) 
								max_count = count;
						state = OUT;

				}
		}

		return max_count;

}

