#include <iostream>
#include <vector>
#include <string>
#include<cstring>
using namespace std;

int* increase_arr(int *arr,int left,int right){
	int max=0;
	int end=left;
	int countable=0;
	int *a=(int *)malloc(2*sizeof(int));
	while(end<right){
		for(left=end;arr[end]<arr[end+1]&&end<right;end++);
		if(end-left+1>max){
			max=end-left+1;
			a[0]=left;
			a[1]=end;
		}
		//cout<<"left"<<left<<" end"<<end<<endl;
		countable=0;
		for(;end<right&&arr[end]>=arr[end+1];end++);
		
	}
	return a;
	
		
}

int main(int argc, char *argv[])
{
	int arr[]={
		1,9,2,5,2,3,4,6,8,9
	};
	int *results=increase_arr(arr,0,9);
	cout<<results[0]<<" "<<results[1]<<endl;
	delete results;
	return 0;
}
