#include<stdio.h>
#include<iostream>
#include"List.h"




void ReverseLinkList(LinkList &List){
  if(List==nullptr) {
    printf("List is empty");
    return ;
  }

  LinkList pPrev = nullptr;
  LinkList pNext = nullptr;

  while(List->Next!=nullptr){
    pNext = List->Next;
    List->Next = pPrev;

    pPrev = List;
    List = pNext;
  }

  List->Next = pPrev;
}

int main(){
  LinkList list = nullptr;
  
  AddToHead(list,1);
  AddToHead(list,3);
  AddToHead(list,5);
  AddToHead(list,7);
  AddToHead(list,9);
  PrintLinkList(list);
  ReverseLinkList(list);
  PrintLinkList(list);
  return 0;
}











