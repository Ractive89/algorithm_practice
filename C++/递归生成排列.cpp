/*
 * @Author: Ractive 
 * @Date: 2019-02-20 02:24:28 
 * @Last Modified by: Ractive
 * @Last Modified time: 2019-02-20 02:40:24
 */
#include <iostream>
#include <vector>
#include <string>
#include <iterator>

using namespace std;

template <class T> int swap(T *a, T *b)
{
    T temp = *a;
    *a = *b;
    *b = temp;
    return 0;
}

template <class T> int permutations(T *list, int k, int len,int *times=new int(0))
{
    int i;
    if (k == len - 1)
    {
        copy(list, list + len, ostream_iterator<T>(cout, ""));
        cout << endl;
        (*times)++;
    }
    else
        for (i = k; i < len; i++)
        {
            swap(&list[k],&list[i]);
            permutations(list,k+1,len,times);
            swap(&list[k],&list[i]);
        }
    return *times;
}

int main(int argc, char *argv[])
{
    int data[]={1,2,3,4,5};
    int k=permutations(data,0,5);
    cout<<endl<<"result: "<<k<<endl;

    system("pause");
    return 0;
}
