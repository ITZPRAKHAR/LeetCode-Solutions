class Solution {
public:
    void merge(vector<int>n , vector<int>m , vector<int>&ans){
          
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
         for(int i = 0; i<nums1.size(); i++){
            ans.push_back(nums1[i]);
        }

        for(int i = 0; i<nums2.size(); i++){
            ans.push_back(nums2[i]);
        }

        sort(ans.begin() , ans.end());

        int mid = ans.size()/2;
        if(ans.size()%2 == 0){
            return ((ans[mid] + ans[mid-1])/2.0);
        }
        else {
             return (ans[mid]);
        }

    }
};