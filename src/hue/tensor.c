#include "hue.h"

hue_tensor_t* hue_tensor_new(int32_t nb_dims, int32_t* dims) {
    int32_t size = sizeof(hue_tensor_t) + sizeof(int32_t) * nb_dims;
    int32_t data_size = 1;
    for (int32_t i = 0; i < nb_dims; i++) {
        data_size *= dims[i];
    }
    size += data_size;
    hue_tensor_t* p_tensor = (hue_tensor_t*) malloc(size);

    p_tensor->nb_dims = nb_dims;
    p_tensor->dims = (int32_t*) (p_tensor + 1);
    memcpy(p_tensor->dims, dims, nb_dims * sizeof(int32_t));
    p_tensor->p_data = (double*) (p_tensor->dims + p_tensor->nb_dims);
    
    return p_tensor;
}

void hue_tensor_delete(hue_tensor_t* p_tensor) {
    free(p_tensor);
}