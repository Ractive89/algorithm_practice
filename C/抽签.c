// 抽签

// X星球要派出一个5人组成的观察团前往W星。
// 其中：
// A国最多可以派出4人。
// B国最多可以派出2人。
// C国最多可以派出2人。
// ....

// 那么最终派往W星的观察团会有多少种国别的不同组合呢？

// 下面的程序解决了这个问题。
// 数组a[] 中既是每个国家可以派出的最多的名额。

#include <stdio.h>
#include <stdlib.h>
#define N 6
#define M 5
#define BUF 1024

void f(int a[], int k, int m, char b[])
{
	int i,j;
	
	if(k==N){ 
		b[M] = 0;
		if(m==0) printf("%s\n",b);
		return;
	}
	
	for(i=0; i<=a[k]; i++){
		for(j=0; j<i; j++) b[M-m+j] = k+'A';
		//______________________;  //填空位置
        f(a,k+1,m-j,b);
	}
}
int main()
{	
	int  a[N] = {4,2,2,1,1,3};
	char b[BUF];
	f(a,0,M,b);
    system("pause");
	return 0;
}