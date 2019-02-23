/*
��������
ɨ����Ϸ��һ������ɣ����ڸ������ɸ�n��m�ĵ�����
��������ÿ��������ÿ����Ԫ�����ڵ�Ԫ���ڵ��׵ĸ�����
ÿ����Ԫ�������8�����ڵĵ�Ԫ�� 0<n,m<=100

�����ʽ
����������ɸ����󣬶���ÿ�����󣬵�һ�а�����������n��m��
�ֱ��ʾ��������������������������n��ÿ�а���m���ַ���
��ȫ�����á�.����ʾ���е���������'*'��ʾ����n=m=0ʱ���������

��������
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
�������
[1]Answer:
*100
2210
1*10
1110

[2]Answer:
**100
33200
1*100
��ע����������֮��Ӧ����һ�����У�����oj�ĸ�ʽ�����ﲻ����ʾ������
���ݹ�ģ��Լ��
����0<n,m<=100
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
