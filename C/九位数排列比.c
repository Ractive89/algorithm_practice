/*
用1,2,3……,9组成3个三位数abc,def和ghi,每个数字恰好使用一次
要求abc:def:ghi=1:2:3.输出所有解。
 */
#include <stdio.h>
 
int resultF(int num, int *result_add, int *result_mul)
{
	int i, j, k;
 	i = num / 100;
	j = num / 10 % 10;
	k = num % 10;
	*result_add += i + j + k;
	*result_mul *= i * j * k;    
}
int main()
{
	int i, j, k;
	int result_add, result_mul;
	
	for(i = 123; i <=329; i++)
	{
		j = i * 2;
		k = i * 3;
		result_add = 0;
		result_mul = 1;
	
		resultF(i, &result_add, &result_mul);
		resultF(j, &result_add, &result_mul);
		resultF(k, &result_add, &result_mul);
		if(result_add == 45 && result_mul == 362880)
			printf("%d %d %d\n", i, j, k); //9位数相加为45，相乘为362880 
	}
	return 0;
}

/*
int main()
{
	int i,j,index;
 	for(i = 123; i <=329;i++){
		int a[3];
		a[0] = i;
		a[1] = 2*i;
		a[2] = 3*i;
 
 
		int hole[10];
		for(j = 0;j<10;j++)hole[j]=0;
 
			int flag = 1;
			for(index = 0;index<3 && flag==1 ;index++){
				if(hole[a[index]%10]==0)
					hole[a[index]%10]=1;
				else
					flag=0;
				if(hole[a[index]/10 %10]==0)
					hole[a[index]/10 %10]=1;
				else
					flag=0;
				if(hole[a[index]/100]==0)
					hole[a[index]/100]=1;
				else
					flag=0;
 
			}
		if(flag==1)
     		       printf("%d %d %d\n",i,2*i,3*i);
	}
	return 0;
}
*/