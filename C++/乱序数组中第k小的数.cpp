/*
 * @Author: Ractive 
 * @Date: 2019-02-18 23:58:22 
 * @Last Modified by: Ractive
 * @Last Modified time: 2019-02-19 00:36:43
 */
#include <iostream>
#include <assert.h>

using namespace std;

int swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return 0;
}
int partition(int *arr, int p, int r)
{
    int import_num = arr[p];
    int import_index = p;
    int i = p + 1, j = r;
    while (i <= j)
    {
        while (arr[i] <= import_num && i <= j)
            i++;
        while (import_num < arr[j] && i <= j)
            j--;
        if (i <= j)
            swap(&arr[i], &arr[j]);
    }
    swap(&arr[j], &arr[import_index]);
    return j;
}
int selectK(int *arr, int p, int r, int k)
{
    int index_of_import = partition(arr, p, r);
    int number_of_import = index_of_import - p + 1;
    //cout << index_of_import << endl;
    if (number_of_import == k)
        return arr[index_of_import];
    else if (number_of_import > k)
    {
        return selectK(arr, p, index_of_import - 1, k);
    }
    else
    {
        return selectK(arr, index_of_import + 1, r, k - number_of_import);
    }
}
int main(int argc, char *argv[])
{

    int data[] = {1, 6, 7, 3, 5, 2, 0, 11, 4};
    int results = selectK(data, 0, 8, 3);
    assert(results == 2);//断言  
    cout << results << endl;
    system("pause");
    return 0;
}
