/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
		int i,sum;
		int carry = 1, overFlag = 0;
		int *resultDigits;

		for (i = digitsSize; i > 0; i--)
		{
				sum = carry + digits[i-1];
				carry = 0;
				if (sum >= 10)
				{
						if (i == 1)
								overFlag = 1;
						carry = sum / 10;
						sum = sum % 10;
				}
				digits[i-1] = sum;
		}
		if (overFlag)
		{
				*returnSize = digitsSize + 1; 
				resultDigits = (int *)malloc(*returnSize *sizeof(int));
				for (i = digitsSize; i > 0; i--)
						resultDigits[i] = digits[i - 1];
				resultDigits[i] = carry;
		}
		else
		{

				*returnSize = digitsSize; 
				resultDigits = (int *)malloc(*returnSize *sizeof(int));
				for (i = digitsSize; i > 0; i--)
						resultDigits[i-1] = digits[i-1];
		}

		return resultDigits;

}

