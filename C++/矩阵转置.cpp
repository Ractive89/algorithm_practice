/*
 * @Author: Ractive 
 * @Date: 2019-02-20 04:48:41 
 * @Last Modified by: Ractive
 * @Last Modified time: 2019-02-20 06:07:37
 */
#include <iostream>
#include <vector>
#include <string>
#include <time.h>

using namespace std;

template <class T>
int swap_Value(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
    return 0;
}

template <class T>
int transpose(T **&arr, int rows)
{
    int i, j;
    for (i = 0; i < rows; i++)
        for (j = i + 1; j < rows; j++)
            swap_Value(arr[i][j], arr[j][i]);
    return 0;
}

template <class T>
bool malloc_Array_3D_Square(T **&arr, int rows)
{
    try
    {
        arr = new T *[rows];
        int i;
        for (i = 0; i < rows; i++)
        {
            arr[i] = new T[rows];
        }
        return true;
    }
    catch (bad_alloc)
    {
        return false;
    }
}

template <class T>
int delete_Array_3D_Square(T **arr, int rows)
{
    int i;
    for (i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    arr = NULL;
    return 0;
}

template <class T>
int Print_Array_3D_Square(T *arr, int rows)
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < rows; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}

int main(int argc, char *argv[])
{
    double clockPerMillis = double(CLOCKS_PER_SEC) / 1000;
    clock_t start_Time = clock();
    int **data, row = 3;
    int i, j;
    malloc_Array_3D_Square(data, row);
    int fill_Number = 1;
    for (i = 0; i < row; i++)
        for (j = 0; j < row; j++)
            data[j][i] = fill_Number++;
    Print_Array_3D_Square(data, row);
    transpose(data, 3);
    Print_Array_3D_Square(data, row);
    delete_Array_3D_Square(data, row);

    double elapsedMillis = (clock() - start_Time) / clockPerMillis;
    cout << "Program Runing with " << elapsedMillis << " ms" << endl;
    system("pause");
    return 0;
}
