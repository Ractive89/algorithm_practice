/*
 * @Author: Ractive 
 * @Date: 2019-02-20 06:17:29 
 * @Last Modified by: Ractive
 * @Last Modified time: 2019-02-20 07:19:11
 */

#include <iostream>
#include <vector>
#include <string>
#include <time.h>
// #include <numeric>
// #include <algorithm>
#pragma GCC diagnostic ignored "-Wreturn-type"

using namespace std;

template <class T>
int swap_Value(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
    return 0;
}

int binary_search(int *arr, int l, int r, int k)
{
    int mid = l + ((r - l) >> 1);
    if (l > r)
        return -1;

    if (k == arr[mid])
        return mid;
    else if (k > arr[mid])
        binary_search(arr, mid + 1, r, k);
    else
        binary_search(arr, l, mid - 1, k);
}

bool num_Is_In_Array(int *arr, int len, int k)
{
    int i;
    for (i = 0; i < len; i++)
    {
        if (arr[i] == k)
            return true;
    }
    return false;
}

pair<vector<int>, vector<int>> couple_Add_Equal_Array(int *arr, int len, int k)
{
    pair<vector<int>, vector<int>> result;
    int i;
    for (i = 0; i < len; i++)
    {
        if (arr[i] + arr[len - 1] < k)
            continue;
        int half = k - arr[i];
        int half_index = binary_search(arr, 0, len - 1, half);
        if (half_index == -1 || i == half_index)
            continue;
        if (num_Is_In_Array(arr, i, half))
            continue;
        result.first.push_back(arr[i]);
        result.second.push_back(arr[half_index]);
    }
    return result;
}

int main(int argc, char *argv[])
{
    double clockPerMillis = double(CLOCKS_PER_SEC) / 1000;
    clock_t start_Time = clock();
    int data[] = {-8, -4, -3, 0, 2, 4, 5, 6, 8, 9, 10};
    int len = 11, i;

    pair<vector<int>, vector<int>> res = couple_Add_Equal_Array(data, len, 10);
    for (i = 0; i < res.first.size(); i++)
    {
        cout << "(" << res.first[i] << " , " << res.second[i] << ")" << endl;
    }
    double elapsedMillis = (clock() - start_Time) / clockPerMillis;
    cout << "Program Runing with " << elapsedMillis << " ms" << endl;
    system("pause");
    return 0;
}
