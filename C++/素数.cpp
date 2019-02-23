/*
 * @Author: Ractive 
 * @Date: 2019-02-16 22:15:07 
 * @Last Modified by: Ractive
 * @Last Modified time: 2019-02-16 22:50:31
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    vector<long long> p={2,3,5};
    bool flag = false;
    long long i, j;
    for (j = 3; p.size()!=100002; j++)
    {
        for (i = 0; i<p.size(); i++)
        {
            flag = true;
            if (j % p[i]==0)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            p.push_back(j);
        }
        if(j%20000==0)cout<<"yes "<<j<<" for"<<p.size()<<endl;;
        flag = 0;
    }cout<<p[100001];
    cout << endl;
    
    system("pause");
    return 0;
}
