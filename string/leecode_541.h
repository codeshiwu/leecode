//
// Created by 15387 on 2022/6/4.
//

#ifndef STRING_LEECODE_541_H
#define STRING_LEECODE_541_H

/*
 题目描述：
 给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。
 如果剩余字符少于 k 个，则将剩余字符全部反转。
 如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。

 实例：
 输入：s = "abcdefg", k = 2
 输出："bacdfeg"
 */

#include <iostream>
#include <string>

using namespace std;

/*
 解题思路：利用2k将字符串分为好几段，挨个对每个字符串段进行处理

 实际情况划分： s.size <= K            -> 翻转整个字符串
             k < s.size <= 2k       -> 翻转前k个字符
             k > 2k                 -> 长度为前2k的字符串翻转前k个字符，剩下的翻转前k个字符

 */

string reverseStr(string s, int k) {
    int l1 = s.size() / (2 * k);
    int l2 = s.size() % (2 * k);
    int max = s.size() - 1;

    for (int i = 0; i <= l1; ++i) {
        int beg = i * 2 * k;
        int end = beg + k - 1 > max ? max : beg + k - 1;

        while (beg < end)
        {
            // 互换
            s[beg] ^= s[end];
            s[end] ^= s[beg];
            s[beg] ^= s[end];

            beg++;
            end--;
        }
    }
    return s;
}

#endif //STRING_LEECODE_541_H
