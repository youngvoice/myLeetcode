void swap(int v[], int i, int j)
{
		int temp;
		temp = v[i];
		v[i] = v[j];
		v[j] = temp;
}
/* sort v[left]...v[right] into increasing order */
void qsortt(int v[], int left, int right)
{
		int i, last;
		if (left >= right)
				return;
		swap(v, left, (left + right)/2);
		last = left;
		for (i = left + 1; i <= right; i++)
				if (v[i] < v[left])
						swap(v, ++last, i);

		swap(v, left, last);

		qsortt(v, left, last - 1);
		qsortt(v, last + 1, right);
}
int arrayPairSum(int* nums, int numsSize)
{
		int sum = 0;
		qsortt(nums, 0, numsSize - 1);
		for (int i = 0; i < (numsSize - 1); i=i+2) {
				sum += nums[i];
		}
		return sum;
}
