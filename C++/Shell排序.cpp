/*��ȡһ��С��n������d1��Ϊ��һ������(gap)�����ļ���ȫ����¼�ֳ�d1���顣
���о���Ϊdl�ı����ļ�¼����ͬһ�����С�
���ڸ����ڽ���ֱ�Ӳ�������Ȼ��ȡ�ڶ�������d2<d1�ظ������ķ��������
ֱ����ȡ������dt=1(dt<dt-l<����<d2<d1���������м�¼����ͬһ���н���ֱ�Ӳ�������Ϊֹ��*/
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
