/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现strStr()
 *
 * https://leetcode-cn.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (37.58%)
 * Total Accepted:    36.2K
 * Total Submissions: 96.2K
 * Testcase Example:  '"hello"\n"ll"'
 *
 * 实现 strStr() 函数。
 * 
 * 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置
 * (从0开始)。如果不存在，则返回  -1。
 * 
 * 示例 1:
 * 
 * 输入: haystack = "hello", needle = "ll"
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: haystack = "aaaaa", needle = "bba"
 * 输出: -1
 * 
 * 
 * 说明:
 * 
 * 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
 * 
 * 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
 * 
 */
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
// #include <numeric>
// #include <algorithm>

using namespace std;

static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    int strStr(string haystack, string needle) {
        int nSizeH = haystack.size();
        int nSizeN = needle.size();
        if(!nSizeN) return 0;
        if(nSizeH<nSizeN) return -1;
        for(int i=0; i<nSizeH, nSizeH-i>=nSizeN; i++)
        {
            if(haystack[i]==needle[0])
            {
                int j=1;
                for(; j<nSizeN; j++)
                {
                    if(haystack[i+j] != needle[j])
                        break;
                }
                if(j>=nSizeN) return i;
            }
        }
        return -1;
    }
};
