int dominantIndex(int* nums, int numsSize){
    int i, max = 0, maxIndex=0;
    for (i = 0; i < numsSize; i++)
        if (nums[i] > max) {
            max = nums[i];
            maxIndex = i;
        }
            
    for (i = 0; i < numsSize; i++)
        if (i != maxIndex)
        {
            if (2*nums[i] > max)
                return -1;
            else
                continue;
        }
        else 
            continue;
    return maxIndex;

}
