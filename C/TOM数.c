/*
题目描述
正整数的各位数字之和被Tom称为Tom数。求输入数（<2^32）的Tom数!

输入
每行一个整数(<2^32).

输出
每行一个输出,对应该数的各位数之和.

样例输入
12345
56123
82

样例输出
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
