#include "nodeiter.h"

class TText
{
protected:
  TNode *root;
public:
  TText();
  TText(TNode* r);
  TText(TText& T);
  TNode* GetRoot();
  char* Copy(int start, int n);
  void Del(TNode* start, int n);
  void Ins(TNode* start, TNode* d); // âñòàâêà
  void Ins(TNode* start, string S);
  void Ins(TNode* start, char c);
  TNode* Find(char* a); // ïîèñê ñ âîçðàòîì óçëà
  int FindIndex(char* a); // ïîèñê ñ âîçâðàòîì íîìåðà áóêâû
  int GetCount();

};