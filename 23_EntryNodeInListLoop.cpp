#include<stdio.h>
#include"List.h"
#include<iostream>
using namespace std;

ListNode* EntryNodeInListLoop(LinkList a){
  if(a==nullptr) return nullptr;
  ListNode *N1 = a;//节点每次走1步
  ListNode *N2 = a;//节点每次走2步

  //当两个节点重合，表明链中有环
  //当N2走到链表末尾，表明链表无环
  N2 = N2->Next;

  while(N2!=nullptr&&N1!=N2){
    N1 = N1->Next;
    N2 = N2->Next;
    if(N2) N2 = N2->Next;
  }

  if(N2==nullptr) return nullptr;

  //函数到此处仍未返回，证明表中有环
  //确认环的长度
  int len = 1;
  N2 = N2->Next;


  while(N1!=N2){
    ++len;
    N2 = N2->Next;
  }

  //将两个指针重设为头指针，N2先走len步,然后再一起走
  //当两个指针重合，则该处为环入口
  N1 = a; N2 = a;
  for(int i = 0; i < len; ++i) N2 = N2->Next;

  while(N1!=N2){
    N1 = N1->Next;
    N2 = N2->Next;
  }
  
  return N1;
}





int main(){
  LinkList a = nullptr;
  //AddToTail(a,1);
  //AddToTail(a,2);
  //AddToTail(a,3);
  //AddToTail(a,4);
  //AddToTail(a,5);

  ListNode *Node = FindValue(a,3);

  ListNode *Tail = GetTail(a);
  //Tail->Next = Tail;
  //PrintLinkList(a);
  
  ListNode *LoopEntry = EntryNodeInListLoop(a);
  
  bool IsNull = (LoopEntry==nullptr);

  //printf("%d\n",LoopEntry->Value);
  cout<<IsNull<<endl;
  return 0;
}
