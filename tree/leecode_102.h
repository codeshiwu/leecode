#pragma once

#include <iostream>
#include <queue>
#include <vector>

#include "treeNode.h"

using namespace std;

vector<vector<int>> levelOrder(TreeNode* root) {
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

	return result;
}

vector<vector<int>> levelOrder1(TreeNode* root) {
	vector<vector<int>> result;
	vector<int>			level;

	if (nullptr == root) return result;

	queue<TreeNode*> nodequeue;
	nodequeue.push(root);
	nodequeue.push(nullptr);

	while (!nodequeue.empty())
	{
		TreeNode* node = nodequeue.front();
		nodequeue.pop();

		if (nullptr == node)
		{
			result.push_back(level);
			level.clear();
			continue;
		}

		if (node->left) nodequeue.push(node->left);
		if (node->right) nodequeue.push(node->right);

		level.push_back(node->val);
		TreeNode* nextNode = nodequeue.front();
		if (nullptr == nextNode)
		{
			continue;
		}
		else
		{
			nodequeue.push(nullptr);
		}
	}

	return result;
}
