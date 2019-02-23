/*
 * @Author: Ractive 
 * @Date: 2019-02-17 12:37:20 
 * @Last Modified by: Ractive
 * @Last Modified time: 2019-02-17 12:48:12
 * 
 */

// 生日蜡烛

// 某君从某年开始每年都举办一次生日party，并且每次都要吹熄与年龄相同根数的蜡烛。

// 现在算起来，他一共吹熄了236根蜡烛。

// 请问，他从多少岁开始过生日party的？

// 请填写他开始过生日party的年龄数。

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{

    int i, j, k;
    int a[70];
    for (i = 0; i < 70; i++)
    {
        a[i] = i;
    }
    for (j = 1; j < 69; j++)
    {
        for (k = j + 1; k < 70; k++)
        {
            int res = 0;
            for (i = j; i <= k; i++)
            {
                res = res + a[i];
            }
            if (res == 236)
                cout << a[j] << " " << a[k] << endl;
        }
    }

    system("pause");
    return 0;
}
