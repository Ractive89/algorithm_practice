/*
输入正整数n，输出一个n层的倒三角形。
例如，n＝5时输出如下
#########
 ####### 
  #####
   ###
    #
*/
#include<stdio.h> 
int main(){
	int n;
	scanf("%d",&n);
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<i;j++)printf(" ");
		for(j=i*2;j<n*2-1;j++)printf("#");
		printf("\n");
	}
}
