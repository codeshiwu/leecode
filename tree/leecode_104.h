#pragma once

/*
 给定一个二叉树，找出其最大深度。
 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
 */

#include <iostream>
#include <queue>
#include <vector>

#include "treeNode.h"

using namespace std;

int maxDepth(TreeNode* root) {
	int depth = 0;
	if (nullptr == root) return depth;

	queue<TreeNode*> queue;
	queue.push(root);

	while (!queue.empty())
	{
		int size = queue.size();
		TreeNode* node = nullptr;
		for (int i = 0; i < size; ++i)
		{
			node = queue.front();
			queue.pop();

			if (node->left) queue.push(node->left);
			if (node->right) queue.push(node->right);
		}

		++depth;
	}

	return depth;
}
