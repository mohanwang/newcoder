//
//  Solution.cpp
//  newcoder
//
//  Created by maciejwang on 2018/8/25.
//  Copyright © 2018年 maciejwang. All rights reserved.
//

#include "Solution.hpp"
#include <algorithm>

vector<int> Solution::PrintFromTopToBottom(TreeNode* root)
{
    vector<int> result;
    deque<TreeNode *> dRoot;
    if (root) {
        dRoot.push_back(root);
    }
    while (!dRoot.empty()) {
        TreeNode *tmp = dRoot.front();
        result.push_back(tmp->val);
        dRoot.pop_front();
        if (tmp->left) {
            dRoot.push_back(tmp->left);
        }
        if (tmp->right) {
            dRoot.push_back(tmp->right);
        }
    }
    return result;
}


bool Solution::IsPopOrder(vector<int> pushV, vector<int> popV)
{
    stack<int> tmp;
    size_t j = 0;
    for (size_t i = 0; i < pushV.size();)
    {
        if (!tmp.empty() && tmp.top() == popV[j]) {
            j++;
            tmp.pop();
        } else {
            tmp.push(pushV[i++]);
        }
    }
    while (!tmp.empty() && j < popV.size()) {
        if (tmp.top() == popV[j++]) {
            tmp.pop();
        }
    }
    return tmp.empty();
}

void Solution::Mirror(TreeNode *pRoot)
{
    if (!pRoot) {
        return;
    }
    TreeNode *tmp = pRoot->left;
    pRoot->left = pRoot->right;
    pRoot->right = tmp;
    Mirror(pRoot->left);
    Mirror(pRoot->right);
    return;
}

bool Solution::_internalHasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
    if (!pRoot2) {
        return true;
    }
    
    if (!pRoot1) {
        return false;
    }

    if (pRoot1->val != pRoot2->val) {
        return false;
    }
    return _internalHasSubtree(pRoot1->left, pRoot2->left) && _internalHasSubtree(pRoot1->right, pRoot2->right);
}

bool Solution::HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
    if (!pRoot2) {
        return false;
    }
    if (!pRoot1) {
        return false;
    }
    
    return _internalHasSubtree(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
}

ListNode* Solution::Merge(ListNode *pHead1, ListNode *pHead2)
{
    ListNode* resultHead = NULL;
    if (!pHead1) {
        return pHead2;
    }
    if (!pHead2) {
        return pHead1;
    }
    if (pHead1->val <= pHead2->val) {
        resultHead = pHead1;
        pHead1 = pHead1->next;
    } else {
        resultHead = pHead2;
        pHead2 = pHead2->next;
    }
    resultHead->next = NULL;
    ListNode* tmp = resultHead;
    
    while (pHead1 && pHead2) {
        if (pHead1->val <= pHead2->val) {
            tmp->next = pHead1;
            tmp = tmp->next;
            pHead1 = pHead1->next;
            tmp->next = NULL;
        } else {
            tmp->next = pHead2;
            tmp = tmp->next;
            pHead2 = pHead2->next;
            tmp->next = NULL;
        }
    }
    if (pHead1) {
        tmp->next = pHead1;
    }
    if (pHead2) {
        tmp->next = pHead2;
    }
    return resultHead;
}

ListNode* Solution::ReverseList(ListNode* pHead)
{
    if (!pHead) {
        return pHead;
    }
    ListNode* reverseHead = pHead;
    ListNode* next = pHead->next;
    
    reverseHead->next = NULL;
    ListNode* nextHead = NULL;
    while (next) {
        nextHead = next->next;
        next->next = reverseHead;
        reverseHead = next;
        next = nextHead;
    }
    return reverseHead;
}

ListNode* Solution::FindKthToTail(ListNode* pListHead, unsigned int k)
{
    ListNode* ptr1 = pListHead;
    ListNode* ptr2 = pListHead;
    if (k < 1) return NULL;
    for (int i = 1; i < k; i++) {
        if (ptr1 && ptr1->next) {
            ptr1 = ptr1->next;
        } else {
            return NULL;
        }
    }
    
    while (ptr1 && ptr1->next) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    
    return ptr2;
}
// 遍历计数，然后找第n-k+1
//ListNode* Solution::FindKthToTail(ListNode* pListHead, unsigned int k)
//{
//    int count = 0;
//    ListNode* tmp = pListHead;
//    while (tmp) {
//        count++;
//        tmp = tmp->next;
//    }
//    if (k > count) {
//        return NULL;
//    }
//    tmp = pListHead;
//    for (int i = 0; i != count - k; i++) {
//        tmp = tmp->next;
//    }
//    return tmp;
//}

void Solution::reOrderArray(vector<int> &array)
{
    int len = array.size();
    bool swapFlag = false;
    for (int i = len - 1; i >= 0;) {
        if (array[i] % 2 == 0) {
            i--;
            swapFlag = false;
            continue;
        }
        for (int j = i; j >= 1; j--) {
            if (array[j] % 2 == 1 && array[j - 1] % 2 ==0) {
                int tmp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = tmp;
                swapFlag = true;
            }
        }
        if (!swapFlag) {
            break;
        }
    }
    return;
}

int Solution::NumberOf1(int n)
{
    int count = 0;
    while (n) {
        if (n & 0x80000000) {
            count++;
        }
        n = n << 1;
    }
    
    return count;
}
//{
//    int count = 0;
//    while (n) {
//        count++;
//        n = (n - 1) & n;
//    }
//
//    return count;
//}
//{
//    int *pn = &n;
//    char *pc = (char *)pn;
//
//    int count = 0;
//    for (int i = 0; i < 4; i++) {
//        char tmp = (*(pc+i));
//        while (tmp) {
//            if (tmp & 0x80) {
//                count++;
//            }
//            tmp = tmp << 1;
//        }
//    }
//
//    return count;
//}

// 推理， 同jumpFloor
int Solution::rectCover(int number)
{
    if (number <= 0)
        return 0;
    if (number == 1) {
        return 1;
    }
    if (number == 2) {
        return 2;
    }
    
    int f1 = 1;
    int f2 = 2;
    while (number-- > 2) {
        f2+=f1;
        f1=f2-f1;
    }
    return f2;
}

// 推理公式，2^(number-1)
int Solution::jumpFloorII(int number)
{
    if (number < 1) {
        return 0;
    }
    int result = 1;
    while (number-1 > 0) {
        result = 2*result;
        number--;
    }
    return result;
}

int Solution::jumpFloor(int number)
{
    // 迭代实现4ms
    if (number <= 1) {
        return 1;
    }
    if (number == 2) {
        return 2;
    }
    
    int f1 = 1;
    int f2 = 2;
    while (number-- > 2) {
        f2+=f1;
        f1=f2-f1;
    }
    return f2;
// 递归实现  400ms
//    if (number <= 1) {
//        return 1;
//    }
//    if (number == 2) {
//        return 2;
//    }
//    return jumpFloor(number-1) + jumpFloor(number-2);
}

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
