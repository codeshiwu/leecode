//
// Created by 15387 on 2022/5/24.
//

#ifndef ARRAY_LEECODE_27_H
#define ARRAY_LEECODE_27_H

#include <iostream>
#include <vector>

/**
 * leecode题目：移除元素
 * 原地移除数组中所有等于val的元素，要求不能使用额外的辅助空间，即空间复杂度为O(1)
 * 返回移除后的新数组的size
 */

int removeElement(std::vector<int>& nums, int val)
{
    std::size_t size = nums.size();

    for (int i = 0; i < nums.size(); ++i)
    {
        if (val != nums[i])
        {
            continue;
        }

        for (int j = i + 1; j < size; ++j)
        {
            nums[j - 1] = nums[j];
        }

        size--;
        i--;
    }

    return size;
}

#endif //ARRAY_LEECODE_27_H
