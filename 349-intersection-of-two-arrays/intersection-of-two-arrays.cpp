class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int , int>m;
        vector<int>ans;

        for(int i = 0;i<nums1.size(); i++){
            if(m[nums1[i]] <1){
            m[nums1[i]]++;
            }
        }

        for(int j = 0;j<nums2.size(); j++){

            if(m[nums2[j]] == 1){
            m[nums2[j]]++;
            }
        }
        
        for(auto x : m){
            if(x.second > 1){
                ans.push_back(x.first);
            }
        }

         return ans;
        
        }
 
};