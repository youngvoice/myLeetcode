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

void ShellInsert(int *nums, int numsSize, int k)
{
    int temp, list_th, i, j;
    for (list_th = 0; list_th < k; list_th++) {
        for (i = 1; list_th +i*k < numsSize; i++) {
            temp = nums[list_th +i*k];
            for (j = i - 1; list_th + j*k >= 0; j--) {
                if (temp < nums[list_th + j*k])
                {
                    /*
                    if (k == 2) {
                        printf("%d  %d\n", nums[list_th + (j+1)*k], list_th + (j+1)*k);
                        printf("%d  %d\n", nums[list_th + j*k], list_th + j*k);
                    }
                    */
                    nums[list_th + (j+1)*k] = nums[list_th + j*k];
                    continue;
                }
                    
                else
                {
                    //nums[list_th + (j+1)*k] = temp;
                    break;
                }
                    
            }
            nums[list_th + (j+1)*k] = temp;
        }
        /*
        printf("k=%d\n", k);
        for (i = 0; i < numsSize; i++) {
        printf("%d  %d\n", i, nums[i]);
        }
        */
    }

}

#define NUM_DLTA 5
void sort(int *nums, int numsSize)
{
    int dlta[NUM_DLTA] = {1, 2, 3, 5, 7};
    int i = 0, k = 0;
    for (i = NUM_DLTA -1; i >= 0; i--) {
        k = dlta[i];
        ShellInsert(nums, numsSize, k);
    }
    

}
