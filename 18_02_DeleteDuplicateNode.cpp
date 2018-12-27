#include<stdio.h>
#include"List.h"



void DeleteDuplicateNode(LinkList &List){
  if(List==nullptr) return;
  ListNode *Node = List;
  
  bool DeleteFlag= false;
  while(Node->Next!=nullptr){//Node一直沿着链表直到尾部
    DeleteFlag = false;
    if(Node->Value==Node->Next->Value){
      while(Node->Value==Node->Next->Value){//当节点元素与下一个元素相等，删除下一元素
        ListNode *ToBeDel = Node->Next;
        Node->Next = ToBeDel->Next;
        delete ToBeDel;
        if(Node->Next==nullptr) break;
      }
      DeleteNodeInList(List,Node);
      DeleteFlag = true;
    }

    if(DeleteFlag==false)Node = Node->Next;
  }
}


int main(){
  LinkList a = nullptr;
  AddToTail(a,1);

  DeleteDuplicateNode(a);

  PrintLinkList(a);
  return 0;
}
