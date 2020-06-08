/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/**
 * optimize:
 * case 1: The array is sorted
 * case 2: The size of nums1 if smaller than nums2
 */

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
	int nums3Size = nums1Size, markSize = nums2Size;
	int i = 0, j = 0, k = 0;
    

	int *nums3 = (int *)malloc(nums3Size*sizeof(int));
	int *mark = (int *)malloc(markSize*sizeof(int));
	//memset(mark, markSize*sizeof(int),0); // can't work, why ???
    for (j = 0; j < markSize; j++)
        mark[j] = 0;
	for (i = 0; i < nums3Size; i++)
		for (j = 0; j < markSize; j++) {
            #printf("%d  %d\n", nums1[i], nums2[j]);
			if (nums1[i] == nums2[j] && mark[j] == 0) {
			    
                mark[j] = 1;
				nums3[k++] = nums1[i];
				break;
			}
		}
	free(mark);
    *returnSize = k;
	return nums3;
}