/*
 * @Author: Ractive 
 * @Date: 2019-02-15 19:40:43 
 * @Last Modified by: Ractive
 * @Last Modified time: 2019-02-15 22:31:02
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int swap(int *a, int *b) //交换
{
    int temp = *a;
    *a = *b;
    *b = temp;

    return 0;
}

int print_List(int *arr, int lenth) //打印列表
{
    int i;
    for (i = 0; i < lenth; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
    for (i = 0; i < lenth; i++)
    {
        cout << i << "\t";
    }
    cout << "\n"
         << endl;
    return 0;
}

int pivot_Middle(int *arr, int p, int r) //减少出现最坏情况
{
    int mid = p + ((r - p) >> 1);
    if (arr[p] > arr[r] && arr[mid] > arr[p])
    {
        return p;
    }
    else if (arr[r] > arr[p] && arr[mid] > arr[r])
    {
        return r;
    }
    else
        return mid;
}

int partition_OnePoint(int *arr, int p, int r)
{
    int midIndex = pivot_Middle(arr, p, r);
    int pivot = arr[midIndex];
    int sp = p + 1, bigger = r;
    while (sp <= bigger)
    {
        if (arr[sp] <= pivot)
            sp++;
        else
        {
            swap(&arr[sp], &arr[bigger]);
            bigger--;
        }
    }
    swap(&arr[p], &arr[bigger]);
    return bigger;
}

int partition_TwoPoint(int *arr, int p, int r)
{
    int midIndex = pivot_Middle(arr, p, r);
    int pivot = arr[midIndex];
    int left = p + 1, right = r;
    while (left <= right)
    {
        while (left <= right && arr[left] <= arr[p])
            left++;
        while (left <= right && arr[right] > arr[p])
            right--;
        if (left < right)
            swap(&arr[left], &arr[right]);
    }
    swap(&arr[p], &arr[right]);
    return right;
}

int insert_Sort(int *arr, int p, int r)
{
    int j;
    for (int j = p + 1; j <= r; j++)
    {
        int key = arr[j];
        int pre = j - 1;
        while (pre >= p && arr[pre] > key)
        {
            arr[pre + 1] = arr[pre];
            pre--;
        }
        arr[pre + 1] = key;
    }
    return 0;
}

int quick_Sort(int *arr, int p, int r)
{

    if (p < r)
    {
        if (r - p + 1 <= 8)
            insert_Sort(arr, p, r);
        //print_List(arr, len);
        //int q = partition_OnePoint(arr, p, r);
        int q = partition_TwoPoint(arr, p, r);
        quick_Sort(arr, p, q - 1);
        quick_Sort(arr, q + 1, r);
    }
    return 0;
}

int len = 10;

int main(int argc, char *argv[])
{

    int arr[] = {7, 4, 3, 7, 7, 7, 9, 0, 1, 2};

    quick_Sort(arr, 0, len - 1);
    print_List(arr, len);
    system("pause");
    return 0;
}
