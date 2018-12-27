#include<iostream>
using namespace std;

void ReplaceSpaces(char string[], int len){
  //判断输入正确性,len为字符串最大长度
  if(len <= 0 || string==nullptr) return;

  int space = 0;
  int i = 0;
  while(string[i]!='\0'){
    if(string[i]==' ') space++;
    ++i;
  }

  int OriginalLength = i;
  int NewLength = OriginalLength + space*2;
  if(NewLength>len) return;

  int NewIndex = NewLength - 1;
  int OldIndex = OriginalLength - 1;

  while(OldIndex >= 0){
    while(string[OldIndex]==' ') {
      string[NewIndex--] = '0';
      string[NewIndex--] = '2';
      string[NewIndex--] = '%';
      OldIndex--;
    }
    
    string[NewIndex--] = string[OldIndex--];
  }
}


int main(){
  char a[100] = "    ";
  ReplaceSpaces(a,100);
  cout<<"a = "<<a<<endl;
  return 0;
}
