class Solution {
public:
    int minDeletions(string s) {
        map<char  , int>mp;
        vector<int>ans;
        int count =0;
        for(int i=0;i<s.length(); i++){
            mp[s[i]]++;
        }
        for(auto i: mp){
            ans.push_back(i.second);
        }
        sort(ans.begin() , ans.end());
        reverse(ans.begin() , ans.end());
        for(int i=1; i<ans.size(); i++){
            while(ans[i] >=ans[i-1] && ans[i]>0){
             ans[i]--;
             count++;
            }
        }
        
        return count;
    }
};