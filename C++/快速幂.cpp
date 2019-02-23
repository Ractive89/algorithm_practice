#include <iostream>
#include <vector>
using namespace std;
int fast_pow(int a,int n){
	if(n==1)return a;
	int res=a;
	int i;
	for(i=1;(i<<1)<n;i<<=1)res=res*res;
	return res*fast_pow(a,n-i);	
}

int main(int argc, char *argv[])
{
	cout<<fast_pow(5,5)<<endl;	
	return 0;
}
