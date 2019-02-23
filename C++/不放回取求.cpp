/*
 * @Author: Ractive 
 * @Date: 2019-02-20 19:26:17 
 * @Last Modified by: Ractive
 * @Last Modified time: 2019-02-20 19:36:42
 */

#include <iostream>
#include <vector>
#include <string>
#include <time.h>
// #include <numeric>
// #include <algorithm>

using namespace std;

int take_Ball(int m, int n)
{
    if (m == n)
        return 1;
    if (n == 0)
        return 1;
    return take_Ball(m - 1, n) + take_Ball(m - 1, n - 1);
// 举个例子，如果从4个球里，取出3个。
// 那么所有的取法，等于3个球里取2个的所有取法，加上3个球里取3个的所有取法。
// 4个球里取3个。a,b,c,d，一共有abc,abd,acd,bcd 四种取法。

// 3个球里取2个，a,b,c ，一共有ab,ac,bc三种。
// 3个球里取3个，a,b,c，一共有abc一种取法。
// 两边相等的，公式是成立的。
}

int main(int argc, char *argv[])
{
    double clockPerMillis = double(CLOCKS_PER_SEC) / 1000;
    clock_t start_Time = clock();
    int data = take_Ball(5, 3);
    cout << data << endl;

    double elapsedMillis = (clock() - start_Time) / clockPerMillis;
    cout << "Program Runing with " << elapsedMillis << " ms" << endl;
    system("pause");
    return 0;
}
