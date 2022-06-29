//
// Created by 15387 on 2022/6/26.
//

#ifndef TREE_LEECODE_94_H
#define TREE_LEECODE_94_H

#include "treeNode.h"
#include <vector>
#include <stack>

/* 题目描述：二叉树的中序遍历 */

void traverse(TreeNode *cur, vector<int> &result) {
    if (nullptr == cur) return;

    traverse(cur->left, result);
    result.push_back(cur->val);
    traverse(cur->right, result);
}

// 递归方法
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    traverse(root, result);
    return result;
}

// 迭代方法
// 左孩子为空，则弹父节点，左右孩子均为空，则弹爷爷节点
vector<int> inorderTraversal1(TreeNode* root) {
    vector<int> result;
    if (nullptr == root) return result;

    stack<TreeNode *> st;
    TreeNode *cur = root;

    while (nullptr != cur || !st.empty()) {
        if (nullptr != cur) {
            st.push(cur);
            cur = cur->left;
        } else {
            cur = st.top();
            st.pop();
            result.push_back(cur->val);

            cur = cur->right;
        }
    }

    return result;
}



#endif //TREE_LEECODE_94_H
