
class Solution {
private:
    int ans = 0;
    vector<int> helper(TreeNode* root, int d) {
        if(!root) return {};
        if(root->left == NULL && root->right == NULL) return {1};

        vector<int> l = helper(root->left, d);
        vector<int> r = helper(root->right, d);
        vector<int> vec;

        for(auto& a:l) {
            for(auto& b: r) {
                if(a + b <= d) ans++;
            }
            a++;
            if(a<d) vec.push_back(a);
        }

        for(auto& b:r) {
            b++;
            if(b<d) vec.push_back(b);
        }

        return vec;
    }
public:
    int countPairs(TreeNode* root, int distance) {
        helper(root, distance);
        return (ans);
    }
};