/*
竖式输入数字返回乘法计算过程 

输入：10804

输出：
<1>
..292
X..37
-----
.2044
 876.
-----
10804

<2>
..148
X..73
-----
. 444
1036.
-----
10804

<3>
..146
X..74
-----
. 584
1022.
-----
10804
 */
#include <stdio.h>

int main()
{
	int number;
	while(scanf("%d",&number)&&number>999){
		int i,j,count=0;
		for(i=10;i<100;i++)
			for(j=100;j<1000;j++)
				if(number==i*j){
					printf("<%d>\n..%3d\nX..%2d\n-----\n",++count,j,i);
					printf(".%4d\n%4d.\n-----\n%5d\n\n",j*(i%10),j*(i/10),number);
				}
	}
    return 0;
}
