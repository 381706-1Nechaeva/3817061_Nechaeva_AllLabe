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
  char* temp;
  int j = 0, b;
  int ind = 0, scob = 0;
  for (int i = 0; inputistr[i] != '\0'; i++)
  {
    f = inputistr[i];
    if (f == '(' || f == ')')
      scob += 1;
  }
  if (scob % 2 != 0)
    throw TException("error string");
  for (int i = 0; inputistr[i] != '\0'; i++)
  {
    b = i;
    f = inputistr[i];
    if (inputistr[0] == '-' && j == 0)
    {
      outputistr[ind++] = '-';
      j = 1;
    }
    else if (inputistr[++b] == '-' && f == '(')
    {
      outputistr[ind++] = '-';
      opera.Put(f);
      i++;
    }
    else if (isalnum(f) && !isoperation(f))
    {
      outputistr[ind++] = f;
    }
    else if (f == '(') {
      // outputistr[ind++] = ' ';
      opera.Put(f);
    }
    else if (f == ')') {
      outputistr[ind++] = ' ';
      while ((tok = opera.Get()) != '(')
        outputistr[ind++] = tok;
    }
    else
    {
      outputistr[ind++] = ' ';
      while (!opera.IsEmpty() && PriorityStack(opera) >= Priority(f))
      {
        tok = opera.Get();
        outputistr[ind++] = tok;
        outputistr[ind++] = ' ';
      }
      opera.Put(f);
    }
  }
  while (!opera.IsEmpty())
  {
    tok = opera.Get();
    if (Priority(tok) > 1)
    {
      outputistr[ind++] = ' ';
      outputistr[ind++] = tok;
    }
    else
      throw TException("error symbol");
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
double TPostfix::calculate()
{
  int oper = 0, scob = 0, neoper = 0, rez;
  char f;
  char* temp;
  int s = 0, c, j = 0, b;
  for (int i = 0; outputistr[i] != '\0'; i++)
  {
    b = i;
    f = outputistr[i];
    if (outputistr[i] == '-' && isalnum(outputistr[++b]))
    {
      continue;
    }
    else if (isoperation(f))
      oper += 1;
    else if (isalnum(f))
    {
      while (outputistr[i] != ' ' && outputistr[i] != '\0')
      {
        c = 1;
        outputistr[i++];
      }
      neoper += c;
    }
  }
  if (oper >= neoper)
    throw TException("error string");
  TStack<int> A(neoper);
  for (int i = 0; outputistr[i] != '\0'; i++)
  {
    b = i;
    f = outputistr[i];
    if (outputistr[i] == '-' && isalnum(outputistr[++b]))
    {
      temp = new char[255];
      while (outputistr[i] != ' ' && outputistr[i] != '\0')
        temp[s++] = outputistr[i++];
      A.Put(atoi(temp));
      s = 0;
      delete temp;
    }
    else if (isalnum(f))
    {
      temp = new char[255];
      while (outputistr[i] != ' ' && outputistr[i] != '\0')
        temp[s++] = outputistr[i++];
      A.Put(atoi(temp));
      s = 0;
      delete temp;
    }
    else if (isoperation(f))
    {
      double B = A.Get();
      double C = A.Get();
      double D;
      if (f == '+')
        D = C + B;
      if (f == '-')
        D = C - B;
      if (f == '*')
        D = C * B;
      if (f == '/')
        D = C / B;
      A.Put(D);
    }
  }
  rez = A.Get();
  return rez;
}
