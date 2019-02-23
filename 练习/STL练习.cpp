/*
 * @Author: Ractive 
 * @Date: 2019-02-20 02:43:09 
 * @Last Modified by: Ractive
 * @Last Modified time: 2019-02-20 06:14:26
 */
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <utility>  //pair

using namespace std;

bool select(int value)
{
    return value >3;
}

int main(int argc, char *argv[])
{

    vector<int> data({2, 3, 5, 7, 8});

    //accumulate
    //numeric库内
    //accumulate(start , end , initialValue , operator);
    int the_Sum = 0;
    cout << accumulate(data.begin(), data.end(), the_Sum) << endl;
    //将data内元素相加
    int the_Multiplies = 1;
    cout << accumulate(data.begin(), data.end(), the_Multiplies, multiplies<int>()) << endl;
    //将data内元素相乘

    //copy
    //copy(start, end, to);
    //把元素从start到end依次复制给位置to

    //copy(list, list+len, ostream_iterator<T>(cout, ""));
    //把元素list[0,len-1]复制到输出流cout且每个元素都跟着一个""
    //ostream_iterator需要#include <iterator>

    //next_permutation
    //algorithm库内
    //next_permutation(start, end, compare);
    //对范围[start,end)的元素，按字典排序，排列存在返回true
    int  i=1;
    while(next_permutation(data.begin(), data.end()))i++;
    cout<<i<<endl;

    //is_sorted
    //bool is_sorted (first, last, Compare comp);
    //测试范围内的元素是否已经有序

    //inner_product
    //numeric库内
    //inner_product(first1,last1,first2,init,operator);
    //计算[firtst1,last1)和[first2, first2+(last1-first1))的一般内积+init
    cout << inner_product(data.begin(), data.end(), data.begin(), 10) << endl;

    //mismatch
    //mismatch (first1, last1, first2, BinaryPredicate pred);
    //查找两个序列中第一对不匹配的元素。第一个序列为[first1.last1),第二个序列从first2开始
    auto arr=mismatch(data.begin(),data.end()-3,data.begin());
    cout<<*arr.first<<" "<<*arr.second<<endl;

    //count
    //algorithm库内
    //count(begin, end, searchValue);
    //返回begin到end中searchValue出现的次数
    int searchValue=3;
    int p=count(data.begin(), data.end(), searchValue);
    cout<<p<<endl;

    //count_if
    //countif(begin, end, Predicate _Pred);
    //用户自定义的 predicate function object ，定义了元素被计数需满足的条件 
    //predicate 只带一个参数，返回 true 或 false.
    //满足断言 predicate 指定条件的元素数。
    p=count_if(data.begin(), data.end(), select);
    cout<<p<<endl;

    //fill
    //fill(start, end, value);
    //用value填充数组从start到end

    system("pause");
    return 0;
}
