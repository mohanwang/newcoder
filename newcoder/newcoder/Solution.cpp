//
//  Solution.cpp
//  newcoder
//
//  Created by maciejwang on 2018/8/25.
//  Copyright © 2018年 maciejwang. All rights reserved.
//

#include "Solution.hpp"
#include <algorithm>

int Solution::Fibonacci(int n)
{
    int a0 = 0, a1 = 1;
    if (n == 0) {
        return a0;
    }
    if (n == 1) {
        return a1;
    }
    int an = 0;
    for (int i = 2; i <= n; i++) {
        an = a0 + a1;
        a0 = a1;
        a1 = an;
    }

    return an;
}

int Solution::minNumberInRotateArray(vector<int> rotateArray)
{
    if (rotateArray.size() == 0) {
        return 0;
    }
    int left = 0;
    int right = rotateArray.size() - 1;
    while (left < right) {
        if (rotateArray[left] < rotateArray[right]) {
            return rotateArray[left];
        }
        int mid = left + (right - left) / 2;
        if (rotateArray[left] < rotateArray[mid]) {
            left = mid;
            continue;
        } else if (rotateArray[left] > rotateArray[mid]) {
            right = mid;
        } else {
            left++; // 顺序查找
        }
    }
    
    return rotateArray[left];
}

int Solution::minNumberInRotateArray1(vector<int> rotateArray)
{
    if (rotateArray.size() == 0) {
        return 0;
    }
    int min = rotateArray[0];
    for (size_t i = rotateArray.size() - 1; i > 1; i--) {
        if (rotateArray[i] >= rotateArray[i-1]) {
            if (min > rotateArray[i-1]) {
                min = rotateArray[i-1];
            }
        } else {
            break;
        }
    }
    return min;
}

void Solution::push(int node)
{
    stack1.push(node);
    return;
}

int Solution::pop()
{
    int value;
    if (stack2.empty()) {
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }
    if (!stack2.empty()) {
        value = stack2.top();
        stack2.pop();
        return value;
    }
    return 0;
}


/*
 1,2,4,7,3,5,6,8
 4,7,2,1,5,3,8,6
 */
TreeNode* Solution::reConstructBinaryTree(vector<int> pre, vector<int> vin)
{
    if (pre.size() == 0) {
        return NULL;
    }
    
    TreeNode *node = new TreeNode(pre[0]);

    if (pre.size() == 1 && vin.size() == 1) { // 可要可不要
        node->left = NULL;
        node->right = NULL;
        return node;
    }
    
    int gen = 0;
    for (int i = 0; i < vin.size(); i++) {
        if (vin[i] == pre[0]) {
            gen = i;
            break;
        }
    }
    vector<int> leftVin;
    vector<int> leftPre;

    vector<int> rightVin;
    vector<int> rightPre;
    
    for (int i = 0; i < gen; i++) {
        leftVin.push_back(vin[i]);
        leftPre.push_back(pre[i+1]);
    }
    for (int i = gen + 1; i < vin.size(); i++) {
        rightVin.push_back(vin[i]);
        rightPre.push_back(pre[i]);
    }
    node->left = reConstructBinaryTree(leftPre, leftVin);
    node->right = reConstructBinaryTree(rightPre, rightVin);
    return node;
}

vector<int> Solution::printListFromTailToHead(ListNode* head)
{
    vector<int> result;
    if (!head) {
        return result;
    }
    ListNode *ptr = head;
    while (ptr) {
        result.push_back(ptr->val);
        ptr = ptr->next;
    }
    return vector<int>(result.rbegin(), result.rend());
}

vector<int> result;
vector<int> Solution::printListFromTailToHead1(ListNode* head)
{
    if (!head) {
        return result;
    }
    result = printListFromTailToHead1(head->next);
    result.push_back(head->val);
    return result;
}

void Solution::replaceSpace(char *str, int length)
{
    if (!str || length <= 0) {
        return;
    }
    int originLength = 0;
    int countSpace = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        originLength++;
        if (str[i] == ' ') {
            countSpace++;
        }
    }
    
    int newLength = originLength + 2 * countSpace;
    if (newLength + 1 > length)
        return;
    str[newLength] = '\0';
    // i追上j就可以停止了
    for (int i = newLength - 1, j = originLength - 1; i != j;) {
        if (str[j] == ' ') {
            str[i--] = '0';
            str[i--] = '2';
            str[i--] = '%';
            j--; // 在这里--
        } else {
            str[i--] = str[j--];
        }
    }
    return;
}

bool Solution::Find(int target, vector<vector<int> > array)
{
    int row = 0;
    int col = array[0].size() - 1;
    for (; col >= 0 && row < array.size(); ) {
        if (array[row][col] == target) {
            return true;
        } else if (target > array[row][col]) {
            row++;
        } else {
            col--;
        }
    }
    return false;
}

bool Solution::Find0(int target, vector<vector<int> > array)
{
    size_t len = array.size();
    size_t min = 0;
    size_t max = 0;
    for (size_t i = 0; i < len; i++) {
        size_t len_i = array[i].size();
        if (len_i > i) {
            if (target == array[i][i]) {
                return true;
            } else if (target > array[i][i]) {
                min = i;
            } else {
                max = i;
                break;
            }
        }
    }
    if (max > min) {
        for (size_t i = 0; i < min; i++) {
            for (size_t j = min; j < array[i].size(); j++) {
                if (array[i][j] == target) {
                    return true;
                }
            }
        }
        for (size_t i = min; i <= max; i++) {
            if (array[i].size() < max) {
                continue;
            }
            for (size_t j = min; j <= max; j++) {
                if (array[i][j] == target) {
                    return true;
                }
            }
        }
        for (size_t i = min; i < array.size(); i++) {
            for (size_t j = 0; j < min; j++) {
                if (array[i][j] == target) {
                    return true;
                }
            }
        }
    }
    return false;
}
