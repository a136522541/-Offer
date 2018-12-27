#include"List.h"

ListNode* KthNodeFromEnd(LinkList list, int k){
  if(list==nullptr||k<=0) return nullptr;
  ListNode *N1 = list;//第一个节点，此为最终返回节点
  ListNode *N2 = list;//第二个节点，此为跟踪至链表末尾的节点
  for(int i = 1; i < k; ++i){
    N2 = N2->Next;
    if(N2==nullptr) {
      printf("list too short\n");
      return nullptr;//如果节点长度小于k，返回空指针
    }
  }
  
  while(N2->Next!=nullptr){
    N1 = N1->Next;
    N2 = N2->Next;
  }
  
  return N1;
}

int main(){
  LinkList a = nullptr;
  AddToTail(a,1);
  AddToTail(a,2);
  AddToTail(a,3);
  AddToTail(a,4);
  AddToTail(a,5);
  AddToTail(a,6);
  //a = nullptr;
  ListNode *Node = KthNodeFromEnd( a, 3);
  if(Node!=nullptr)printf("%d\n",Node->Value);
  return 0;
}



