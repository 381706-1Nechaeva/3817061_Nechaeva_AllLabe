#include "plex.h"

#include <gtest.h>

TEST(TPlex, can_create_plex)
{
  ASSERT_NO_THROW(TPlex A);
}
TEST(TPlex, can_copy_plex)
{
  TPoint *D, *B;
  B = new TPoint(3, 3);
  D = new TPoint(4, 4);
  TPlex A(B,D);
  ASSERT_NO_THROW(TPlex B(A));
}
TEST(TPlex, throw_when_add_error_line)
{
  TPlex A;
  TPoint *D, *B, *E, *S;
  S = new TPoint(1, 1);
  B = new TPoint(3, 3);
  D = new TPoint(3, 4);
  E = new TPoint(4, 4);
  A.Add(E, B);
  ASSERT_ANY_THROW(A.Add(D, S));
}
TEST(TPlex, can_add_line)
{
  TPlex A;
  TPoint *D, *B;
  B = new TPoint(3, 3);
  D = new TPoint(4, 4);
  ASSERT_NO_THROW(A.Add(D, B));
}
TEST(TPlex, can_get_first_point)
{
  TPlex A;
  TPoint *D, *B;
  B = new TPoint(3, 3);
  D = new TPoint(4, 4);
  A.Add(D, B);
  EXPECT_TRUE(D == A.GetFirst());
}
TEST(TPlex, can_get_last_point)
{
  TPlex A;
  TPoint *D, *B;
  B = new TPoint(3, 3);
  D = new TPoint(4, 4);
  A.Add(D, B);
  EXPECT_TRUE(B == A.GetLast());
}
TEST(TPlex, can_set_first_point)
{
  TPlex A;
  TPoint *D, *B, *S;
  B = new TPoint(3, 3);
  D = new TPoint(4, 4);
  S = new TPoint(23, 4);
  A.Add(D, B);
  EXPECT_TRUE(D == A.GetFirst());
  A.SetFirst(S);
  EXPECT_TRUE(S == A.GetFirst());
}
TEST(TPlex, can_set_last_point)
{
  TPlex A;
  TPoint *D, *B, *S;
  B = new TPoint(3, 3);
  D = new TPoint(4, 4);
  S = new TPoint(23, 4);
  A.Add(D, B);
  EXPECT_TRUE(B == A.GetLast());
  A.SetLast(S);
  EXPECT_TRUE(S == A.GetLast());
}