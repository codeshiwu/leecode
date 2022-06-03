//
// Created by 15387 on 2022/5/25.
//

#ifndef HASH_LEECODE_15_H
#define HASH_LEECODE_15_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

/**
 * 题目描述：在一个数组中，找到三个元素，使其相加等于0。这个数组中可以找到多少组这样的数据
 */

vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> result;

    // 对数组进行升序重组
    sort(nums.begin(), nums.end());

    // 要判断 a+b+c=0
    for (int i = 0; i < nums.size(); ++i) {
        // 第一个元素大于0， 无法凑成三元组
        if (nums[i] > 0) {
            return result;
        }

        // 去除重复的元素，因为已经保证了数组元素的有序性
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        int lft = i + 1;                // 左指针
        int rht = nums.size() - 1;      // 右指针
        while (lft < rht) {
            int sum = nums[i] + nums[lft] + nums[rht];

            if (sum > 0) {
                rht--;
            } else if (sum < 0) {
                lft++;
            } else {
                result.emplace_back(vector{nums[i], nums[lft], nums[rht]});

                // 此时找到一组可用的数据，为避免重复，因此左、右指针同时移动
                // 需要对b、c的数据进行去重 [-2,0,0,2,2]
                while(lft < rht && nums[rht] == nums[rht - 1]) rht--;
                while(lft < rht && nums[lft] == nums[lft + 1]) lft++;

                rht--; lft++;
            }
        }
    }

    return result;
}

#endif //HASH_LEECODE_15_H
