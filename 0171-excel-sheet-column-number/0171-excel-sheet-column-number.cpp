class Solution {
public:
    int titleToNumber(string columnTitle) {
        unordered_map<char,int>m;
        int k=1;
        int n=columnTitle.size();
        for(char i='A';i<='Z';i++)
        {
            m[i]=k;
            k++;
        }
        long long ans=0;
        k=0;
        for(int i=n-1;i>=0;i--)
        {
            ans+=(m[columnTitle[i]]*pow(26,k));
            k++;
        }
        return ans;
    }
};