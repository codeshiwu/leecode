//
// Created by 15387 on 2022/5/25.
//

#ifndef HASH_LEECODE_349_H
#define HASH_LEECODE_349_H

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/**
 * 题目描述：计算两个数组的交集，交集里的元素都是唯一的
 */

// 暴力解法
vector<int> intersection_1(vector<int>& nums1, vector<int>& nums2) {
    unordered_set set1(nums1.begin(), nums1.end());
    unordered_set set2(nums2.begin(), nums2.end());

    vector<int> vec;

    for (int val1 : set1) {
        for (int val2 : set2) {
            if (val1 == val2) {
                vec.push_back(val1);
                break;
            }
        }
    }

    return vec;
}

vector<int> intersection_2(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> set_rst;
    unordered_set<int> set_nums(nums1.begin(), nums1.end());

    for (int val : nums2)
    {
        if (set_nums.find(val) != set_nums.end()) {
            set_rst.insert(val);
        }
    }

    return vector<int>{set_rst.begin(), set_rst.end()};
}

#endif //HASH_LEECODE_349_H
