#pragma once

/*
	给定一个二叉树，找出其最小深度。

	最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
 */

#include <iostream>
#include <queue>
#include <vector>

#include "treeNode.h"

using namespace std;

int minDepth(TreeNode* root) {
	int depth = 0;
	if (nullptr == root) return depth;

	queue<TreeNode*> queue;
	queue.push(root);

	while (!queue.empty())
	{
		int size = queue.size();
		TreeNode* node = nullptr;

		++depth;

		for (int i = 0; i < size; ++i)
		{
			node = queue.front();
			queue.pop();

			if (node->left) queue.push(node->left);
			if (node->right) queue.push(node->right);

			if (!node->left && !node->right)
			{
				return depth;
			}
		}
	}

	return depth;
}

