#include "hue.h"

hue_array_t* hue_array_new() {
    hue_array_t* p_array = (hue_array_t*) malloc(sizeof(hue_array_t));
    p_array->capacity = HUE_ARRAY_INIT_SIZE;
    p_array->size = 0;
    p_array->p_data = (int64_t*) malloc(p_array->capacity * sizeof(int64_t));
    return p_array;
}

void hue_array_delete(hue_array_t* p_array) {
    free(p_array->p_data);
    free(p_array);
}

void hue_array_grow(hue_array_t* p_array) {
    int64_t* p_old_data = p_array->p_data;
    int32_t old_capacity = p_array->capacity;
    p_array->capacity *= 2;
    p_array->p_data = (int64_t*) malloc(p_array->capacity * sizeof(int64_t));
    memmove(p_array->p_data, p_old_data, old_capacity * sizeof(int64_t));
    free(p_old_data);
}

int64_t hue_array_remove(hue_array_t* p_array, int32_t index) {
    assert(index < p_array->size);
    int64_t value = p_array->p_data[index];
    memmove(p_array->p_data + index, p_array->p_data + index + 1, (p_array->size - index - 1) * sizeof(int64_t));
    p_array->size--;
    return value;
}

void hue_array_insert(hue_array_t* p_array, int32_t index, int64_t value) {
    assert(index < p_array->size);
    if (p_array->size == p_array->capacity) {
        hue_array_grow(p_array);
    }
    memmove(p_array->p_data + index + 1, p_array->p_data + index, (p_array->size - index) * sizeof(int64_t));
    p_array->size++;
    p_array->p_data[index] = value;
}

void hue_array_append(hue_array_t* p_array, int64_t value) {
    if (p_array->size == p_array->capacity) {
        hue_array_grow(p_array);
    }
    p_array->p_data[p_array->size++] = value;
}

int64_t hue_array_get(hue_array_t* p_array, int32_t index) {
    assert(index < p_array->size);
    return p_array->p_data[index];
}

void hue_array_quick_sort(int64_t* arr, int32_t lo, int32_t hi) {
    if (lo >= hi) {
        return;
    }

    int64_t pvt_val = arr[lo];
    int64_t tmp;
    int32_t pvt = lo;
    for (int32_t chk = lo + 1; chk < hi; chk++) {
        if (arr[chk] <= pvt_val) {
            pvt++;
            HUE_SWAP_INT64(arr[chk], arr[pvt]);
        }
    }
    HUE_SWAP_INT64(arr[pvt], arr[lo]);

    hue_array_quick_sort(arr, lo, pvt);
    hue_array_quick_sort(arr, pvt + 1, hi);
}

void hue_array_sort(hue_array_t* p_array) {
    hue_array_quick_sort(p_array->p_data, 0, p_array->size);
}