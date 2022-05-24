//
// Created by 15387 on 2022/5/24.
//

#ifndef ARRAY_LEECODE_704_H
#define ARRAY_LEECODE_704_H

/**
 * leecode题目：二分查找
 */

#include <iostream>
#include <vector>

// 左闭右开
int search1(std::vector<int> &nums, int target)
{
    std::size_t beg = 0;
    std::size_t end = nums.size();
    std::size_t mid = 0;

    while (beg < end) {
        mid = beg + (end - beg) / 2;

        if (nums[mid] > target)
        {
            end = mid;
        }
        else if (nums[mid] < target)
        {
            beg = mid + 1;
        }
        else
        {
            return mid;
        }
    }

    return -1;
}

// 左闭右闭
int search2(std::vector<int> &nums, int target)
{
    std::size_t beg = 0;
    std::size_t end = nums.size() - 1;
    std::size_t mid = 0;

    while (beg <= end) {
        mid = beg + (end - beg) / 2;

        if (nums[mid] > target)
        {
            end = mid - 1;
        }
        else if (nums[mid] < target)
        {
            beg = mid + 1;
        }
        else
        {
            return mid;
        }
    }

    return -1;
}

bool test704()
{
    std::vector<int> vec{1,2,3,4,5,6,7,8,9,10};

    std::cout << "first method:" << search1(vec, 5) << std::endl;
    std::cout << "second method:" << search2(vec, 5) << std::endl;
}



#endif //ARRAY_LEECODE_704_H
