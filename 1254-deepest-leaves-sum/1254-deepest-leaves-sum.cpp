/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int deepestLeavesSum(TreeNode* root) {
        vector<vector<int>>v;
        if(!root) return root->val;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            vector<int>ans(n);
            for(int i=0;i<n;i++)
            {
                
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left) 
                {
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    q.push(temp->right);
                }
                ans.push_back(temp->val);
            }
            v.push_back(ans);
        }
        int k=v[v.size()-1].size();
        int value=0;
        int i=0;
        while(i<k)
        {
            value+=v[v.size()-1][i];
            i++;
        }
        return value;
    }
};