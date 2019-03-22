#include <stdio.h>
#include <stdint.h>

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
    int32_t nums[] = {10, 100, 1000, 3, 7, 12, 35, 49};
    int32_t len  = sizeof(nums) / sizeof(int32_t);
    for (int32_t i = 0; i < len; i++) {
        printf("%d\n", quick_select(nums, 0, len, i));
    }
}