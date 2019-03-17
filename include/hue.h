#ifndef HUE_H
#define HUE_H

#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct hue_array_s {
    int32_t size;
    int64_t* p_data;
};
typedef struct hue_array_s hue_array_t;

/**
 * @brief 
 * 
 * @param size 
 * @return hue_array_t* 
 */
hue_array_t* hue_array_new(int32_t size);

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
 */
void hue_array_sort(hue_array_t* p_array);

struct hue_tensor_s {
    double* p_data;
    int32_t* dims;
    int32_t nb_dims;
};
typedef struct hue_tensor_s hue_tensor_t;

/**
 * @brief 
 * 
 * @param nb_dims 
 * @param dims 
 * @return hue_tensor_t* 
 */
hue_tensor_t* hue_tensor_new(int32_t nb_dims, int32_t* dims);

/**
 * @brief 
 * 
 * @param p_tensor 
 */
void hue_tensor_delete(hue_tensor_t* p_tensor);

/**
 * @brief 
 * 
 * @param p_tensor 
 * @param dims 
 * @return double 
 */
double hue_tensor_get(hue_tensor_t* p_tensor, int32_t* dims);

/**
 * @brief 
 * 
 * @param p_tensor 
 * @param dims 
 * @param value 
 * @return double 
 */
double hue_tensor_set(hue_tensor_t* p_tensor, int32_t* dims, double value);

/**
 * @brief 
 * 
 * @param p_tensor 
 */
void hue_tensor_print(hue_tensor_t* p_tensor);

#ifdef __cplusplus
}
#endif

#endif //HUE_H