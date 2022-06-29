#pragma once

#include <iostream>
#include <queue>
#include <vector>

#include "treeNode.h"

using namespace std;

/*
 给你二叉树的根节点 root ，返回其节点值 自底向上的层序遍历 。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
*/

vector<vector<int>> levelOrderBottom(TreeNode* root) {
	vector<vector<int>> result;
	vector<int>			level;

	if (nullptr == root) return result;

	queue<TreeNode*> nodequeue;
	nodequeue.push(root);

	while (!nodequeue.empty())
	{
		int size = nodequeue.size();
		for (int i = 0; i < size; ++i)
		{
			TreeNode* node = nodequeue.front();
			level.push_back(node->val);
			nodequeue.pop();

			if (node->left) nodequeue.push(node->left);
			if (node->right) nodequeue.push(node->right);
		}

		result.push_back(level);
		level.clear();
	}

	reverse(result.begin(), result.end());

	return result;
}
