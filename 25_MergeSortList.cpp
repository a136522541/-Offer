#include<stdio.h>
#include<iostream>
#include"List.h"

LinkList MergeSortList(LinkList L1, LinkList L2){
  if(L1==nullptr&&L2==nullptr) return nullptr;
  else if(L1==nullptr) return L2;
  else if(L2==nullptr) return L1;
  else{
    ListNode* Node1 = L1;
    ListNode* Node2 = L2;

    LinkList ListResult = nullptr;
    ListNode *NodeResult = nullptr;
    //初始化输出的第一个节点
    if(Node1->Value<=Node2->Value){
      NodeResult = Node1;
      ListResult = NodeResult;
      Node1 = Node1->Next;
    }
    else{
      NodeResult = Node2;
      ListResult = NodeResult;
      Node2 = Node2->Next;
    }
    //循环判断两个链表的元素大小
    while(Node1!=nullptr&&Node2!=nullptr){
      if(Node1->Value<=Node2->Value){
        NodeResult->Next = Node1;
        NodeResult = NodeResult->Next;
        Node1 = Node1->Next;
      }
      else{
        NodeResult->Next = Node2;
        NodeResult = NodeResult->Next;
        Node2 = Node2->Next;
      }
    }

    //当有一个链表已经结束时，退出循环，此时将另一个链表拷贝到输出链表末端
    if(Node1==nullptr) NodeResult->Next = Node2;
    else NodeResult->Next = Node1;

    return ListResult;
  }
}

int main(){
   LinkList a = nullptr;
   LinkList b = nullptr;
   //AddToHead(a,10);
   //AddToHead(a,8);
   AddToHead(a,5);
   AddToHead(a,3);
   AddToHead(a,1);
   //AddToHead(b,10);
   //AddToHead(b,8);
   AddToHead(b,5);
   AddToHead(b,3);
   AddToHead(b,1);
   PrintLinkList(a);
   PrintLinkList(b);
   //a = nullptr;
   //b = nullptr;
   LinkList c = MergeSortList(a,b);
   PrintLinkList(c);
   
   return 0;
}











