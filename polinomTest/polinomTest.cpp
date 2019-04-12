#include "polinom.h"
#include <gtest.h>

TEST(TMonom, can_create_monom1)
{
  ASSERT_NO_THROW(TMonom A);
}
TEST(TMonom, can_create_monom2)
{
  int deg[] = { 2,4 ,5 };
  ASSERT_NO_THROW(TMonom A(deg, 4, 3));
}
TEST(TMonom, throw_when_create_monom_with_negavive_count)
{
  int deg[] = { 2,4 ,5 };
  ASSERT_ANY_THROW(TMonom A(deg,4,-5));
}
TEST(TMonom, throw_when_create_monom_with_negavive_deg)
{
  int deg[] = { -2,4 ,5 };
  ASSERT_ANY_THROW(TMonom A(deg, 4, 3));
}
TEST(TMonom, can_copy_monom)
{
  TMonom B;
  ASSERT_NO_THROW(TMonom A(B));
}
TEST(TMonom, can_set_and_get_next)
{
  TMonom B,A;
  ASSERT_NO_THROW(B.SetNext(&A));
  EXPECT_EQ(B.GetNext(), &A);
}
TEST(TMonom, can_set_and_get_deg)
{
  TMonom B;
  int deg[] = { 3,4,5,6 };
  ASSERT_NO_THROW(B.SetDeg(deg));
  EXPECT_EQ(B.GetDeg()[0], deg[0]);
  EXPECT_EQ(B.GetDeg()[1], deg[1]);
  EXPECT_EQ(B.GetDeg()[2], 5);
  EXPECT_EQ(B.GetDeg()[3], 6);
}
TEST(TMonom, can_set_and_get_koeff)
{
  TMonom B;
  ASSERT_NO_THROW(B.SetKoef(3));
  EXPECT_EQ(B.GetKoeff(), 3);
}
TEST(TMonom, can_set_and_get_count)
{
  TMonom B;
  ASSERT_NO_THROW(B.SetCount(3));
  EXPECT_EQ(B.GetCount(), 3);
}
TEST(TMonom, can_add_two_monoms)
{
  int deg[] = { 3,2 };
  TMonom B(deg, 4, 2), C(deg, 3, 2);
  B += C;
  EXPECT_EQ(7, B.GetKoeff());
}
TEST(TMonom, throw_when_add_two_different_monoms)
{
  int deg[] = { 3,2 };
  int deg1[] = { 3 };
  TMonom B(deg, 4, 2), C(deg1, 3, 1);
  ASSERT_ANY_THROW(B += C);
}
TEST(TMonom, can_substract_two_monoms)
{
  int deg[] = { 3,2 };
  TMonom B(deg, 4, 2), C(deg, 3, 2);
  B -= C;
  EXPECT_EQ(1, B.GetKoeff());
}
TEST(TMonom, throw_when_substract_two_different_monoms)
{
  int deg[] = { 3,2 };
  int deg1[] = { 3 };
  TMonom B(deg, 4, 2), C(deg1, 3, 1);
  ASSERT_ANY_THROW(B -= C);
}
TEST(TMonom, can_multiply_two_monoms)
{
  int deg[] = { 3,2 };
  TMonom B(deg, 4, 2), C(deg, 3, 2);
  B *= C;
  EXPECT_EQ(12, B.GetKoeff());
  EXPECT_EQ(B.GetDeg()[0], 2*deg[0]);
  EXPECT_EQ(B.GetDeg()[1], 2*deg[1]);
}
TEST(TMonom, throw_when_multiply_two_different_monoms)
{
  int deg[] = { 3,2 };
  int deg1[] = { 3 };
  TMonom B(deg, 4, 2), C(deg1, 3, 1);
  ASSERT_ANY_THROW(B *= C);
}
TEST(TMonom, assign_operator_monom_works_correct)
{
  int deg[] = { 3,2 };
  int deg1[] = { 3 };
  TMonom B(deg, 4, 2), C(deg1, 3, 1);
  C = B;
  EXPECT_EQ(C.GetDeg()[0], deg[0]);
  EXPECT_EQ(C.GetDeg()[1], deg[1]);
  EXPECT_EQ(C.GetKoeff(), 4);
  EXPECT_EQ(C.GetCount(), 2);
}
TEST(TMonom, can_equivalence_monoms)
{
  int deg[] = { 3,2 };
  int deg1[] = { 3,2 };
  int deg2[] = { 3,1 };
  TMonom B(deg, 4, 2), C(deg1, 3, 2), D(deg2, 7, 2);
  ASSERT_TRUE(B == C);
  ASSERT_FALSE(B == D);
}
TEST(TMonom, throws_when_equivalence_monoms_with_different_count)
{
  int deg[] = { 3,2 };
  int deg1[] = { 3};
  TMonom B(deg, 4, 2), C(deg1, 3, 1);
  ASSERT_ANY_THROW(B == C);
}
TEST(TMonom, can_compare_monoms)
{
  int deg[] = { 3,2 };
  int deg1[] = { 1,2 };
  int deg2[] = { 4,1 };
  TMonom B(deg, 4, 2), C(deg1, 3, 2), D(deg2, 7, 2);
  ASSERT_TRUE(B > C);
  ASSERT_TRUE(B < D);
  ASSERT_FALSE(C > D);
}
TEST(TMonom, throws_when_compare_monoms_with_different_count_or_same_monoms)
{
  int deg[] = { 3,2 };
  int deg1[] = { 3,2 };
  int deg2[] = { 4 };
  TMonom B(deg, 4, 2), C(deg1, 3, 2), D(deg2, 7, 1);
  ASSERT_ANY_THROW(B > C);
  ASSERT_ANY_THROW(B < D);
}

