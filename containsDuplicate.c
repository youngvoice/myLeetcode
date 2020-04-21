/*
#include <stdio.h>
#include <stdlib.h>
void sort(int *nums, int numsSize);
enum bool {false, true};
*/
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

void Merge(int *sr, int *tr, int i, int m, int n)
{
    // sorted sr[i..m] and sorted sr[m+1..n]   ----> tr[i..n]
    int j, k;
    for (j=m+1, k = i; i <= m && j <= n; ++k) {
        if (sr[i] < sr[j]){
            tr[k] = sr[i++];
        }
        else{
            tr[k]= sr[j++];
        }

    }
    if (i <= m) {
        //for (k++; i <= m; i++, k++)
        for (; i <= m; i++, k++)
        {
            
            tr[k]= sr[i];
        }
            
    }
    if (j <= n) {
        for (; j <=n; j++)
        {
            //k++;
            tr[k] = sr[j];
        }
    }
}

void MSort(int *sr, int *tr1, int s, int t, int numsSize)
{
    if (s==t) tr1[s]=sr[s];
    else {
        
        int m = (s+t)/2;
        //int *tr2 = (int *)malloc((t-s+1)*sizeof(int));
        int *tr2 = (int *)malloc(numsSize*sizeof(int));
        MSort(sr, tr2, s, m, numsSize);
        MSort(sr, tr2, m+1, t, numsSize);
        Merge(tr2, tr1, s, m, t);  
        free(tr2);
        tr2 = NULL;
    }
}

void MergeSort(int *nums, int numsSize)
{
    int *tr = (int *)malloc(numsSize*sizeof(int));
    MSort(nums, tr, 0, numsSize -1, numsSize);
    for (int i = 0; i < numsSize; i++) {
        nums[i] = tr[i];
    }
    free(tr);
    tr = NULL;
}

void sort(int *nums, int numsSize)
{
    MergeSort(nums, numsSize);
}

/*
int main()
{
	int nums[]={1, 2, 3, 4};
	containsDuplicate(nums, 4);
}

*/
