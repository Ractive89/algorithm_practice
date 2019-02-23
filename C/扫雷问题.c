/*
问题描述
扫雷游戏你一定玩过吧！现在给你若干个n×m的地雷阵，
请你计算出每个矩阵中每个单元格相邻单元格内地雷的个数，
每个单元格最多有8个相邻的单元格。 0<n,m<=100

输入格式
输入包含若干个矩阵，对于每个矩阵，第一行包含两个整数n和m，
分别表示这个矩阵的行数和列数。接下来n行每行包含m个字符。
安全区域用‘.’表示，有地雷区域用'*'表示。当n=m=0时输入结束。

样例输入
4 4
*...
....
.*..
....
3 5
**...
.....
.*...
0 0
样例输出
[1]Answer:
*100
2210
1*10
1110

[2]Answer:
**100
33200
1*100
（注意两个矩阵之间应该有一个空行，由于oj的格式化这里不能显示出来）
数据规模和约定
　　0<n,m<=100
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int iCheck(int row,int col,char **array){
	int count=0,i,j;
		for(i=0;i<row;i++){
			for(j=0;j<col;j++){
				if(array[i][j]!='*'){
					
					if(i<row-1){
						if(array[i+1][j]=='*')count++;
						if(j>0)if(array[i+1][j-1]=='*')count++;
						if(j<col-1)if(array[i+1][j+1]=='*')count++;
					}
					
					if(i>0){
						if(array[i-1][j]=='*')count++;
						if(j>0)if(array[i-1][j-1]=='*')count++;
						if(j<col-1)if(array[i-1][j+1]=='*')count++;
					}
					
					if(j<col-1)if(array[i][j+1]=='*')count++;
					
					if(j>0)if(array[i][j-1]=='*')count++;
					
					array[i][j]=(char)(count+48);
					count=0;
				}else continue;
			}
		}
	return 0;	
}

int iPrintA(int count,int row,int col,char **array){
	int i,j;
	printf("\nField #%d\n",count);
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			//printf("%c",*(*(array+i)+j));
			printf("%c",array[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return 0;
}

int main()
{
	int row,col,count=0;
	char **array;
	while(scanf("%d%d",&row,&col)&&(row>0)&&(col>0)){
		int i,j;
		array = (char **)malloc(row * sizeof(char *));
		for(i=0;i<row;i++){
			array[i] = (char *)malloc(col * sizeof(char));
			memset(array[i],0,col * sizeof(char));
		}
    	
		
		for(i=0;i<row;i++){
			getchar();
			for(j=0;j<col;j++){
				scanf("%c",&array[i][j]);
			}
		}
		
		iCheck(row,col,array);
		iPrintA(++count,row,col,array);
	}
    return 0;
}
