#include<iostream>
using namespace std;
#include<vector>
bool isTrue(vector<int>array,vector<int>sequence){
int i=0;
int j=0;
for(int i=0;i<array.size();i++){
if(array[i]==sequence[j]){
j+=1;
}
}
if(j==sequence.size()){
return true;
}
return false;
}
