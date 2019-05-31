#pragma once
#include "stack.h"
#include "node.h"

 class TNodeIter
  {
  protected:
    TNode* root;
    TNode* cur;
    TStack <TNode*> St;
  public:
    TNodeIter(TNode*r); // êîíñòðóêòîð ïî óìîë÷àíèþ
    TNodeIter& GoNext(); // ïåðåéòè íà ñëåäóþùèé ýëåìåíò
    void Reset(); // ñáðîñèòü òåêóùóþ ïîçèöèþ è óñòàíîâèòü óêàçàòåëü íà íà÷àëî
    bool IsEnd(); // åñëè ìû çàêîí÷èëè, òî âîçâðàùàåò ïðàâäó
    TNode* operator() ();
    TNodeIter& operator++ (int);
  };
