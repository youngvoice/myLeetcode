/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/**
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
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
	int sizeLarger = 1, i = 0;
	int *result;
	for (i = digitsSize - 1; i >= 0; i--) {
		digits[i] = digits[i] + 1;
		// if sum is 10, the carry is occur
		if (digits[i] % 10 == 0) digits[i] = 0;
		else {sizeLarger = 0; break;}
	}

	if (sizeLarger) {
		//result = (int *)malloc(digitsSize + 1);
		result = (int *)malloc((digitsSize + 1)*sizeof(int));
		for (i = digitsSize - 1; i >= 0; i--) {
			result[i+1] = digits[i];
		}
		//result[0] = result[1] / 10;
        result[0] = 1;
		result[1] = result[1] % 10;
	}
	else {
		result = (int *)malloc(digitsSize*sizeof(int));
		for (i = digitsSize - 1; i >= 0; i--) {
			result[i] = digits[i];
		}
	}
	*returnSize = digitsSize + sizeLarger;
	return result;

}

