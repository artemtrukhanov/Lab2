#include <gtest.h>
#include "MyVector.h"

TEST(Vector, can_create_vector_with_positive_length)
{
    ASSERT_NO_THROW(Vector<int> v(5));
}

TEST(Vector, cant_create_too_large_vector)
{
    ASSERT_ANY_THROW(Vector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(Vector, throws_when_create_vector_with_negative_length)
{
    ASSERT_ANY_THROW(Vector<int> v(-5));
}

TEST(Vector, throws_when_create_vector_with_negative_startindex)
{
    ASSERT_ANY_THROW(Vector<int> v(5, -2));
}

TEST(Vector, can_create_copied_vector)
{
    Vector<int> v(10);

    ASSERT_NO_THROW(Vector<int> v1(v));
}

TEST(Vector, copied_vector_is_equal_to_source_one)
{
    Vector<int> v1(2);
    v1[0] = 2;
    v1[1] = 3;
    Vector<int> v2(v1);

    EXPECT_EQ(v1 == v2, true);
}

TEST(Vector, copied_vector_has_its_own_memory)
{
    Vector<int> v1(5);
    Vector<int> v2(v1);
    v1[0] = 10;

    EXPECT_NE(v1[0], v2[0]);
}

TEST(Vector, can_get_size)
{
    Vector<int> v(4);

    EXPECT_EQ(4, v.Length());
}

TEST(Vector, can_set_and_get_element)
{
    Vector<int> v(4);
    v[0] = 4;

    EXPECT_EQ(4, v[0]);
}

TEST(Vector, throws_when_set_element_with_negative_index)
{
    Vector<int> v(4);

    ASSERT_ANY_THROW(v[-3]);
}

TEST(Vector, throws_when_set_element_with_too_large_index)
{
    Vector<int> v(4);

    ASSERT_ANY_THROW(v[7]);
}

TEST(Vector, can_assign_vector_to_itself)
{
    ASSERT_NO_THROW(Vector<Vector<int> > v());
}

TEST(Vector, can_assign_vectors_of_equal_size)
{
    Vector<int> v1(4);
    Vector<int> v2(4);

    ASSERT_NO_THROW(v2 = v1);
}

TEST(Vector, can_assign_vectors_of_different_size)
{
    Vector<int> v1(4);
    Vector<int> v2(5);

    ASSERT_NO_THROW(v2 = v1);
}

TEST(Vector, compare_equal_vectors_return_true)
{
    Vector<int> v1(2);
    v1[0] = 3;
    v1[1] = 4;

    Vector<int> v2(2);
    v2[0] = 3;
    v2[1] = 4;

    EXPECT_EQ(v1 == v2, true);
}

TEST(Vector, compare_vector_with_itself_return_true)
{
    Vector<int> v1(4);

    EXPECT_EQ(v1 == v1, true);
}

TEST(Vector, vectors_with_different_size_are_not_equal)
{
    Vector<int> v1(4);
    Vector<int> v2(5);

    EXPECT_EQ(v1 == v2, false);
}

TEST(Vector, can_add_scalar_to_vector)
{
    Vector<int> v1(2);
    v1[0] = 1;
    v1[1] = 2;
    Vector<int> v2(2);
    v2[0] = 4;
    v2[1] = 5;
    v1 = v1 + 3;
    EXPECT_EQ(v1, v2);
}

TEST(Vector, can_subtract_scalar_from_vector)
{
    Vector<int> v1(2);
    v1[0] = 5;
    v1[1] = 4;

    Vector<int> v2(2);
    v2[0] = 2;
    v2[1] = 1;

    EXPECT_EQ(v1 - 3, v2);
}

TEST(Vector, can_multiply_scalar_by_vector)
{
    Vector<int> v1(2);
    v1[0] = 5;
    v1[1] = 4;

    Vector<int> v2(2);
    v2[0] = 15;
    v2[1] = 12;

    EXPECT_EQ(v1 * 3, v2);
}

TEST(Vector, can_subtract_vectors_with_equal_size)
{
    Vector<int> v1(5);
    Vector<int> v2(5);

    ASSERT_NO_THROW(v2 - v1);
}

TEST(Vector, cant_subtract_vectors_with_not_equal_size)
{
    Vector<int> v1(5, 3);
    Vector<int> v2(6, 4);

    ASSERT_ANY_THROW(v1 - v2);
}

TEST(Vector, can_multiply_vectors_with_equal_size)
{
    Vector<int> v1(10);
    Vector<int> v2(10);

    ASSERT_NO_THROW(v1 * v2);
}

TEST(Vector, cant_multiply_vectors_with_not_equal_size)
{
    Vector<int> v1(10, 3);
    Vector<int> v2(11, 2);

    ASSERT_ANY_THROW(v1 * v2);
}

