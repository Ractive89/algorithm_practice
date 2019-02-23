/*
 * @Author: Ractive 
 * @Date: 2019-02-20 15:40:35 
 * @Last Modified by: Ractive
 * @Last Modified time: 2019-02-20 16:17:29
 */
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
// #include <numeric>
// #include <algorithm>

using namespace std;

int *find_Segment_Up(int *arr, int n)
{
    int p1 = -1, p2 = -1;
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (i < n - 1 && arr[i] > arr[i + 1] && p1 == -1)
        {
            p1 = i;
            if (arr[i] > max)
                max = arr[i];
        }
        //右面排序
        if (arr[i] < max)
            p2 = i;
    }
    if (p1 == -1)
        return new int[2]{0, 0};
    return new int[2]{p1, p2};
}

int *find_Segment_Down(int *arr, int n)
{
    int p1 = -1, p2 = -1;
    int min = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (i < n - 1 && arr[i] < arr[i + 1] && p1 == -1)
        {
            p1 = i;
            if (arr[i] < min)
                min = arr[i];
        }
        if (arr[i] > min)
            p2 = i;
    }
    if (p1 == -1)
        return new int[2]{0, 0};
    return new int[2]{p1, p2};
}

int *find_Segment(int *arr, int n)
{
    int *up_res = find_Segment_Up(arr, n);
    int *down_res = find_Segment_Down(arr, n);
    if ((up_res[1] - up_res[0]) > (down_res[1] - down_res[0]))
        return new int[3] {-1,down_res[0],down_res[1]};
    return new int[3] {1,up_res[0],up_res[1]};
}

int main(int argc, char *argv[])
{
    double clockPerMillis = double(CLOCKS_PER_SEC) / 1000;
    clock_t start_Time = clock();
    int data[] = {8, 7, 6, 5, 4, 3, 9};
    //int *arr = find_Segment(data, 7);
    //cout << arr[0] << " " << arr[1] << endl;
    int *res=find_Segment(data,7);
    cout << res[0] << " " << res[1] <<" "<< res[2]<<endl;

    double elapsedMillis = (clock() - start_Time) / clockPerMillis;
    cout << "Program Runing with " << elapsedMillis << " ms" << endl;
    system("pause");
    return 0;
}
