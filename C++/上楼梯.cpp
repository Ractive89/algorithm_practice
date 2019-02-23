/*
 * @Author: Ractive 
 * @Date: 2019-02-21 21:22:23 
 * @Last Modified by: Ractive
 * @Last Modified time: 2019-02-21 22:23:17
 */

// 有个小孩正在上楼梯，楼梯有n阶台阶，小孩一次可以上1阶、2阶、3阶。

// 请实现一个方法，计算小孩有多少种上楼的方式。
// 为了防止溢出，请将结果Mod 1000000007

// 给定一个正整数int n，请返回一个数，代表上楼的方式数。
// 保证n小于等于100000。

#include <iostream>
#include <vector>
#include <string>
#include <time.h>
// #include <numeric>
// #include <algorithm>

using namespace std;

int walk_stair(int n)
{
    int mod = 1000000007;
    if (n == 3)
        return 4;
    if (n == 2)
        return 2;
    if (n == 0 || n == 1)
        return 1;

    return walk_stair(n - 3) % mod + walk_stair(n - 2) % mod + walk_stair(n - 1) % mod;
}

int walk_stair_iteration(int n)
{
    if (n == 3)
        return 4;
    if (n == 2)
        return 2;
    if (n == 0 || n == 1)
        return 1;
    int x1 = 1, x2 = 2, x3 = 4;
    int mod = 1000000007;
    int i;

    for (i = 4; i <= n; i++)
    {
        int x1_temp=x1%mod;
        x1 =x2%mod;
        x2=x3%mod;
        x3=((x1+x2)%mod+x1_temp)%mod;
    }
    return x3;
}

int main(int argc, char *argv[])
{
    double clockPerMillis = double(CLOCKS_PER_SEC) / 1000;
    clock_t start_Time = clock();
    int data = 4;

    cout << walk_stair_iteration(data) << endl;

    double elapsedMillis = (clock() - start_Time) / clockPerMillis;
    cout << "Program Runing with " << elapsedMillis << " ms" << endl;
    system("pause");
    return 0;
}
