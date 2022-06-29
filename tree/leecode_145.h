//
// Created by 15387 on 2022/6/26.
//

#ifndef TREE_LEECODE_145_H
#define TREE_LEECODE_145_H

#include "treeNode.h"
#include <vector>
#include <stack>

/* 题目描述：二叉树的后序遍历 */

void traverse(TreeNode *cur, vector<int> &result) {
    if (nullptr == cur) return;

    traverse(cur->left, result);
    traverse(cur->right, result);
    result.push_back(cur->val);
}

// 递归方法
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> result;
    traverse(root, result);
    return result;
}

// 迭代方法
// 入栈顺序： 中左右
vector<int> postorderTraversal1(TreeNode *root) {
    vector<int> result;
    if (nullptr == root) return result;

    stack<TreeNode *> st;
    st.push(root);

    while (st.size()) {
        TreeNode *cur = st.top();
        st.pop();

        if (cur->left) {
            st.push(cur->left);
        }

        if (cur->right) {
            st.push(cur->right);
        }

        if (cur) {
            result.push_back(cur->val);
        }
    }

    reverse(result.begin(), result.end());

    return result;
}

#endif //TREE_LEECODE_145_H
