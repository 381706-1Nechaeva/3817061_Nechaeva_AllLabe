#include "vector.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
	ASSERT_NO_THROW( TVector<int> D;);
}
TEST(TVector, throws_when_create_vector_with_negative_length)
{
	ASSERT_ANY_THROW(TVector<int> D(-5););
}
TEST(TVector, throws_when_create_vector_with_negative_firstindex)
{
	ASSERT_ANY_THROW(TVector<int> D(5,-5););
}
TEST(TVector, can_get_size)
{
	TVector<int> D(17);
	EXPECT_EQ(17, D.GetSize());
}
TEST(TVector, can_get_firstindex)
{
	TVector<int> D(17,3);
	EXPECT_EQ(3, D.GetFirstInd());
}
TEST(TVector, throws_when_create_vector_with_large_firstindex_then_size)
{
	ASSERT_ANY_THROW(TVector<int> D(5, 6););
}
TEST(TVector, throws_when_output_vector_with_negative_index)
{
	TVector<int> D(3);
	ASSERT_ANY_THROW(cout << D[-3];);
}
TEST(TVector, throws_when_output_vector_with_large_index)
{
	TVector<int> D(3);
	ASSERT_ANY_THROW(cout << D[3];);
}
TEST(TVector, can_create_zero_vector)
{
	TVector<int> D(3);
	for(int i = 0; i < D.GetSize(); i++)
	EXPECT_EQ(0,D[i]);
}
TEST(TVector, assign_operator_changes_vector_size)
{
	TVector<int> D(3),F(5);
	D = F;
	EXPECT_EQ(5, D.GetSize());
}
TEST(TVector, correctness_of_the_comparison_operators_with_different_size_of_vectors)
{
	TVector<int> D(3), F(5);
	EXPECT_EQ(0, D==F);
	EXPECT_EQ(1, D != F);
}
TEST(TVector, correctness_of_the_comparison_operators)
{
  TVector<int> D(3), F(D);
  EXPECT_TRUE(D == F);
  D[1] = 5;
  EXPECT_TRUE(D != F);
}
TEST(TVector, can_add_scalar)
{
	TVector<int> D(3);
	D = D + 3;
	EXPECT_EQ(3, D[1]);
	EXPECT_NE(2, D[0]);
}
TEST(TVector, can_subtract_scalar)
{
	TVector<int> D(3);
	D = D - 3;
	EXPECT_EQ(-3, D[1]);
	EXPECT_NE(0, D[0]);
}
TEST(TVector, can_multiply_by_a_scalar)
{
	TVector<int> D(3);
	D[0] = 2;
	D = D * 3;
	EXPECT_EQ(6, D[0]);
}
TEST(TVector, can_add_two_vectors)
{
	TVector<int> D(3),F(D);
	for (int i = 0; i < D.GetSize(); i++) 
	{
		D[i] = i;
		F[i] = i;
	}
	F = D + F;
	for (int j = 0; j < F.GetSize(); j++)
		EXPECT_EQ(2 * j, F[j]);
}
TEST(TVector, can_subtraction_two_vectors)
{
	TVector<int> D(3), F(D);
	for (int i = 0; i < D.GetSize(); i++)
	{
		D[i] = i;
		F[i] = i;
	}
	F = D - F;
	for (int j = 0; j < F.GetSize(); j++)
		EXPECT_EQ(0, F[j]);
}
TEST(TVector, throws_when_subtraction_two_vectors_different_size)
{
	TVector<int> D(3), F(5);
	ASSERT_ANY_THROW(D-F);
}
TEST(TVector, throws_when_added_two_vectors_different_size)
{
	TVector<int> D(3), F(5);
	ASSERT_ANY_THROW(D + F);
}
TEST(TVector, throws_when_multiply_two_vectors_different_size)
{
	TVector<int> D(3), F(5);
	ASSERT_ANY_THROW(D * F);
}
TEST(TVector, can_multiply_two_vectors)
{
	TVector<int> D(3), F(3);
	int c;
	
	for (int i = 0; i < D.GetSize(); i++)
	{
		D[i] = i;
		F[i] = i;
	}
    c = D * F;
	EXPECT_EQ(5, c);
}








