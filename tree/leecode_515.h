#pragma once

#include <iostream>
#include <queue>
#include <vector>

#include "treeNode.h"

using namespace std;

/*
 给定一棵二叉树的根节点 root ，请找出该二叉树中每一层的最大值。
*/

vector<int> largestValues(TreeNode* root)
{
	vector<int> result;
	if (nullptr == root) return result;

	queue<TreeNode*> queue;
	queue.push(root);

	while (!queue.empty())
	{
		int size = queue.size();
		int max = INT32_MIN;

		TreeNode* node = nullptr;

		for (int i = 0; i < size; ++i)
		{
			node = queue.front();
			max = max < node->val ? node->val : max;
			queue.pop();

			if (node->left) queue.push(node->left);
			if (node->right) queue.push(node->right);
		}

		result.push_back(max);
	}

	return result;
}


