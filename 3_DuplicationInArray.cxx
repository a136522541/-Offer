#include<iostream>
using namespace std;

int Count(int array[],int len, int start, int end){
  if(len<=0||array==nullptr) return -1;
  int count = 0;
  for(int i = 0; i <= len; ++i){
    if(array[i]>=start&&array[i]<=end) count++;
  }
  return count;
}

/*
int CheckDuplicateArray(int array[], int len){
  if(array==nullptr||len<=0) return -1;
  for(int i = 0; i < len; ++i){
    if(array[i]<0||array[i]>len-1) return -1;
  }
  for(int i = 0; i < len; ++i){
    while(array[i]!=i){
      if(array[i]==array[array[i]]) return array[i];
      swap(array[i],array[array[i]]);
    }
  }
  return -1;
}
*/
/*
int CheckDuplicateArray(int array[], int len){
  if(array==nullptr||len<=0) return -1;
  for(int i = 0; i < len; ++i){
    if(array[i]<0||array[i]>len-1) return -1;
  }
  int temp[len];
  for(int i = 0; i < len; i++){
    temp[i] = -1;
  }
  for(int i = 0; i < len; i++){
    if(temp[array[i]]!=-1) return array[i];
    temp[array[i]] = array[i];
  }
  return -1;
}
  */  

int main(){
  int a[7] = {2,3,1,0,2,5,3};
  int *b = nullptr;
  int c[1] = {0};
  int d[5] = {4,2,1,3,3};
  int e[5] = {6,2,1,3,3};
  cout<<"array a: "<<CheckDuplicateArray(a,sizeof(a)/sizeof(int))<<endl;
  cout<<"array b: "<<CheckDuplicateArray(b,sizeof(b)/sizeof(int))<<endl;
  cout<<"array c: "<<CheckDuplicateArray(c,sizeof(c)/sizeof(int))<<endl;
  cout<<"array d: "<<CheckDuplicateArray(d,sizeof(d)/sizeof(int))<<endl;
  cout<<"array e: "<<CheckDuplicateArray(e,sizeof(e)/sizeof(int))<<endl;
  return 0;
}
