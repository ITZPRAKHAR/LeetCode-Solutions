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
    int maxLevelSum(TreeNode* root) {
        queue<pair<TreeNode* , int>>q;
        q.push(make_pair(root , 1));
        
        int maxsum = -1e9;
        int currlevel = 0;
        int lvl = 0;
        while(!q.empty()){
            
            int size = q.size();
            int sum = 0;
            for(int i=0; i<size; i++){
                pair<TreeNode* , int>temp = q.front();
                q.pop();
                  sum = sum + temp.first->val;
                  currlevel = temp.second;
                if(temp.first->left){
                    q.push(make_pair(temp.first->left , currlevel+1));
                }
                if(temp.first->right){
                    q.push(make_pair(temp.first->right , currlevel+1));
                }
            }
            if(sum >maxsum){
                maxsum = sum;
                lvl = currlevel;
            }
            
        }

        return lvl;

    }
};