#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicVector<int> v(5));
}

TEST(TDynamicVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TDynamicVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(-5));
}

TEST(TDynamicVector, can_create_copied_vector)
{
  TDynamicVector<int> v(10);

  ASSERT_NO_THROW(TDynamicVector<int> v1(v));
}

TEST(TDynamicVector, copied_vector_is_equal_to_source_one)
{
	TDynamicVector<int> v(10);
	ASSERT_EQ(v, TDynamicVector<int>(v));
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
	TDynamicVector<int>v(10);
	TDynamicVector<int>z(v);
	v[0] = 67;
	z[0] = 52;
	ASSERT_NE(v[0], z[0]);
}

TEST(TDynamicVector, can_get_size)
{
  TDynamicVector<int> v(4);

  EXPECT_EQ(4, v.size());
}

TEST(TDynamicVector, can_set_and_get_element)
{
  TDynamicVector<int> v(4);
  v[0] = 4;

  EXPECT_EQ(4, v[0]);
}

TEST(TDynamicVector, throws_when_set_element_with_negative_index)
{
	TDynamicVector<int> v(4);
	ASSERT_ANY_THROW(v[-1]);
}

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
	TDynamicVector<int> v(4);
	ASSERT_ANY_THROW(v[5] = 1);
}

TEST(TDynamicVector, can_assign_vector_to_itself)
{
	TDynamicVector<int> v(4);
	ASSERT_ANY_THROW(v = v);
}

TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
	TDynamicVector<int> v(4);
	TDynamicVector<int> z(4);
	ASSERT_NO_THROW(z = v);
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
	TDynamicVector<int> a(5), b(6);
	for (int i = 0; i < 5; i++)
	{
		b[i] = i * 10;
	}
	ASSERT_EQ(a.size(), 5);
	a = b;
	ASSERT_EQ(a.size(), 6);
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
	TDynamicVector<int> a(5), b(6);
	for (int i = 0; i < 5; i++)
	{
		a[i] = i * 10;
	}
	ASSERT_NO_THROW(b = a);
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
	TDynamicVector<int> a(5), b(5);
	for (int i = 0; i < 5; i++)
	{
		a[i] = i * 10;
		b[i] = i * 10;
	}
	ASSERT_EQ(a== b,true);
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
	TDynamicVector<int> a(5);
	for (int i = 0; i < 5; i++)
	{
		a[i] = i * 10;
	}
	ASSERT_EQ(a==a,true);
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
	TDynamicVector<int> a(5), b(6);
	for (int i = 0; i < 5; i++)
	{
		a[i] = i * 10;
		b[i] = i * 10;
	}
	ASSERT_NE(a, b);
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
	TDynamicVector<int> a(5), b(5);
	int i = 0, tmp = 2;
	for (i = 0; i < 5; i++)
	{
		a[i] = i * 10;

		b[i] = i * 10 + tmp;
	}
	ASSERT_EQ(a + tmp, b);
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
	TDynamicVector<int> a(5), b(5);
	int i = 0, tmp = 2;
	for (i = 0; i < 5; i++)
	{
		a[i] = i * 10;

		b[i] = i * 10 - tmp;
	}
	ASSERT_EQ(a - tmp, b);
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
	TDynamicVector<int> a(5), b(5);
	int i = 0,tmp=2;
	for (i = 0; i < 5; i++)
	{
		a[i] = i * 10;

		b[i] = i*10*tmp;
	}
	ASSERT_EQ(a *tmp, b);
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
	TDynamicVector<int> a(5), b(5), c(5);
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		a[i] = i * 10;

		b[i] = (i * 10) * 100;
		c[i] = i * 10 + i * 10 * 100;
	}
	ASSERT_EQ(a + b, c);
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
	TDynamicMatrix<int> a(5), b(6);
	ASSERT_ANY_THROW(a + b);
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
	TDynamicVector<int> a(5), b(5),c(5);
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		a[i] = i * 10;

		b[i] = (i * 10) * 100;
		c[i] = i * 10 - i * 10 * 100;
	}
	ASSERT_EQ(a - b, c);
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
	TDynamicMatrix<int> a(5), b(6);
	ASSERT_ANY_THROW(a - b);
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
	TDynamicVector<int> a(5), b(5);
	int tmp = 0;
	int i = 0;
	for (i = 0; i < 5; i++)
		{
			a[i] = i * 10 ;
			b[i] = (i * 10 ) * 100;
			tmp += i * 10 * i * 10 * 100;
		}
	ASSERT_EQ(a * b,300000);
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
	TDynamicVector<int> a(5), b(6);
	ASSERT_ANY_THROW(a * b);
}

