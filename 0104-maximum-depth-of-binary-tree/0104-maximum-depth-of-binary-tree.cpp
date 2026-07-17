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
    int maxDepth(TreeNode* root) {
        int ans=0;
        if(root==nullptr){
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            
            
            int size=q.size();
            
            for(int i=0;i<size;i++){
                root=q.front();
                q.pop();
                if(root->left!=nullptr){q.push(root->left);};
                if(root->right!=nullptr){q.push(root->right);};
            }
            ans+=1;
        }
        return ans;
        
    }
};