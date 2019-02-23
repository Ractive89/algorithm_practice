/*
蛇形填数
在n×n方阵里填入1，2，…，n×n，要求填成蛇形。
例如，n＝4时方阵为：
10 11 12 1 
9 16 13 2 
8 15 14 3 
7 6 5 4
上面的方阵中，多余的空格只是为了便于观察规律，不必严格输出。n≤8。

 */
//include<string.h>
//memset(a, 0, sizeof(a));
//memcpy(b,a,sizeof(int)*k);

#include <stdio.h>
#include <string.h>
#define MAXN 30
int a[MAXN][MAXN];

int main()
{
	int n;
	while(scanf("%d",&n)&&n>0&&n<30){
		memset(a,0,sizeof(a));
		int x=0,y=n-1,total=1;
		a[x][y]=1;
		while(total<n*n){

		while(x+1<n&&!a[x+1][y])a[++x][y]=++total;
		while(y-1>=0&&!a[x][y-1])a[x][--y]=++total;
		while(x-1>=0&&!a[x-1][y])a[--x][y]=++total;
		while(y+1<n&&!a[x][y+1])a[x][++y]=++total;			
		}
		int i,j;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				printf("%5d ",a[i][j]);
			}
			printf("\n");
		}
		
	}
    return 0;
}
