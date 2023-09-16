//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    int mod = 1e9+7;
    long long countWays(int n)
    {
        
        // your code here
        vector<long long> dp(n+1, 0);
        dp[0] = 1;
        for(int i=1; i<=n; i++)
        {
            long long temp = 0;
            if(i-1>=0) temp += dp[i-1] % mod;
            if(i-2>=0) temp += dp[i-2] % mod;
            if(i-3>=0) temp += dp[i-3] % mod;
            dp[i] = temp %mod;
        }
        return dp[n];
        
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends