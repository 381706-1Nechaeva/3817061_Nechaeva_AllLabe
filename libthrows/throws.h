#pragma once
#include <iostream>
#include <string>

using namespace std;

class TException
{
private:
  string str;
public:
  TException(const string _str) ;  //КОНСТРУКТОР
  void Print() ;  //ВЫВОД ДАННОГО ИСКЛЮЧЕНИЯ НА КОНСОЛЬ
};

TException::TException(const string _str)
{
  str = _str;
}

void TException::Print() 
{
  cout << "\nWarning! \nMessage: " << str << endl;
}