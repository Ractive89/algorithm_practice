/*
 * @Author: Ractive 
 * @Date: 2019-02-20 18:48:36 
 * @Last Modified by: Ractive
 * @Last Modified time: 2019-02-20 19:13:38
 */

// 小明最近喜欢搭数字积木。一共有10块积木，每个积木上有一个数字，0~9。

// 搭积木规则：
// 每个积木放到其它两个积木的上面，并且一定比下面的两个积木数字小。
// 最后搭成4层的金字塔形，必须用完所有的积木。

// 请你计算这样的搭法一共有多少种？

//    0
//   1 2
//  3 4 5
// 6 7 8 9

#include <iostream>
#include <vector>
#include <string>
#include <time.h>
// #include <numeric>
// #include <algorithm>

using namespace std;

template <class T>
int swap_Value(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
    return 0;
}

int check_Array(int *arr, int len)
{
    if (arr[1] < arr[0] || arr[2] < arr[0] || arr[3] < arr[1])
        return -1;
    if (arr[4] < arr[1] || arr[4] < arr[2] || arr[5] < arr[2])
        return -1;
    if (arr[6] < arr[3] || arr[7] < arr[3] || arr[7] < arr[4])
        return -1;
    if (arr[8] < arr[4] || arr[8] < arr[5] || arr[9] < arr[5])
        return -1;
    return 0;
}

int  buliding_Blocks(int *arr, int k, int len,int &iter)
{
    if (k == len - 1)
    {
        if(check_Array(arr, len)!=-1)
        iter++;
    }
    int i;
    for(i=k;i<len;i++){
        swap_Value(arr[i],arr[k]);
        buliding_Blocks(arr,k+1,len,iter);
        swap_Value(arr[i],arr[k]);
    }
    return 0;
}
int main(int argc, char *argv[])
{
    double clockPerMillis = double(CLOCKS_PER_SEC) / 1000;
    clock_t start_Time = clock();

    int iter=0;
    int arr[10]={0,1,2,3,4,5,6,7,8,9};
    buliding_Blocks(arr,0,10,iter);
    cout<<iter<<endl;
    double elapsedMillis = (clock() - start_Time) / clockPerMillis;
    cout << "Program Runing with " << elapsedMillis << " ms" << endl;
    system("pause");
    return 0;
}
