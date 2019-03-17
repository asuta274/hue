#ifndef HUE_ARRAY_H
#define HUE_ARRAY_H

#include "hue/base.h"

#define HUE_ARRAY_INIT_SIZE         16;

struct hue_array_s {
    int32_t size;
    int32_t capacity;
    int64_t* p_data;
};
typedef struct hue_array_s hue_array_t;

/**
 * @brief 
 * 
 * @param size 
 * @return hue_array_t* 
 */
hue_array_t* hue_array_new();

/**
 * @brief 
 * 
 * @param p_array 
 */
void hue_array_delete(hue_array_t* p_array);

/**
 * @brief 
 * 
 * @param p_array 
 * @param index 
 * @return int64_t 
 */
int64_t hue_array_remove(hue_array_t* p_array, int32_t index);

/**
 * @brief 
 * 
 * @param p_array 
 * @param index 
 * @param value 
 */
void hue_array_insert(hue_array_t* p_array, int32_t index, int64_t value);

/**
 * @brief 
 * 
 * @param p_array 
 * @param value 
 */
void hue_array_append(hue_array_t* p_array, int64_t value);

/**
 * @brief 
 * 
 * @param p_array 
 * @param index 
 * @return int64_t 
 */
int64_t hue_array_get(hue_array_t* p_array, int32_t index);

void hue_array_sort(hue_array_t* p_array);



#endif //HUE_ARRAY_H