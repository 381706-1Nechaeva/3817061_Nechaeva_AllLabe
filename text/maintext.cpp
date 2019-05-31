#include <iostream>
#include "text.h"

int main() 
{
  TNode* r;
  r = new TNode(0);
  TText Text(r);
  char a = 'H';
  Text.Ins(Text.GetRoot(), a);
  TText C(Text);
}