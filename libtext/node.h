#pragma once
#include "throws.h"
#include "Stack.h"
#include <string.h>

class TNode {

protected:
  TNode* nextLevel;// óêàçàòåëü íà ñëåäóþùèé óðîâåíü
  TNode* sosed;// óêàçàòåëü íà ñîñåäà
  int level; // óðîâåíü ëèñòî÷êà 0 - òåêñò, 1 - ñòðîêà, 2 - ñëîâî, 3 - ñèìâîë.
  char data; // äàííîå ëèñòî÷êà

  static TNode* start; // íà÷àëî
  static TNode* end; // êîíåö
  static TNode* _free; // ïóñòîå ìåñòî
  static char* mas; // íàáîð áàéòîâ
  static int sizeMas; // ðàçìåð ìàññèâà, ãäå áóäåò âñÿ íàøà ïàìÿòü

public:
  TNode(char c);
  TNode(string s);
  TNode(int _level);
  TNode(TNode& other);
  TNode& operator=(const TNode& a);
  TNode& operator+=(TNode& a);
  TNode& operator+=(char c);
  TNode& operator+=(char*c);

  char* ToStr();
  TNode* Clone();

  int GetLevel();
  void SetLevel(int lev);
  TNode* GetNextLevel();
  void SetNextLevel(TNode* NL);
  TNode* GetSosed();
  void SetSosed(TNode* S);
  char GetData();
  void SetData(char c);

  void Init(int size); // èíèöèàëèçàöèÿ ñòàòè÷åñêèõ ïîëåé
  void* operator new (size_t n);
  void operator delete (void* a);
  static void GC(); // ñáîðùèê ìóñîðà
};