/*
 * @Author: Ractive 
 * @Date: 2019-02-24 16:50:22 
 * @Last Modified by: Ractive
 * @Last Modified time: 2019-02-24 16:54:27
 */

// 今天我们要认识一对新朋友，Alice与Bob。
// Alice与Bob总是在进行各种各样的比试，今天他们在玩一个取石子的游戏。
// 在这个游戏中，Alice和Bob放置了N堆不同的石子，编号1..N，第i堆中有A[i]个石子。
// 每一次行动，Alice和Bob可以选择从一堆石子中取出任意数量的石子。至少取1颗，至多取出这一堆剩下的所有石子。
// Alice和Bob轮流行动，取走最后一个石子的人获得胜利。
// 假设每一轮游戏都是Alice先行动，请你判断在给定的情况下，如果双方都足够聪明，谁会获得胜利？

#include <iostream>
#include <vector>
#include <string>
#include <time.h>
// #include <numeric>
// #include <algorithm>

using namespace std;
bool solve(int *arr,int len){
    int res=0,i;
    for(i=0;i<len;i++){
        res^=arr[i];
    }
    return res!=0;
}
int main(int argc, char *argv[])
{
    double clockPerMillis = double(CLOCKS_PER_SEC) / 1000;
    clock_t start_Time = clock();

    int data[]={2,4,5};
    cout<<solve(data,3)<<endl;
    
    double elapsedMillis = (clock() - start_Time) / clockPerMillis;
    cout << "Program Runing with " << elapsedMillis << " ms" << endl;
    system("pause");
    return 0;
}
