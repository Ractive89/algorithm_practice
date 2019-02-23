/*
 * @Author: Ractive 
 * @Date: 2019-02-17 14:07:03 
 * @Last Modified by: Ractive
 * @Last Modified time: 2019-02-17 14:07:52
 */

// 煤球数目

// 有一堆煤球，堆成三角棱锥形。具体：
// 第一层放1个，
// 第二层3个（排列成三角形），
// 第三层6个（排列成三角形），
// 第四层10个（排列成三角形），
// ....
// 如果一共有100层，共有多少个煤球？

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{

    int s = 0, a = 0;
    for (int i = 1; i <= 100; i++)
    {
        a = a + i;
        s = s + a;
    }
    cout << s << endl;
    system("pause");
    return 0;
}
