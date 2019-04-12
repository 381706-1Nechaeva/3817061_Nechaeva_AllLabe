#include "vector.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_size)
{
	ASSERT_NO_THROW(TMatrix<int> D(3));
}
TEST(TMatrix, throws_when_create_matrix_with_negative_size)
{
	ASSERT_ANY_THROW(TMatrix<int> D(-4));
}
TEST(TMatrix, assign_operator_changes_matrix_size)
{
  TMatrix<int> D(3), F(5);
  D = F;
  EXPECT_EQ(5, D.GetSize());
}
TEST(TMatix, compare_two_matrix)
{
  TMatrix<int> D(3), F(3);

  EXPECT_TRUE(D==F);
  D[1][2] = 5;
  EXPECT_TRUE(D != F);
}
TEST(TMatrix, can_add_two_matrix)
{
  TMatrix<int> D(2), F(2);
  D[0][0] = 1;
  F[0][0] = 3;
  D = D + F;
  EXPECT_EQ(4, D[0][0]);
}
TEST(TMatrix, can_subtraction_two_matrix)
{
  TMatrix<int> D(2), F(2);
  D[0][0] = 1;
  F[0][0] = 3;
  D = D - F;
  EXPECT_EQ(-2, D[0][0]);
}
TEST(TMatrix, throws_when_subtraction_two_matrix_different_size)
{
  TMatrix<int> D(3), F(5);
  ASSERT_ANY_THROW(D - F);
}
TEST(TMatrix, throws_when_added_two_matrix_different_size)
{
  TMatrix<int> D(3), F(5);
  ASSERT_ANY_THROW(D + F);
}
TEST(TMatrix, throws_when_multiply_two_matrix_different_size)
{
  TMatrix<int> D(3), F(5);
  ASSERT_ANY_THROW(D * F);
}
TEST(TMatrix, can_multiply_two_matrix)
{
  TMatrix<int> D(2), F(2), C(2);
  for (int i = 0; i < D.GetSize(); i++)
  {
    for (int j = i; j < D.GetSize(); j++)
        D[i][j] = 2;
  }
  F = D;
  C[0][0] = 4;
  C[0][1] = 8;
  C[1][1] = 4;
  EXPECT_TRUE(C == F*D);
}
TEST(TMatrix, can_to_divide_two_matrix)
{
  TMatrix<float> D(2), F(2), C(2);
  for (int i = 0; i < D.GetSize(); i++)
  {
    for (int j = i; j < D.GetSize(); j++)
      D[i][j] = 2;
  }
  F = D;
  C[0][0] = 1;
  C[0][1] = 0;
  C[1][1] = 1;
  EXPECT_TRUE(C == F / D);
}
TEST(TMatrix, throws_when_divide_two_matrix_different_size)
{
  TMatrix<int> D(3), F(5);
  ASSERT_ANY_THROW(D / F);
}




