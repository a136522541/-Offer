#include<stdio.h>
#include<exception>
#include<iostream>

int MinInOrder(int Array[], int P1, int P2){
  int result= Array[P1];
  for(int i = P1; i < P2; ++i){
    if(Array[i] < result) result = Array[i];
  }
  return result;
}

int MinNumberInRotatedArray(int Array[], int Len){
  if(Array==nullptr){
    printf("Array is empty!\n");
    return -9999;
  }

  if(Len==1) return Array[0];

  int P1 = 0;
  int P2 = Len - 1;

  if(Array[P1] < Array[P2]) return Array[P1]; //数组并没有旋转，返回第一个元素

  int PMid = (P1 + P2)/2;

  while(true){
    if(Array[P1]==Array[P2]&&Array[P1]==Array[PMid]) 
      return MinInOrder(Array,P1,P2);//如果三者相等，则只能用顺序查找

    if(P2 - P1==1) return Array[P2];//如果两者已经挨在一起，则右指针是数组头
    
    if(Array[PMid] > Array[P2]) {
      P1 = PMid;
      PMid = (P1 + P2)/2;
    }
    else{
      P2 = PMid;
      PMid = (P1 + P2)/2;
    }
  }



}

int main(){
  //int a[10] = {4,5,6,7,8,9,0,0,0,3};
  int a[5] = {2,2,3,5,1};

  int result = MinNumberInRotatedArray(a,5);
  printf("%d\n",result);
  return 0;
}
