#include<stdio.h>
#include"List.h"


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


int main(){
  LinkList a = nullptr;
  AddToTail(a,2);
  AddToTail(a,4);
  AddToTail(a,6);
  //AddToTail(a,8);
  //AddToTail(a,10);
  //PrintLinkList(a);
  ListNode *Node = FindValue(a,6);
  DeleteNodeInList(a,Node);
  PrintLinkList(a);
  //printf("%d\n",Node->Value);
  return 0;
}
