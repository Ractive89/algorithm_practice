/*
输出100～999中的所有水仙花数。
若3位数ABC满足ABC＝A^3＋B^3＋C^3，则称其为水仙花 数。
例如153＝1^3＋5^3＋3^3，所以153是水仙花数。
*/
#include<stdio.h> 
#define POW_THREE(i) (i*i*i)

int main() {  
	int i;
	for(i=100;i<1000;i++)
		if(POW_THREE((i%10))+POW_THREE((i/100))+POW_THREE(((i/10)%10))==i)
	printf("%d\n",i);
}