TEST(TPolynom, can_create_polynom)
{
  ASSERT_NO_THROW(TPolynom A(3));
}
TEST(TPolynom, throw_when_create_polynom_with_negavive_count)
{
  ASSERT_ANY_THROW(TPolynom A(-5));
}
TEST(TPolynom, can_copy_polynom)
{
  TPolynom B(3);
  ASSERT_NO_THROW(TPolynom A(B));
}
TEST(TPolynom, can_get_size_of_polynom)
{
  TPolynom B(4);
  TMonom A;
  EXPECT_EQ(0, B.GetSize());
  B.Put(A);
  EXPECT_EQ(1, B.GetSize());
}
TEST(TPolynom, can_get_begin_of_polynom)
{
  TPolynom B(4);
  int deg[] = { 3,2,4, 5 };
  int deg1[] = { 1,2,4, 5 };
  TMonom A(deg1, 4, 4), D(deg,4,4);
  B.Put(A);
  B.Put(D);
  TMonom* temp = B.GetBegin();
  ASSERT_TRUE(*temp==D);
}
TEST(TPolynom, can_add_two_polynom)
{
  int deg[] = { 1,2,0,0 };
  int deg1[] = { 1,2,0,3 };
  TMonom G(deg, 12, 4), F(deg1, 14, 4);
  TPolynom A(4),D(4),S(4);
  A.Put(G);
  D.Put(F);
  ASSERT_NO_THROW(A + D);
  S = A + D;
  TMonom* temp = S.GetBegin();
  ASSERT_TRUE(*temp==F);
  temp=temp->GetNext();
  ASSERT_TRUE(*temp == G);
}
TEST(TPolynom, can_substract_two_polynom)
{
  int deg[] = { 1,2,0,0 };
  int deg1[] = { 1,2,0,3 };
  TMonom G(deg, 12, 4), F(deg1, 14, 4);
  TPolynom A(4), D(4), S(4);
  A.Put(G);
  D.Put(F);
  ASSERT_NO_THROW(A - D);
  S = A - D;
  TMonom* temp = S.GetBegin();
  ASSERT_TRUE(*temp == F);
  temp = temp->GetNext();
  ASSERT_TRUE(*temp == G);
}
TEST(TPolynom, can_multiply_two_polynom)
{
  int deg[] = { 1,1,0,0 };
  int deg1[] = { 1,0,1,0};
  TMonom G(deg, 12, 4), F(deg1, 14, 4);
  TPolynom A(4), D(4), S(4);
  A.Put(G);
  D.Put(F);
  ASSERT_NO_THROW(A * D);
  S = A * D;
  TMonom* temp = S.GetBegin();
  int degx[] = { 2,1,1,0 };
  for (int i = 0; i < G.GetCount(); i++)
    ASSERT_TRUE(degx[i] == temp->GetDeg()[i]);
  EXPECT_EQ(12 * 14, temp->GetKoeff());
}
TEST(TPolynom, throws_when_substract_two_polynom_different_count)
{
  int deg[] = { 1,2,0 };
  int deg1[] = { 1,2,0,3 };
  TMonom G(deg, 12, 3), F(deg1, 14, 4);
  TPolynom A(3), D(4);
  A.Put(G);
  D.Put(F);
  ASSERT_ANY_THROW(A - D);
}
TEST(TPolynom, throws_when_add_two_polynom_different_count)
{
  int deg[] = { 1,2,0 };
  int deg1[] = { 1,2,0,3 };
  TMonom G(deg, 12, 3), F(deg1, 14, 4);
  TPolynom A(3), D(4);
  A.Put(G);
  D.Put(F);
  ASSERT_ANY_THROW(A + D);
}
TEST(TPolynom, throws_when_multiply_two_polynom_different_count)
{
  int deg[] = { 1,2,0 };
  int deg1[] = { 1,2,0,3 };
  TMonom G(deg, 12, 3), F(deg1, 14, 4);
  TPolynom A(3), D(4);
  A.Put(G);
  D.Put(F);
  ASSERT_ANY_THROW(A * D);
}
TEST(TPolynom, assign_operator_works)
{
  int deg[] = { 1,2,0 };
  TMonom G(deg, 12, 3);
  TPolynom A(3), D(3);
  A.Put(G);
  D = A;
  TMonom* temp = D.GetBegin();
  ASSERT_TRUE(*temp == G);
}
TEST(TPolynom, can_compare_two_polynoms)
{
  int deg[] = { 1,2,0,0 };
  int deg1[] = { 1,2,0,3 };
  TMonom G(deg, 12, 4), F(deg1, 14, 4);
  TPolynom A(4), D(4);
  A.Put(G);
  D.Put(F);
  TPolynom S(A);
  ASSERT_FALSE(A == D);
  ASSERT_TRUE(A == S);
}
TEST(TPolynom, throws_when_compare_two_polynoms_different_count)
{
  int deg[] = { 1,2,0,0 };
  int deg1[] = { 1,2,0};
  TMonom G(deg, 12, 4), F(deg1, 14, 3);
  TPolynom A(4), D(3);
  A.Put(G);
  D.Put(F);
  ASSERT_ANY_THROW(A == D);
}

