//
// Created by 15387 on 2022/6/3.
//

#ifndef HASH_LEECODE_18_H
#define HASH_LEECODE_18_H

/**
 * 题目描述：在一个数组中，找到四个元素，使其相加等于target，问这个数组中可以找到多少个这样的四元组（四元组不可重复）
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



vector<vector<int>> fourSum(vector<int> &nums, int target) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); ++i) {
        // 注意：此处不能使用此条件，会导致判断异常 [1,-2,-5,-4,-3,3,3,5]
//        if (nums[i] > target) {
//            return result;
//        }

        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        for (int j = i + 1; j < nums.size(); ++j) {
            // 此处进行b的去重操作
            // 注意：必须是确定当前数据在之前已经出现过，因此 j > i + 1
            if (j > i + 1 && nums[j] == nums[j - 1]) {
                continue;
            }

            int left = j + 1;
            int right = nums.size() - 1;

            while (left < right) {
                // 改成这个鬼样子是为了解决 整形溢出 [1000000000, 1000000000,1000000000,1000000000]
                if (nums[i] + nums[j] > target - nums[left] - nums[right]) {
                    right--;
                } else if (nums[i] + nums[j] < target - nums[left] - nums[right]) {
                    left++;
                } else {
                    result.emplace_back(vector{nums[i], nums[j], nums[left], nums[right]});

                    while (left < right && nums[right] == nums[right - 1]) right--;
                    while (left < right && nums[left] == nums[left + 1]) left++;

                    right--;
                    left++;
                }
            }
        }
    }

    return result;
}

#endif //HASH_LEECODE_18_H
