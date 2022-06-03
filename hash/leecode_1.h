//
// Created by 15387 on 2022/5/25.
//

#ifndef HASH_LEECODE_1_H
#define HASH_LEECODE_1_H

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * 题目描述：在数组中找到两个元素的数值之和为目标值，返回这两个数的下标
 */

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;

    for (int i = 0; i < nums.size(); ++i) {
        map[nums[i]] = i;
    }

    for (int i = 0; i < nums.size(); ++i) {
        if (map.find(target - nums[i]) != map.end() && i != map[target - nums[i]]) {
            return {i, map[target - nums[i]]};
        }
    }

    return {};
}

#endif //HASH_LEECODE_1_H
