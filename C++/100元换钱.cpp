/*
有10元，5元，2元，1元四种面值的人民币，问组成100元钱有多少种组合
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
