#pragma once

#include <iostream>
#include <queue>
#include <vector>

#include "treeNode.h"

using namespace std;

/*
	给定一个非空二叉树的根节点 root , 以数组的形式返回每一层节点的平均值。与实际答案相差 10-5 以内的答案可以被接受。
*/

vector<double> averageOfLevels(TreeNode* root) {
	vector<double> result;
	if (nullptr == root) return result;

	queue<TreeNode*> queue;
	queue.push(root);

	while (!queue.empty())
	{
		int size = queue.size();
		long sum = 0;

		TreeNode* node = nullptr;

		for (int i = 0; i < size; ++i)
		{
			node = queue.front();
			sum += node->val;
			queue.pop();

			if (node->left) queue.push(node->left);
			if (node->right) queue.push(node->right);
		}

		result.push_back((double)sum / size);
	}

	return result;
}