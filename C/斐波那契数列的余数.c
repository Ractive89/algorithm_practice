/*
��������
Fibonacci���еĵ��ƹ�ʽΪ��Fn=Fn-1+Fn-2������F1=F2=1��

��n�Ƚϴ�ʱ��FnҲ�ǳ�������������֪����Fn����10007�������Ƕ��١�

�����ʽ
�������һ������n��
�����ʽ
���һ�У�����һ����������ʾFn����10007��������
˵�����ڱ����У�����Ҫ��Fn����10007���������������ֻҪ���������������ɣ�������Ҫ�ȼ����Fn��׼ȷֵ���ٽ�����Ľ������10007ȡ������ֱ�Ӽ������������������ԭ����ȡ��򵥡�

��������
10
�������
55
��������
22
�������
7704
���ݹ�ģ��Լ��
1 <= n <= 1,000,000��

 */
//include<string.h>
//memset(a, 0, sizeof(a));
//memcpy(b,a,sizeof(int)*k);

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
int Fibbonacci(int f){
	if(f==1||f==2)return 1;
	return Fibbonacci(f-1)+Fibbonacci(f-2);
}
*/


int main(void)
{
	int n,i;
	__int64 fib[1000005];
	fib[0]=fib[1]=1;
	for(i=2;i<1000005;i++){
		fib[i]=(fib[i-1]+fib[i-2])%10007;
	}
	scanf("%d",&n);
	printf("%I64d\n",fib[n-1]);		
	
	return 0;
}
