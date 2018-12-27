#include<stdio.h>
#include<iostream>

typedef struct ListNode{
  int Value;
  ListNode *Next;
  ListNode *Tail;
} *LinkList;

void DeleteNodeInList(LinkList &List, ListNode *Node){
  if(List==nullptr||Node==nullptr) return;
  //假设输入的Node一定在链表中

  //当链表只有1个元素
  if(List==Node&&List->Next==nullptr){
    delete Node;
    List=nullptr;
    return;
  }

  //当删除节点为尾节点，需要从头遍历找到节点的前一个节点
  if(Node->Next==nullptr){
    ListNode *mPrev = List;
    while(mPrev->Next!=Node) mPrev = mPrev->Next;
    delete Node;
    mPrev->Next = nullptr;
    return;
  }

  //当删除节点为除尾节点以外

  ListNode *NodeToBeDel = Node->Next;//真实需要删除节点
  ListNode *NodeNext = NodeToBeDel->Next;//删除后Node的下一个节点

  Node->Value = NodeToBeDel->Value;
  Node->Next = NodeNext;
  delete NodeToBeDel;
  return;
}


void AddToHead(LinkList &List, int value){
  if(List==nullptr) {
    ListNode *Node = new ListNode;
    Node->Value = value;
    Node->Next = nullptr;
    List = Node;
    List->Tail = Node;
    return;
  }

  ListNode *Node = new ListNode;
  Node->Value = value;
  Node->Next = List;
  List = Node;
}

void AddToTail(LinkList &List, int value){
  if(List==nullptr) {
    ListNode *Node = new ListNode;
    Node->Value = value;
    Node->Next = nullptr;
    List = Node;
    List->Tail = Node;
    return;
  }

  ListNode *Node = new ListNode;
  Node->Value = value;
  Node->Next = nullptr;
   
  List->Tail->Next = Node;
  List->Tail = Node;
}


ListNode* FindValue(LinkList List, int value){
  if(List==nullptr) return nullptr;
  while(List!=nullptr){
    if(List->Value==value) return List;
    List = List->Next;
  }
  return nullptr;
}


ListNode* GetTail(LinkList List){
  if(List==nullptr) return nullptr;
  while(List->Next!=nullptr) List = List->Next;
  return List;
}

void PrintLinkList(LinkList List){
 if(List==nullptr){
   printf("List is empty");
   return;
 }

 int len = 0;
 while(List!=nullptr){
   if(len>=100) break;//防止链表中存在环时，陷入
   int value = List->Value;
   printf("%d\t",value);
   List = List->Next;
   len++;
 }
 
 printf("\n");
}












