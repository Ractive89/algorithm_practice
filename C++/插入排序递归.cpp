#include <iostream>
#include <vector>
using namespace std;
int swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
	return 0;
	
}
int InsertSort(int *arr,int n,int i){
	if(n==i)return arr[n];
	int j;
	InsertSort(arr,n,i-1);
	for(j=n;j<i;j++){
		if(arr[i]>arr[j])swap(&arr[i],&arr[j]);
	}
	
}
int PrintArr(int *arr,int size){
	int i;
	for(i=0;i<size;i++){
		cout<<arr[i];
	}
	cout<<endl;
}
int main(int argc, char *argv[])
{
	int arr[10]={
		6,4,6,4,2,0,9,3,8,1
	};
	
	InsertSort(arr,0,9);
	PrintArr(arr,9);
	return 0;
}
