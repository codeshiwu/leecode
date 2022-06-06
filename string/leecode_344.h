//
// Created by 15387 on 2022/6/4.
//

#ifndef STRING_LEECODE_344_H
#define STRING_LEECODE_344_H

#include <iostream>
#include <vector>

using namespace std;

/**
 * 题目描述：
 *  编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。
 *  不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
 *
 * 实例：
 * 输入：s = ["h","e","l","l","o"]
 * 输出：["o","l","l","e","h"]
 */

// 方法1：使用两个指针分别遍历，一个从前往后，一个从后往前，直到相遇
void reverseString(vector<char>& s) {
    int left = 0;
    int right = s.size() - 1;
    int temp = 0;

    while (left < right)
    {
        // 互换
        temp = s[left];
        s[left] = s[right];
        s[right] = temp;

        left++;
        right--;
    }
}

#endif //STRING_LEECODE_344_H
