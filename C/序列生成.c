/*
序列生成算法：从整数 n 开始，如果 n 是偶数，把它除以 2；如果 n 是奇数，把它乘 3 加1。用新得到的值重复上述步骤，直到 n = 1 时停止。例如，n = 22 时该算法生成的序列是：
22，11，34，17，52，26，13，40，20，10，5，16，8，4，2，1
人们猜想（没有得到证明）对于任意整数 n，该算法总能终止于 n = 1。这个猜想对于至少 1 000 000内的整数都是正确的
对于给定的 n，该序列的元素（包括 1）个数被称为 n 的循环节长度。在上述例子中，22 的循环节长度为 16。输入两个数 i 和 j，你的任务是计算 i 到 j（包含 i 和 j）之间的整数中，循环节长度的最大值。

输入
输入每行包含两个整数 i 和 j。所有整数大于 0，小于 1 000 000。

样例输入：
1 10
100 200
201 210
900 1000

样例输出：
1 10 20
100 200 125
201 210 89
900 1000 174
*/
#include <stdio.h>
int iRoute(int rag){	//返回最大循环路径
	int count=1;
	for(;rag!=1;count++){
		if(rag%2==0)rag=rag/2;
		else rag=rag*3+1;
	}	
	return count;
}

int swap(int *i,int *j){	//交换
	int temp=*i;
	*i=*j;
	*j=temp;
	return 0;
}

int main(int argc,char* argv[]){
	int i,j;
	while(scanf_s("%d%d",&i,&j)&&i>0&&j>0&&i<1000000&&j<1000000){//输入检测
		if (i>j)swap(&i,&j);//如果i大于j，交换
		int rag,max=0,temp;
		for(rag=i;rag<=j;rag++){
			temp=iRoute(rag);
			if(temp>max)max=temp;//留下最大循环节长度
		}
		printf("%d %d %d\n",i,j,max);
	}
	return 0;
}