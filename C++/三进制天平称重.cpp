/*
 * @Author: Ractive 
 * @Date: 2019-02-23 10:04:19 
 * @Last Modified by: Ractive
 * @Last Modified time: 2019-02-23 14:10:31
 */

// 用天平称重时，我们希望用尽可能少的砝码组合称出尽可能多的重量。
// 如果只有5个砝码，重量分别是1，3，9，27，81
// 则它们可以组合称出1到121之间任意整数重量
// （砝码允许放在左右两个盘中）。

// 本题目要求编程实现：对用户给定的重量，给出砝码组合方案。
// 例如：
// 用户输入：
// 5
// 程序输出：
// 9-3-1
// 用户输入：
// 19
// 程序输出：
// 27-9+1

#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <math.h>
#include <numeric>
#include <algorithm>

#define N 500

using namespace std;

int balance(int n)
{
    char *s = new char[N];
    _itoa(n, s, 3);
    string str = s;
    reverse(str.begin(), str.end());

    vector<int> arr;
    // arr.resize(s.length());
    // arr.assign(s.begin(),s.end());
    //倒序存入

    int i;
    for (i = 0; i < str.length(); i++)
    {
        if (str[i] == '2')
        {
            arr.insert(arr.begin(), -1);
            if (i == str.length() - 1)
                arr.insert(arr.begin(), 1);

            else
                str[i + 1]++;
        }
        else if (str[i] == '3')
        {
            arr.insert(arr.begin(), 0);
            if (i == str.length() - 1)
                arr.insert(arr.begin(), 1);
            else
                str[i + 1]++;
        }
        else
            arr.insert(arr.begin(), str[i] - '0');
    }

    string res;
    for (i = 0; i < arr.size(); i++)
    {
        int bit = pow(3, arr.size() - i - 1);
        if (arr[i] == 1)
        {
            res.append("+");
            res.append(to_string(bit));
        }
        if (arr[i] == -1)
        {
            res.append("-");
            res.append(to_string(bit));
        }
    }
    res.erase(res.begin());
    cout << res.substr() << endl;

    return 0;
}

int balance_Violent_Cracking(int n)
{
    int size = 10;
    int usually[] = {0, 1, -1};
    int *bit = new int[size]{0};
    int *multi = new int[size]{0};
    for (bit[0] = 0; bit[0] < 3; bit[0]++)
    {
        multi[0] = pow(3, 0) * usually[bit[0]];
        for (bit[1] = 0; bit[1] < 3; bit[1]++)
        {
            multi[1] = pow(3, 1) * usually[bit[1]];
            for (bit[2] = 0; bit[2] < 3; bit[2]++)
            {
                multi[2] = pow(3, 2) * usually[bit[2]];
                for (bit[3] = 0; bit[3] < 3; bit[3]++)
                {
                    multi[3] = pow(3, 3) * usually[bit[3]];
                    for (bit[4] = 0; bit[4] < 3; bit[4]++)
                    {
                        multi[4] = pow(3, 4) * usually[bit[4]];
                        for (bit[5] = 0; bit[5] < 3; bit[5]++)
                        {
                            multi[5] = pow(3, 5) * usually[bit[5]];
                            for (bit[6] = 0; bit[6] < 3; bit[6]++)
                            {
                                multi[6] = pow(3, 6) * usually[bit[6]];
                                for (bit[7] = 0; bit[7] < 3; bit[7]++)
                                {
                                    multi[7] = pow(3, 7) * usually[bit[7]];
                                    for (bit[8] = 0; bit[8] < 3; bit[8]++)
                                    {
                                        multi[8] = pow(3, 8) * usually[bit[8]];
                                        for (bit[9] = 0; bit[9] < 3; bit[9]++)
                                        {
                                            multi[9] = pow(3, 9) * usually[bit[9]];
                                            int i, res = 0;
                                            for (i = 0; i < size; i++)
                                            {
                                                res += multi[i];
                                            }
                                            if (res == n)
                                            {
                                                for (i = size-1; i >-1; i--)
                                                {
                                                    if (multi[i]>0){
                                                        cout<<"+"<<multi[i];
                                                    }
                                                    if(multi[i]<0){
                                                        cout<<multi[i];
                                                    }
                                                }
                                                cout << endl;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

int main(int argc, char *argv[])
{
    double clockPerMillis = double(CLOCKS_PER_SEC) / 1000;
    clock_t start_Time = clock();
    int data = 13425;
    //balance(data);
    balance_Violent_Cracking(data);
    double elapsedMillis = (clock() - start_Time) / clockPerMillis;
    cout << "Program Runing with " << elapsedMillis << " ms" << endl;
    system("pause");
    return 0;
}
