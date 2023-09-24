class Solution {
private :
    void calcSubset(vector<int>& A, vector<vector<int> >& res,vector<int>& subset, int index){
    res.push_back(subset);
    for (int i = index; i < A.size(); i++) {
        subset.push_back(A[i]);
        calcSubset(A, res, subset, i + 1);
        subset.pop_back();
    }
}
public:
    vector<vector<int>> subsets(vector<int>& nums) { 
    vector<int> subset;
    vector<vector<int> > res;
    int index = 0;
    calcSubset(nums, res, subset, index);
    return res;
    }
};