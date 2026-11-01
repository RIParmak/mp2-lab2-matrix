#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicMatrix<int> m(5));
}

TEST(TDynamicMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(-5));
}

TEST(TDynamicMatrix, can_create_copied_matrix)
{
  TDynamicMatrix<int> m(5);

  ASSERT_NO_THROW(TDynamicMatrix<int> m1(m));
}

TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one)
{
	size_t a = 10;
	TDynamicMatrix<int> v(a);
	ASSERT_EQ(v, TDynamicMatrix<int>(v));
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
	size_t a = 10;
	TDynamicMatrix<int> v(a);
	TDynamicMatrix<int> z(v);
	v[0][0] = 1; z[0][0] = 2;
	ASSERT_NE(v[0][0],z[0][0]);
}

TEST(TDynamicMatrix, can_get_size)
{
	size_t a = 10;
	TDynamicMatrix<int> v(a);
	ASSERT_EQ(a, v.size());
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
	size_t a = 10;
	TDynamicMatrix<int> v(a);
	v[0][0] = 1;
	ASSERT_EQ(1, v[0][0]);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
	size_t a = 10;
	TDynamicMatrix<int> v(a);
	ASSERT_ANY_THROW(v[-1][-1] = 0);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
	size_t a = 10;
	TDynamicMatrix<int> v(a);
	ASSERT_ANY_THROW(v[a][a] = 0);
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
	size_t a = 10;
	TDynamicMatrix<int> v(a);
	ASSERT_ANY_THROW(v=v);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
	size_t a = 10;
	TDynamicMatrix<int> v(a);
	TDynamicMatrix<int> z(a);
	ASSERT_NO_THROW(z = v);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
	TDynamicMatrix<int> a(5), b(6);
	for (int i = 0; i < 5; i++)
	{
		b[i][0] = i * 10;
	}
	ASSERT_EQ(a.size(), 5);
	a = b;
	ASSERT_EQ(a.size(), 6);
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
	TDynamicVector<int> a(5), b(6);
	for (int i = 0; i < 5; i++)
	{
		a[i] = i * 10;
	}
	ASSERT_NO_THROW(b = a);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
	TDynamicMatrix<int> a(5), b(5);
	ASSERT_EQ(a, b);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
	TDynamicMatrix<int> a(5);
	ASSERT_EQ(a, a);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
	TDynamicMatrix<int> a(5), b(6);
	ASSERT_NE(a, b);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
	TDynamicMatrix<int> a(5), b(5), c(5);
	int i, j;
	for (i = 0; i < 5; i++)
		for (j = i; j < 5; j++)
		{
			a[i][j] = i * 10 + j;
			b[i][j] = (i * 10 + j) * 100;
			c[i][j] = (i * 10 + j) * 100 + i * 10 + j;
		}
	ASSERT_EQ(a + b, c);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
	TDynamicMatrix<int> a(5), b(6);
	ASSERT_ANY_THROW(a + b);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
	TDynamicMatrix<int> a(5), b(5), c(5);
	int i, j;
	for (i = 0; i < 5; i++)
		for (j = i; j < 5; j++)
		{
			a[i][j] = i * 10 + j;
			b[i][j] = (i * 10 + j) * 100;
			c[i][j] = -(i * 10 + j)+((i * 10 + j) * 100);
		}
	ASSERT_EQ(b-a, c);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TDynamicMatrix<int> a(5), b(6);
	ASSERT_ANY_THROW(a - b);
}

