#include<stdio.h>
#include<iostream>

int FindLeftEdge(int Array[], int First, int Last, int Num){

  if(Array[First]==Num&&Array[Last]==Num){//如果First到Last都是Num，返回首或尾的下标即可
    return First;
  }

  int Mid = (First + Last)/2;

  while(Mid > First){
    if(Array[Mid] >= Num) Last = Mid;
    else First = Mid;
    Mid = (First + Last)/2;
  }

  if(Mid==First) return Last;
}

int FindRightEdge(int Array[], int First, int Last, int Num){

  if(Array[First]==Num&&Array[Last]==Num){//如果First到Last都是Num，返回首或尾的下标即可
    return Last;
  }

  int Mid = (First + Last)/2;

  while(Mid > First){
    if(Array[Mid] > Num) Last = Mid;
    else First = Mid;
    Mid = (First + Last)/2;
  }

  //if(Array[Mid]==Array[Last]) return Last;
  //else return First;
  return First;
}




int NumberOfK(int Array[],int len, int Num){
  if(Array==nullptr||len<=0) {
    return -9999;
  }

  int P1 = 0;
  int P2 = len - 1;
  int PMid = (P1 + P2)/2;

  while(PMid > P1){
    if(Array[PMid] == Num) break;//如果找到数字，退出此循环
    else if(Array[PMid] > Num) P2 = PMid;
    else if(Array[PMid] < Num) P1 = PMid;
    PMid = (P1 + P2)/2;
  }


  if(Array[PMid]!=Num&&Array[P2]!=Num){
    return 0;
  }
  else if(Array[PMid]!=Num&&Array[P2]==Num){//对于此种情况，P2一定位于末尾，而且只有最后一个元素为待查找元素
    return 1;
  }

  int FirstIndex = FindLeftEdge(Array, 0, PMid, Num);
  int LastIndex = FindRightEdge(Array, PMid, len-1, Num);


  return LastIndex - FirstIndex +1;

}

void Test1(){//空指针
  int *a = nullptr;
  int Num = NumberOfK(a,sizeof(a)/sizeof(int), 5);
  if(Num==-9999) printf("Test1 Pass\n");
}

void Test2(){//数组只有1个元素
  int a[1] = {5};
  int Num = NumberOfK(a,sizeof(a)/sizeof(int), 5);
  if(Num==1) printf("Test2 Pass\n");
}

void Test3(){//数组有多个待查找元素
  int a[8] = {1,2,3,3,3,4,5,6};
  int Num = NumberOfK(a,sizeof(a)/sizeof(int), 3);
  if(Num==3) printf("Test3 Pass\n");
}

void Test4(){//数组没有待查找元素
  int a[8] = {1,2,3,3,3,4,5,6};
  int Num = NumberOfK(a,sizeof(a)/sizeof(int), 7);
  if(Num==0) printf("Test4 Pass\n");
}

void Test5(){//查找元素为最小值
  int a[8] = {1,1,1,3,3,4,5,6};
  int Num = NumberOfK(a,sizeof(a)/sizeof(int), 1);
  if(Num==3) printf("Test5 Pass\n");
}

void Test6(){//查找元素为最大值
  int a[8] = {1,2,2,3,3,6,6,6};
  int Num = NumberOfK(a,sizeof(a)/sizeof(int), 6);
  if(Num==3) printf("Test6 Pass\n");
}

void Test7(){//查找元素为最大值,且只有1个
  int a[8] = {1,2,2,3,3,3,4,6};
  int Num = NumberOfK(a,sizeof(a)/sizeof(int), 6);
  if(Num==1) printf("Test7 Pass\n");
}

int main(){
  Test1();
  Test2();
  Test3();
  Test4();
  Test5();
  Test6();
  Test7();

  return 0;
}
