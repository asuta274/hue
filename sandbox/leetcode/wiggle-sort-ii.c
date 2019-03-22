#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

int32_t quick_select(int32_t* nums, int32_t start, int32_t end, int32_t k) {
    if (end - start == 1) {
        return nums[start];
    }

    int32_t pvt = start;
    int32_t pvt_val = nums[pvt];
    int32_t tmp;
    for (int chk = start + 1; chk < end; chk++) {
        if (nums[chk] <= pvt_val) {
            tmp = nums[chk];
            nums[chk] = nums[++pvt];
            nums[pvt] = tmp;
        }
    }

    tmp = nums[pvt];
    nums[pvt] = nums[start];
    nums[start] = tmp;

    if (k < pvt) {
        return quick_select(nums, start, pvt, k);
    } else if (k > pvt) {
        return quick_select(nums, pvt + 1, end, k);
    } else {
        return nums[pvt];
    }
}

int main() {
    int32_t nums[] = { 5,3,1,2,6,7,8,5,5 };
    int32_t len  = sizeof(nums) / sizeof(int32_t);
    int32_t mid = len / 2;
    int32_t mid_val = quick_select(nums, 0, len, mid);

    int32_t start = 0;
    int32_t end = mid - 1;
    while (end >= 0 && nums[end] == mid_val) {
        end--;
    }

    for (;start < end; start++) {
        if (nums[start] == mid_val) {
            nums[start] = nums[end];
            nums[end--] = mid_val;
        }
    }

    end = mid + 1;
    while (end < len && nums[end] == mid_val) {
        end++;
    }

    for (start = len - 1; start > end; start--) {
        if (nums[start] == mid_val) {
            nums[start] = nums[end];
            nums[end++] = mid_val;
        }
    }


    
    int32_t* tmp_nums = (int32_t*) malloc(len * sizeof(int32_t));
    memcpy(tmp_nums, nums, len * sizeof(int32_t));

    for (int32_t i = 0; i < len; i++) {
        printf("%d\n", nums[i]);
    }

    printf("------ %d\n", mid_val);

    int32_t i = len - 1;
    for (int32_t k = 1; k < len ; i--, k += 2) {
        nums[k] = tmp_nums[i];
    }

    for (int32_t k = 0; k < len; i--, k += 2) {
        nums[k] = tmp_nums[i];
    }

    free(tmp_nums);

    for (int32_t i = 0; i < len; i++) {
        printf("%d\n", nums[i]);
    }
}