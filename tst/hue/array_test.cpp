#include "gtest/gtest.h"
#include "hue.h"

TEST(array_test, basic_test)
{
    EXPECT_TRUE(true);
}

TEST(array_test, grow_test)
{
    hue_array_t* p_array = hue_array_new();
    for (int32_t i = 0; i < 33; i++) {
        hue_array_append(p_array, i);
    }

    for (int32_t i = 0; i < 33; i++) {
        int64_t value = hue_array_get(p_array, i);
        EXPECT_EQ(i, value);
    }
}

TEST(array_test, sort_test)
{
    hue_array_t* p_array = hue_array_new();
    for (int32_t i = 0; i < 33; i++) {
        hue_array_append(p_array, 33 - i - 1);
    }

    hue_array_sort(p_array);

    for (int32_t i = 0; i < 33; i++) {
        int64_t value = hue_array_get(p_array, i);
        EXPECT_EQ(i, value);
    }

    hue_array_t* p_array2 = hue_array_new();
    int64_t values[] = { 10, 8, 12, 6 };
    int64_t expected[] = { 6, 8, 10, 12 };
    int32_t len = 4;
    for (int32_t i = 0; i < len; i++) {
        hue_array_append(p_array2, values[i]);
    }
    hue_array_sort(p_array2);
    for (int32_t i = 0; i < len; i++) {
        int64_t value = hue_array_get(p_array2, i);
        EXPECT_EQ(expected[i], value);
    }
}