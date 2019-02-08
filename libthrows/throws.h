#pragma once
#include <iostream>
#include <string>

using namespace std;

class TException
{
private:
  char* str;
public:
  TException(char* _str) ;  //�����������
  void Print() ;  //����� ������� ���������� �� �������
};

TException::TException(char* _str) 
{
  str = new char[255];
  strcpy(str, _str);
}

void TException::Print() 
{
  cout << "\nWarning! \nMessage: " << str << endl;
}