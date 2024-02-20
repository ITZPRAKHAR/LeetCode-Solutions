class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int totalsum =0;

        for(int i = 1; i<=nums.size(); i++){
            totalsum = totalsum + i;
        }

        for(int i = 0; i<nums.size(); i++){
           sum = sum + nums[i];
        }
      
      return totalsum-sum;
    }
};