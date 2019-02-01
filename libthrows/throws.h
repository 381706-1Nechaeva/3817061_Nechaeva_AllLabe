#pragma once
#include <iostream>
#include <string>

using namespace std;

class TException
{
private:
  string str;
public:
  TException(const string _str); //йнмярпсйрнп
  void Print(); //бшбнд дюммнцн хяйкчвемхъ мю йнмянкэ
};

TException::TException(const string _str) 
{
  str = _str;
}

void TException::Print()
{
  cout << "\nWarning! \nMessage: " << str << endl;
}