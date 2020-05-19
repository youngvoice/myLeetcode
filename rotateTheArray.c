void rotate(int* nums, int numsSize, int k)
{
	
	int s = 0;
	int count = 0;
	int i = -1;
	int index = -1;
	int next, orignal;
	if (numsSize <= 1)	return ;
	while (count < numsSize) {
		index = (i + s*k)%numsSize;
		if (index == i) {
			i++;
			s = 0;
			orignal = nums[(i + s*k)%numsSize];
			index = (i + s*k)%numsSize;
		}

		next = nums[(index + k)%numsSize];
		printf("%d %d\n",orignal, next);
		nums[(index + k)%numsSize] = orignal;
		count++;
	
		orignal = next;
		s++;
	}
}



