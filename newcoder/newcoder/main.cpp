//
//  main.cpp
//  newcoder
//
//  Created by maciejwang on 2018/8/27.
//  Copyright © 2018年 maciejwang. All rights reserved.
//

#include <iostream>
#include "Solution.hpp"

using namespace std;

void getRandMoney()
{
    srand(time(NULL));
    int sum = 0;
    cout << "----small---" << endl;
    for (int i = 0; i < 25; i++) {
        int small_money = (rand() % 40 + 10) * 10 + rand() % 10;
        cout << small_money << endl;
        sum += small_money;
    }
    cout << "---middle----" << endl;
    for (int i = 0; i < 3; i++) {
        int middle_money = (rand() % 3 + 1) * 1000 + rand() % 10 * 100 + rand() % 10 * 10 + rand() % 10;
        cout << middle_money << endl;
        sum += middle_money;
    }
    cout << "---big----" << endl;
    int big_money = rand() % 10 * 100 + rand() % 10 * 10 + rand() % 10 + 5000;
    cout << big_money << endl;
    sum += big_money;
    cout << "---count----" << endl;
    cout << sum << endl;
    cout << "---END----" << endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    getRandMoney();

    Solution solution;
    std::cout << solution.NumberOf1(4) << std::endl;
    
    TreeNode *head1 = new TreeNode(8);
    head1->left = new TreeNode(8);
    head1->left->left = new TreeNode(9);
    head1->left->right = new TreeNode(2);
    head1->left->right->left = new TreeNode(4);
    head1->left->right->right = new TreeNode(7);
    head1->right = new TreeNode(7);
    
    TreeNode *head2 = new TreeNode(8);
    head2->left = new TreeNode(9);
    head2->right = new TreeNode(2);
    cout << solution.HasSubtree(head1, head2) << endl;
    
    solution.Mirror(head2);
    
    int arr[5] = {4,3,5,2,1};
    vector<int> seq(arr+0, arr+5);
    cout << solution.VerifySquenceOfBST(seq) << endl;
    
    cout << endl;

    return 0;
}
