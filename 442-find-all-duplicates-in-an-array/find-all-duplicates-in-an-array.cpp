class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        map<int , int>mp;
        for(auto i: nums){
            mp[i]++;
        }
        
        for(auto j: mp){
            if(j.second == 2){
                ans.push_back(j.first);
            }
        }

        return ans;
    }
};