/*
 * @Author: Ractive 
 * @Date: 2019-02-21 21:48:09 
 * @Last Modified by: Ractive
 * @Last Modified time: 2019-02-22 02:23:49
 */

// 机器人走方格
// 有一个XxY的网格，一个机器人只能走格点且只能向右或向下走，要从左上角走到右下角。

// 请设计一个算法，计算机器人有多少种走法。
// 给定两个正整数int x,int y，请返回机器人的走法数目。
// 保证x＋y小于等于12。

#include <iostream>
#include <vector>
#include <string>
#include <time.h>
// #include <numeric>
// #include <algorithm>

using namespace std;

int walk_In_Mesh(int x, int y)
{
    if (x == 1 || y == 1)
        return 1;
    return walk_In_Mesh(x - 1, y) + walk_In_Mesh(x, y - 1);
}

int walk_In_Mesh_Iteration(int m, int n)
{
    int i, j;

    int **array = new int *[n + 1];
    for (i = 0; i < n + 1; ++i)
    {
        array[i] = new int[m + 1]{1, 1};
    }

    for (j = 1; j < n + 1; j++)
    {
        array[1][j] = 1;
    }

    for (i = 2; i <= m; i++)
    {
        for (j = 2; j <= n; j++)
        {
            array[i][j] = array[i][j - 1] + array[i - 1][j];
        }
    }
    int count = array[m][n];

    // for (int i = 1; i <= m; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout << array[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    return count;
}

int main(int argc, char *argv[])
{
    double clockPerMillis = double(CLOCKS_PER_SEC) / 1000;
    clock_t start_Time = clock();
    int data;

    //cout << walk_In_Mesh(4, 4) << endl;
    cout << walk_In_Mesh_Iteration(6, 6)<<endl;

    double elapsedMillis = (clock() - start_Time) / clockPerMillis;
    cout << "Program Runing with " << elapsedMillis << " ms" << endl;
    system("pause");
    return 0;
}
