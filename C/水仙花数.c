/*
���100��999�е�����ˮ�ɻ�����
��3λ��ABC����ABC��A^3��B^3��C^3�������Ϊˮ�ɻ� ����
����153��1^3��5^3��3^3������153��ˮ�ɻ�����
*/
#include<stdio.h> 
#define POW_THREE(i) (i*i*i)

int main() {  
	int i;
	for(i=100;i<1000;i++)
		if(POW_THREE((i%10))+POW_THREE((i/100))+POW_THREE(((i/10)%10))==i)
	printf("%d\n",i);
}
