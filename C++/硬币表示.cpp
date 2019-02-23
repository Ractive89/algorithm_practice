/*
 * @Author: Ractive 
 * @Date: 2019-02-22 04:52:53 
 * @Last Modified by: Ractive
 * @Last Modified time: 2019-02-23 10:03:39
 */

// 硬币表示
// 假设我们有8种不同面值的硬币｛1，2，5，10，20，50，100，200｝
// 用这些硬币组合够成一个给定的数值n。

// 例如n=200，那么一种可能的组合方式为 200 = 3 1 + 1＊2 + 1＊5 + 2＊20 + 1 50 + 1 * 100
// 问总共有多少种可能的组合方式？

#include <iostream>
#include <vector>
#include <string>
#include <time.h>
// #include <numeric>
// #include <algorithm>

using namespace std;

int count_Ways_Core(int n, int cur, int *coins)
{
    if (cur == 0)
        return 1;
    int i;
    int res = 0;
    for (i = 0; i * coins[cur] <= n; i++)
    {
        int last = n - i * coins[cur];
        res += count_Ways_Core(last, cur - 1, coins);
    }
    return res;
}

int count_Ways(int n, int cur, int *coins)
{
    if (n <= 0)
        return 0;
    return count_Ways_Core(n, cur, coins);
}

int main(int argc, char *argv[])
{
    double clockPerMillis = double(CLOCKS_PER_SEC) / 1000;
    clock_t start_Time = clock();
    int data;
    int *coins = new int[6]{1, 5, 10, 20, 50, 100};
    cout << count_Ways(15, 2, coins);
    double elapsedMillis = (clock() - start_Time) / clockPerMillis;
    cout << "Program Runing with " << elapsedMillis << " ms" << endl;
    system("pause");
    return 0;
}
