void sort(int *nums, int numsSize);
bool containsDuplicate(int* nums, int numsSize){
    if (numsSize < 2) return false;
    sort(nums, numsSize);
    int i;
    //for (i = 0; i < numsSize; i++)
    //    printf("%d ", nums[i]);
    for (i = 0; i < numsSize -1; i++) {
        if (nums[i] == nums[i+1]) {
            return true;
        }
    }
    return false;
}

void sort(int *nums, int numsSize)
{

    int *nums_guard = (int *)malloc((numsSize+1)*sizeof(int));
    nums_guard[0] = 0;
    int i,j;
    for (i = 1; i < numsSize+1; i++) {
        nums_guard[i] = nums[i-1];
        //printf("\n");
        //printf("i=%d  %d ",i,nums_guard[i]);
    }
    
    for (i = 2; i < numsSize+1; i++) {
	    nums_guard[0] = nums_guard[i];
	    for (j = i - 1; j >= 0; j--) {
		    if (nums_guard[0] < nums_guard[j]) {
			    nums_guard[j + 1] = nums_guard[j];
			    continue;
		    }
            else {
                nums_guard[j+1] = nums_guard[0];
                break;
            }
		    
	    }
    }

    for (i = 1; i < numsSize+1; i++) {
	    nums[i-1] = nums_guard[i];
        //printf("\n");
        //printf("i=%d  %d ",i,nums_guard[i]);
    }
    free(nums_guard);
    nums_guard = NULL;
}
