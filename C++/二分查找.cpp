/*
 * @Author: Ractive 
 * @Date: 2019-02-20 06:43:12 
 * @Last Modified by:   Ractive 
 * @Last Modified time: 2019-02-20 06:43:12 
 */

#include <iostream>
#include <vector>
using namespace std;

int fBinary_Search(int *arr, int low, int high, int key)
{
	if (low > high)
		return -1;
	int mid = low + ((high - low) >> 1);
	int midVal = arr[mid];
	cout << mid << endl;
	if (midVal > key)
		fBinary_Search(arr, low, mid, key);
	else if (midVal < key)
		fBinary_Search(arr, mid, high, key);
	else
		return mid;
}
int main(int argc, char *argv[])
{
	int arr[10000];
	int i;
	for (i = 0; i < 10000; i++)
	{
		arr[i] = i + 1;
	}
	int k = fBinary_Search(arr, 0, 10000, 3);
	cout << k;
	return 0;
}
