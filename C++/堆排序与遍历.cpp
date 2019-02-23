/*
 * @Author: Ractive 
 * @Date: 2019-02-19 17:54:13 
 * @Last Modified by: Ractive
 * @Last Modified time: 2019-02-19 23:54:22
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int preOrder(int *arr, int index, int len)
{
    if (index >= len)
        return 0;
    cout << arr[index] << " ";
    preOrder(arr, index * 2 + 1, len);
    preOrder(arr, index * 2 + 2, len);
    return 0;
}

int inOrder(int *arr, int index, int len)
{
    if (index >= len)
        return 0;
    inOrder(arr, index * 2 + 1, len);
    cout << arr[index] << " ";
    inOrder(arr, index * 2 + 2, len);
    return 0;
}

int swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return 0;
}

int min_Heap_Fix(int *arr, int index, int len)
{
    int left = index * 2 + 1;
    int right = index * 2 + 2;
    int min = left;
    if (left >= len)
        return 0;

    if (right >= len)
        ;
    else
    {
        if (arr[left] > arr[right])
        {
            min = right;
        }
    }

    if (arr[min] >= arr[index])
        return 0;

    swap(&arr[min], &arr[index]);

    min_Heap_Fix(arr, min, len);

    return 0;
}

int min_Heap(int *arr, int len)
{
    int i;
    for (i = len / 2 - 1; i >= 0; i--)
    {
        min_Heap_Fix(arr, i, len);
    }
    return 0;
}

int heap_Sort(int *arr, int len)
{
    min_Heap(arr, len);
    int i;
    for (i = len; i > 0; i--)
    {
        swap(&arr[0], &arr[i - 1]);
        //min_Heap_Fix(arr, 0,i+1);
        min_Heap(arr,i-1);
        //大坑 BUG: min_Heap(arr,i);
        
    }
    return 0;
}

int main(int argc, char *argv[])
{

    int data[] = {1, 6, 5, 4, 3, 2,9};
    // preOrder(data, 0, 7);
    // cout << endl;
    // inOrder(data, 0, 7);
    // min_Heap(data, 7);
    // cout << endl;
    // preOrder(data, 0, 7);

    heap_Sort(data, 7);
    int i;
    for (i = 0; i < 7; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
