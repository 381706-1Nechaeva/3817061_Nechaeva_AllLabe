
#include "postfix.h"

int main()
{
  char* str = new char[255];
  cin.getline(str, 255);
  TPostfix poland(str);
  cout << poland.Postfix();
  return 0;
}