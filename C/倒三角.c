/*
����������n�����һ��n��ĵ������Ρ�
���磬n��5ʱ�������
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
