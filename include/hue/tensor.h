#ifndef HUE_TENSOR_H
#define HUE_TENSOR_H

#include "hue/base.h"

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

#endif //HUE_TENSOR_H