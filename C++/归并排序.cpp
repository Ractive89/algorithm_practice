/*
 * @Author: Ractive 
 * @Date: 2019-02-18 14:22:53 
 * @Last Modified by: Ractive
 * @Last Modified time: 2019-02-18 18:23:10
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int merger(int *arr, int p, int mid, int r)
{
    int *helper = (int *)malloc(sizeof(int) * 10);
    memcpy(helper, arr, sizeof(int) * 10);

    int left = p, right = mid + 1;
    int current = p;
    while (mid >= left && r >= right)
    {
        if (helper[left] <= helper[right])
            arr[current++] = helper[left++];

        else
            arr[current++] = helper[right++];
    }

    while (left <= mid)
        arr[current++] = helper[left++];
    delete helper;
    return 0;
}

int merger_Sort(int *arr, int p, int r)
{
    if (p < r)
    {

        int mid = p + ((r - p) >> 1);
        merger_Sort(arr, p, mid);
        merger_Sort(arr, mid + 1, r);
        merger(arr, p, mid, r);
    }
    return 0;
}
int main(int argc, char *argv[])
{

    int data[] = {4, 2, 7, 2, 6, 3, 7, 1, 0, 9};
    merger_Sort(data, 0, 9);

    int i;
    for (i = 0; i < 10; i++)
    {
        cout << data[i] << " ";
    }
    system("pause");
    return 0;
}
