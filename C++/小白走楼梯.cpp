/*С����¥��
�ܹ��м��ַ�����n��¥��
һ����һ��
һ��������
һ��������  
*/
#include <iostream>
#include <vector>
using namespace std;

int stair(int i){
	if(i==0)return 1;
	if(i==1)return 1;
	if(i==2)return 2;
	return stair(i-1)+stair(i-2)+stair(i-3);
}
int main(int argc, char *argv[])
{
	cout<<stair(3);
	return 0;
}
