/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 *
 * https://leetcode-cn.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (31.81%)
 * Total Accepted:    50.8K
 * Total Submissions: 159.6K
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 示例 1:
 * 
 * 输入: ["flower","flow","flight"]
 * 输出: "fl"
 * 
 * 
 * 示例 2:
 * 
 * 输入: ["dog","racecar","car"]
 * 输出: ""
 * 解释: 输入不存在公共前缀。
 * 
 * 
 * 说明:
 * 
 * 所有输入只包含小写字母 a-z 。
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
class Solution
{
  public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string out = "";
        if (strs.empty())
            return out;

        bool end = false;
        char temp;
        for (int i = 0; end == false; i++)
        {
            temp = strs[0][i];
            if (temp == '\0')
                break;

            for (int j = 0; j < strs.size(); j++)
            {
                if (temp != strs[j][i])//不等于就退出
                {
                    end = true;
                    break;
                }
            }

            if (end == false)
                out += temp;
        }
        return out;
    }
};
