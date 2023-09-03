class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int ans = nums[0];
        int size = nums.size();
        for(int i=0; i<size; i++){
            sum = sum + nums[i];
            ans = max(ans , sum);

            if(sum<0){
                sum=0;
            }
        }
        
        return ans;
    }
};