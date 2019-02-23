#include <iostream>
#include <vector>
#include <string>
using namespace std;

int indexOf(string *arr,string p,int len){
	int begin=0;
	int end=len-1;
	while(begin<=end){
		int mid=begin+((end-begin)>>1);
		while(arr[mid]==""){
		
		mid++;
		if(mid>end)return -1;
		}
		if(arr[mid].compare(p)>0){
			end=mid-1;
		}else if(arr[mid].compare(p)<0){
			begin=mid+1;
		}else return mid;
	}	
	return -1;
}

int main(int argc, char *argv[])
{
	string arr[]={
		"a","","ac","","ad","b","","ba"
	};
	
	cout<<indexOf(arr,"ab",8);
	
	return 0;
}
