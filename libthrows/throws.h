#pragma once
#include <iostream>
#include <string>

using namespace std;

class TException
{
private:
  string str;
public:
  inline TException(const string _str) ;  //КОНСТРУКТОР
  inline void Print() ;  //ВЫВОД ДАННОГО ИСКЛЮЧЕНИЯ НА КОНСОЛЬ
};

inline TException::TException(const string _str)
{
  str = _str;
}

inline void TException::Print()
{
  cout << "\nWarning! \nMessage: " << str << endl;
}