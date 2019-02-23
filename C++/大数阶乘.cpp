#include<iostream>
using namespace std;
void f(int n)
{
    if(n==1)
    cout<<"1";
    else
    {
        int a[100000],tail=0,head=0,p=0;
        a[0]=1;
        for(int i=2;i<=n;i++){
     	   for(int j=head;j<=tail;j++)
   		   {
			  	p=a[j]*i+p;
				a[j]=p%10;
				p=p/10;
        	}
			while(p!=0)
			{
				tail++;
				a[tail]=p%10;
				p=p/10;
			}
      }
      for(int i=tail;i>=0;i--)cout<<a[i];
    }
}
int main()
{
    int n;
    cin>>n;
    f(n);
    return 0;
}
