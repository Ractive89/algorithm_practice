/*
��10Ԫ��5Ԫ��2Ԫ��1Ԫ������ֵ������ң������100ԪǮ�ж��������
*/#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
	int total,iteral=1;
	for(int five=1;five<20;five++)
	{
		for(int two=1;two<=(100-five*5)/2;two++){
			total=100-five*5-two*2;
			if(total>0){
				cout<<"iteral="<<(iteral++)<<" "<<total<<" "<<two<<" "<<five<<endl;
			}
		}
	}
	return 0;
}
