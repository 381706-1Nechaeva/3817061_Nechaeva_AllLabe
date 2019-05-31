#include <iostream>
#include "hashlist.h"

int main() 
{
  THashTable<int> A(4);
  A.Put("a", 5);
  A.Del("a");
  cout << A.Find("a");
  return 0;
}