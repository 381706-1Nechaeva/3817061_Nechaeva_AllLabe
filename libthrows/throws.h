#pragma once
#include <iostream>
#include <string>

using namespace std;

class TException
{
private:
  string str;
public:
  TException(string _str); //�����������
  void Print(); //����� ������� ���������� �� �������
};

TException::TException(string _str) 
{
  str = _str;
}

void TException::Print()
{
  cout << "\nWarning! \nMessage: " << str << endl;
}