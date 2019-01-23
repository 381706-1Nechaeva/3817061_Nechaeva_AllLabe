#include <iostream>

#include "postfix.h"
#include <cstring>

TPostfix::TPostfix(char* _inputistr)
{
  inputistr = new char[255];
  outputistr = new char[255];
  strcpy(inputistr, _inputistr);
}
char* TPostfix::Postfix()
{
  TStack<char> opera(20);
  char f, tok;
  int k,ind=0;
  for (int i = 0;inputistr[i]!='\0'; i++)
  {
    f = inputistr[i];
    if (isalnum(f) || f == '.' && !isoperation(f))
    {
      outputistr[ind++] = f;
    }
    else if (f == '(') {
     // outputistr[ind++] = ' ';
      opera.Put(f);
    }
    else if (f == ')') {
     // outputistr[ind++] = ' ';
      while ((tok = opera.Get()) != '(')
        outputistr[ind++] = tok;
    }
    else
    {
      outputistr[ind++] = ' ';
     while (!opera.IsEmpty() && PriorityStack(opera)>=Priority(f))
     {
          tok = opera.Get();
          outputistr[ind++] = tok;
     }
        opera.Put(f);
    }
   }
  while (!opera.IsEmpty())
  {
    tok = opera.Get();
    if (Priority(tok) > 1)
      outputistr[ind++] = tok;
  }
  outputistr[ind] = '\0';
  return outputistr;
}

bool isoperation(const char a)
{
  return (a == '+' || a == '-' || a == '*' || a == '/' || a == '(' || a == ')');
}

int Priority(const char a)
{
  switch (a)
  {
  case '(':
    return 0;
  case ')':
    return 1;
  case '+':
    return 2;
  case '-':
    return 2;
  case '*':
    return 3;
  case '/':
    return 3;
  default:
    return -1;
  }
}

int PriorityStack(TStack<char>& a)
{
  char x = a.Get();
  int res = Priority(x);
  a.Put(x);
  return res;
}
