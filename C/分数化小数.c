/*
����������a��b��c�����a/b��С����ʽ����ȷ��С�����cλ��
a��b<=10^6��c<=100���� ������������ݣ��������Ϊa��b��c��0��

�������룺
1 6 4
0 0 0

���������
Case 1: 0.1667

*/

#include <stdio.h>
int main(int argc, char *argv[])
{
	long long int a,b,c;
	int kase=0;
	while(scanf("%lld%lld%lld",&a,&b,&c)&&(a||b||c)){
		if(b==0||c>=18){
			printf("error\n");
			continue;
		}else{
			int i;
			long long int d;
			printf("Case %d :%lld.",++kase,a/b);
			
			for(i=1;i<c;i++){
				a*=10;
				printf("%lld",a/b%10);
			}
			if((d=a*10/b%10)>5)
				printf("%lld",d+1);
			else
				printf("%lld",d);
		}
	}
	return 0;
}
