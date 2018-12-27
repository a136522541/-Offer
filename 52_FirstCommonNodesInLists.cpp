#include"List.h"
#include<math.h>

ListNode* FirstCommonNodesInLists(LinkList a, LinkList b){
  if(a==nullptr||b==nullptr) return nullptr;
  int LenA = 0;
  int LenB = 0;
  
  ListNode *NodeA = a;
  ListNode *NodeB = b;
  while(NodeA!=nullptr){
    LenA++;
    NodeA = NodeA->Next;
  }

  while(NodeB!=nullptr){
    LenB++;
    NodeB = NodeB->Next;
  }

  if(NodeA!=NodeB) return nullptr;//如果两者尾指针不相等，则肯定没有共同节点

  NodeA = a; NodeB = b;

  int step = abs(LenA - LenB);
  if(LenA >= LenB) for(int i = 0; i < step; ++i) NodeA = NodeA->Next;
  else  for(int i = 0; i < step; ++i) NodeB = NodeB->Next;

  while(NodeA!=NodeB&&NodeA!=nullptr){
    NodeA = NodeA->Next;
    NodeB = NodeB->Next;
  }
  return NodeA;//如果空，则表明无共同节点，否则返回第一个共同节点

}





int main(){
  LinkList a = nullptr;
  LinkList b = nullptr;

  AddToTail(a,1);
  AddToTail(a,2);
  AddToTail(a,3);
  AddToTail(a,4);

  AddToTail(b,5);
  AddToTail(b,6);
  AddToTail(b,7);

  ListNode *NodeA = FindValue(a,4);
  ListNode *TailB = GetTail(b);
  TailB->Next = NodeA;

  ListNode *Result = FirstCommonNodesInLists(a,b);
  int flag = 0;
  if(Result==nullptr) flag=1;
  printf("%d\n",Result->Value);
  //printf("%d",flag);

  //PrintLinkList(a);
  //PrintLinkList(b);
  return 0;
}
