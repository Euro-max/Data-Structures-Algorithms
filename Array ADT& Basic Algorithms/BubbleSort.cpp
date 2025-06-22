void BubbleSort(int*arr,int size){
  for(int i=0;i<size-1;i++){
for(int j=0;j<size-i-1;j++){
if(arr[j+1]<arr[j]){
int temp=arr[j];
arr[j]=arr[j+1];
arr[j+1]=temp;
}
}
  }
for (int i = 0; i < size; i++) cout << arr[i] << " ";

}
int main(){
  int arr[10]={1,2,5,3,23,22};
BubbleSort(arr,sizeof(arr)/sizeof(arr[0]);
return 0;
}
