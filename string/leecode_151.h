//
// Created by 15387 on 2022/6/4.
//

#ifndef STRING_LEECODE_151_H
#define STRING_LEECODE_151_H

/*
 题目描述：
    给你一个字符串 s ，颠倒字符串中 单词 的顺序。
    单词是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的单词分隔开。
    返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。
    注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。

 实例：
    输入：s = "  hello world  "
    输出："world hello"
    解释：颠倒后的字符串中不能存在前导空格和尾随空格。
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 时间复杂度为O(n) 空间复杂度为O(n)
string reverseWords(string s) {
    vector<string> vec;
    string result = "";

    for (int i = 0; i < s.size() + 1; ++i) {
        if (s[i] == ' ' || s[i] == '\0') {
            if (!result.empty()) {
                vec.push_back(result);
                result.clear();
            }
            continue;
        }

        result.push_back(s[i] );
    }

    result.clear();
    for (int i = vec.size() - 1; i >= 0; --i) {
        result += vec[i];
        result += (i == 0 ? "" : " ");
    }

    return result;
}

/*
 原地替换步骤如下：
   1.删除多余空格
   2.翻转整个字符串
   3.翻转单个单词
 */
string reverseWords1(string s) {
    // 1. 删除多余空格
    int fast = 0, slow = 0;   // 快慢指针

    // 删除字符串开头的空格
    while (fast < s.size() && s[fast] == ' ') {
        fast++;
    }

    // 删除剩下的字符串的多余空格（注意：若是原字符串末尾有空格，则会多赋值一个空格）
    for (; fast < s.size(); ++fast) {
        if (s[fast] == ' ' && s[fast - 1] == ' ' && fast > 0) {
            // 找到多余空格
            continue;
        }

        s[slow++] = s[fast];
    }

    // 删除末尾的多余空格
    if (s[s.size() - 1] == ' ') {
        slow--;
    }
    s.resize(slow);

    // 2. 翻转整个字符串
    reverse(s.begin(), s.end());

    // 3. 翻转字符串中的各单词
    int beg = 0, end = 0;
    for (int i = 0; i <= s.size(); ++i) {
        if (s[i] == ' ' || s[i] == '\0') {
            end = i - 1;
        } else {
            continue;
        }

        // 翻转单词
        while (beg < end) {
            s[beg] ^= s[end];
            s[end] ^= s[beg];
            s[beg] ^= s[end];

            beg++; end--;
        }

        // 重置 beg end
        beg = i + 1;
    }

    return s;
}

#endif //STRING_LEECODE_151_H
