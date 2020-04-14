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

void BubbleSort(int *nums, int numsSize)
{
    int i, j, temp;
    bool exchange = true;
    for (i = numsSize -1; i > 0 && exchange; i--) {
        exchange = false;

        for (j = 0; j < i; j++) {
            if (nums[j] > nums[j+1]) {
                exchange = true;
                temp = nums[j+1];
                nums[j+1] = nums[j];
                nums[j] = temp;  
            }
        }
    }

}

void sort(int *nums, int numsSize)
{
    BubbleInsert(nums, numsSize);
}