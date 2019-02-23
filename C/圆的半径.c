/*
问题描述
给定圆的半径r，求圆的面积。
输入格式
输入包含一个整数r，表示圆的半径。
输出格式
输出一行，包含一个实数，四舍五入保留小数点后7位，表示圆的面积。
说明：在本题中，输入是一个整数，但是输出是一个实数。

对于实数输出的问题，请一定看清楚实数输出的要求，比如本题中要求保留小数点后7位，则你的程序必须严格的输出7位小数，输出过多或者过少的小数位数都是不行的，都会被认为错误。

实数输出的问题如果没有特别说明，舍入都是按四舍五入进行。

样例输入
4
样例输出
50.2654825
数据规模与约定
1 <= r <= 10000。
 */
//include<string.h>
//memset(a, 0, sizeof(a));
//memcpy(b,a,sizeof(int)*k);

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int main(void)
{
	int n;
	double PI=atan(1.0)*4;
	scanf("%d",&n);
	printf("%.7lf",n*n*PI);
	return 0;
}
