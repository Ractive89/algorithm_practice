/*
��Ŀ����
�������ĸ�λ����֮�ͱ�Tom��ΪTom��������������<2^32����Tom��!

����
ÿ��һ������(<2^32).

���
ÿ��һ�����,��Ӧ�����ĸ�λ��֮��.

��������
12345
56123
82

�������
15
17
10
 */

#include <stdio.h>

int main()
{
	long long int a;
    while(~scanf("%lld", &a)){
    	int i,count=0;
    	for(i=0;a;count+=a%10,a=a/10);
    	printf("%d\n",count);
    }
    return 0;
}
