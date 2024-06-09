class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
    int sum=0;
    int count=0;
    map<int,int>mp;
    mp[0]++;                  // always one prefix sum that is initially 0

    
    for(int i=0;i<nums.size();i++)
    {
        sum+=nums[i];
        int rem=sum%k;        //Calculte the remainders of current sun
        
        if(rem<0)             // Handle negative remainders to ensure they are positive
        {
            rem=k+rem;
        }
        
        if(mp[rem]>0)          // If remainder has seen before, it means there are subarrays
            count+=mp[rem];    // which sum to multiple of k. Add the count of occurrences

        mp[rem]++;              // Increment the count for this remainder in the map
    }
    return count;
        
    }
};