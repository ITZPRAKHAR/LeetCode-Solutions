class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int ans = 0;
        map<int,int>mp;
        for(int i =0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        int maxnum = 0;
        for(auto j : mp){
           maxnum = max(maxnum , j.second);
        }
        for(auto k : mp){
            if(k.second == maxnum){
              ans =  ans+k.second;
            }
        }
        return ans;
    }
};