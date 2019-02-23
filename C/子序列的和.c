/*
��������������n��m��10^6,����5λС����
���1/(n)^2+1/(n+1)^2+...+1/(m)^2
��������������ݣ� �������Ϊn��m��0��
��ʾ�����������塣

�������룺
2 4
65536 655360
0 0

���������
Case 1: 0.42361
Case 2: 0.00001

*/

#include <stdio.h>
#define POW_TWO(i)(i*i)
int main(int argc, char *argv[])
{
	long long int n,m;
	int kase=0;
	while(scanf("%lld%lld",&n,&m)&&(n||m)){
		if(m<n){
			printf("error:m<n\n");
			continue;
		}else{
			double value=0;
			long long int i;
			for(i=n;i<=m;i++)value+=1.0/POW_TWO(i);
			
			printf("Case %d :%.5f",++kase,value);
		}	
	}
	return 0;
}
