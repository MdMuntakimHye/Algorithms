#include<iostream>
#include<string.h>

using namespace std;

int main(){
   string input;
   cout<<"Enter input:: "<<endl;
   cin>>input;
   int i = 0, index;

   while(input[i]){
   char temp = input[i];
   char temp2 = input[i+1];
       if(temp == '+' && (temp2 != '+' && temp2 != '*')){
          input[++i] = 'E';
          index = i;
       }
       else if(temp == '*' && input[i+1]!= '+'&&input[i+1]!= '*'){
          input[++i] = 'E';
          index = i;
       }
       i++;
   }

   if(input[index] == 'E'){
    cout<<"Accepted";
   }
   else
   cout<<"Rejected";
}
