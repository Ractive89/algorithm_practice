/*
 * @Author: Ractive 
 * @Date: 2019-02-17 12:47:21 
 * @Last Modified by: Ractive
 * @Last Modified time: 2019-02-17 14:05:52
 */

//      B      DEF
// A + --- + ------- = 10
//      C      GHI

// 这个算式中A~I代表1~9的数字，不同的字母代表不同的数字。

// 比如：
// 6+8/3+952/714 就是一种解法，
// 5+3/1+972/486 是另一种解法。

// 这个算式一共有多少种解法？

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{

    int A, B, C, D, E, F, G, H, I; //九个不重复的数字

    int sum1, sum2, sum3, sum4; //四个多项式

    int ans = 0;

    for (A = 1; A <= 9; ++A)
    {
        for (B = 1; B <= 9; ++B)
        {
            if (B == A)
                continue;
            for (C = 1; C <= 9; ++C)
            {
                if (C == A || C == B)
                    continue;
                for (D = 1; D <= 9; ++D)
                {
                    if (D == A || D == B || D == C)
                        continue;
                    for (E = 1; E <= 9; ++E)
                    {
                        if (E == A || E == B || E == C || E == D)
                            continue;
                        for (F = 1; F <= 9; ++F)
                        {
                            if (F == A || F == B || F == C || F == D || F == E)
                                continue;
                            for (G = 1; G <= 9; ++G)
                            {
                                if (G == A || G == B || G == C || G == D || G == E || G == F)
                                    continue;
                                for (H = 1; H <= 9; ++H)
                                {
                                    if (H == A || H == B || H == C || H == D || H == E || H == F || H == G)
                                        continue;
                                    for (I = 1; I <= 9; ++I)
                                    {
                                        if (I == A || I == B || I == C || I == D || I == E || I == F || I == G || I == H)
                                            continue;

                                        sum1 = A * C * (G * 100 + H * 10 + I);
                                        sum2 = B * (G * 100 + H * 10 + I);
                                        sum3 = (D * 100 + E * 10 + F) * C;
                                        sum4 = 10 * C * (G * 100 + H * 10 + I);
                                        //注意，要将题中的等式通分
                                        if (sum1 + sum2 + sum3 == sum4)
                                        {

                                            ++ans;
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

    cout << ans << endl;
    system("pause");
    return 0;
}
