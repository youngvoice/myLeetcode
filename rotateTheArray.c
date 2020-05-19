void reverse(int *nums, int left, int right);
void rotate(int* nums, int numsSize, int k)
{
	k = k % numsSize;
	reverse(nums, 0, numsSize - 1);
	reverse(nums, 0, k - 1);
	reverse(nums, k, numsSize - 1);
}
void reverse(int *nums, int left, int right)
{
	int temp;
	while (left < right) {
		
		temp = nums[left];
		nums[left] = nums[right];
		nums[right] = temp;
		left++;
		right--;
	}
}



