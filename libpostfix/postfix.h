#pragma once
#include <iostream>
#include <string>
#include "stack.h"
#include "queue.h"

using namespace std;

class TPostfix
{
protected:
  char* inputistr;
  char* outputistr;

public:
  TPostfix(char* _inputistr);
  char* Postfix(); //перевод
  double calculate(); //считает
 
};
bool isoperation(const char a);
int Priority(const char a);
int PriorityStack(TStack<char> &a);