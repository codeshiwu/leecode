//
// Created by 15387 on 2022/5/24.
//

#ifndef ARRAY_LEECODE_209_H
#define ARRAY_LEECODE_209_H

#include <iostream>
#include <vector>

/**
 * 题目描述：在一个正整数数组nums中找到最小长度的连续子数组，使子数组元素之和大于等于s
 * 返回满足条件的连续子数组的最小长度，如果没找到则返回0
 *
 */

// 暴力解法
int minSubArrayLen1(int target, std::vector<int>& nums)
{
    int min = INT32_MAX;
    int sum = 0;

    for (int i = 0; i < nums.size(); ++i)
    {
        sum = 0;
        for (int j = i; j < nums.size(); ++j)
        {
            sum += nums[j];
            if (sum >= target)
            {
                int len = j - i + 1;

                if (len < min)
                {
                    min = len;
                }

                break;
            }
        }
    }

    return min == INT32_MAX ? 0 : min;
}

// 双指针 滑动窗口法
int minSubArrayLen2(int target, std::vector<int>& nums)
{
    int min = INT32_MAX;
    int fast = 0;
    int slow = 0;
    int sum = 0;
    int len = 0;

    for (; fast < nums.size(); ++fast)
    {
        sum += nums[fast];

        while (sum >= target)
        {
            len = fast - slow + 1;
            min = min > len ? len : min;

            sum -= nums[slow++];
        }
    }

    return min == INT32_MAX ? 0 : min;
}

void test_209()
{
    std::vector<int> vec{2,3,1,2,4,3};

    std::cout << minSubArrayLen1(7, vec) << std::endl;
    std::cout << minSubArrayLen2(7, vec) << std::endl;
}



#endif //ARRAY_LEECODE_209_H
