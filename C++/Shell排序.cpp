/*先取一个小于n的整数d1作为第一个增量(gap)，把文件的全部记录分成d1个组。
所有距离为dl的倍数的记录放在同一个组中。
先在各组内进行直接插入排序；然后，取第二个增量d2<d1重复上述的分组和排序，
直至所取的增量dt=1(dt<dt-l<；…<d2<d1），即所有记录放在同一组中进行直接插入排序为止。*/
#include <iostream>
#include <vector>
using namespace std;

int swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
	return 0;
}

int PrintArr(int *arr,int size){
	int i;
	for(i=0;i<size;i++){
		cout<<arr[i];
	}
	cout<<endl;
}
int Shell_sort(int *arr,int len){
	int interal,i,j;
	for(interal=len/2;interal>0;interal=interal/2){
		for(i=interal;i<len;i++){
			for(j=i-interal;j>-1&&arr[j]>arr[j+interal];j=j-interal){
				swap(&arr[j],&arr[j+interal]);
			}
		}
	}
}


int main(int argc, char *argv[])
{
	int arr[10]={
		9,8,7,6,5,4,3,2,1,0
	};
	Shell_sort(arr,10);
	PrintArr(arr,10);
	return 0;
}
