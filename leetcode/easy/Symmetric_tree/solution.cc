#include <queue>
#include <iostream>
using namespace std;


struct TreeNode
{
    int                 val;
    TreeNode            *left;
    TreeNode            *right;
};

class Solution {
    public:
        bool isSymmetric(TreeNode *root) {
            if(!root)
            {
                return true;
            }
            if(root->left && !root->right)
            {
                return false;
            }
            if(root->right && !root->left)
            {
                return false;
            }
            if(!root->left && !root->right)
            {
                return true;
            }

            queue<TreeNode*> qLeft;
            queue<TreeNode*> qRight;

            qLeft.push(root->left);
            qRight.push(root->right);

            TreeNode* pLeft = NULL;
            TreeNode* pRight = NULL;
            while( !qLeft.empty() && !qRight.empty() )
            {
                pLeft = qLeft.front();
                qLeft.pop();
                pRight = qRight.front();
                qRight.pop();
                if(pLeft->val != pRight->val)
                    return false;

                if(pLeft->left)
                {
                    qLeft.push(pLeft->left);
                }
                if(pLeft->right)
                {
                    qLeft.push(pLeft->right);
                }
                if(pRight->right)
                {
                    qRight.push(pRight->right);
                }
                if(pRight->left)
                {
                    qRight.push(pRight->left);
                }
            }
            if( qLeft.empty() && qRight.empty() )
            {
                return true;
            }
            else
            {
                return false;
            }

        }
};
