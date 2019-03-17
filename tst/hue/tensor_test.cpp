#include "gtest/gtest.h"

#include "hue.h"

TEST(tensor_test, new_delete)
{
    int dims[] = {2, 4};
    hue_tensor_t* p_tensor = hue_tensor_new(2, dims);
    EXPECT_EQ(2, p_tensor->nb_dims);
    EXPECT_EQ(2, p_tensor->dims[0]);
    EXPECT_EQ(4, p_tensor->dims[1]);
    hue_tensor_delete(p_tensor);
    EXPECT_TRUE(true);
}