#include <stdio.h>
int pivotIndex(int* nums, int numsSize){
    if (numsSize < 3) {
        return -1;
    }
    int index, i;
    for (index = 0; index < numsSize; index++) {
    	int sumPre = 0, sumLat = 0;
        for (i = 0; i < index; i++)
            sumPre += nums[i];
        for (i = index + 1; i < numsSize; i++)
            sumLat += nums[i];
        if (sumPre == sumLat)
            return index;
    }
    return -1;

}

int main()
{
		int nums[] = {1, 7, 3, 6, 5, 6};
		printf("pivot index is %d\n", pivotIndex(nums, sizeof(nums)/sizeof(int)));
		return 0;
}
