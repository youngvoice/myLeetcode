void swap(int i, int j, int *nums);
void moveZeroes(int* nums, int numsSize)
{
		int i,j,k,t;
		for (i = numsSize - 1; i >= 0; i--) {
				if (nums[i] != 0) {
						k = i;
						break;
				}
		}
		for (i = k - 1; i >= 0; i--) {
				if (nums[i] == 0) {
						j = i;
						for (t = 0; t < k - j; t++)
								swap(j+t, j+1+t, nums);
						k--;
				}
		}
}
/*
int nums[] = {0, 3, 12};
int numsSize = 3;
void main()
{
		int i,j,k,t;
		for (i = numsSize - 1; i >= 0; i--) {
				if (nums[i] != 0) {
						k = i;
						break;
				}
		}
		for (i = k - 1; i >= 0; i--) {
				if (nums[i] == 0) {
						j = i;
						for (t = 0; t < k - j; t++)
								swap(j+t, j+1+t, nums);
						k--;
				}
		}
}
*/

void swap(int i, int j, int *nums)
{
		int temp;
		temp = nums[i];
		nums[i] = nums[j];
		nums[j] = temp;
}
