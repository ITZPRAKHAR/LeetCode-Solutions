//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        // priority_queue<long long , vector<long long> , greater<long long>>pq;
        
        // for(int i = 0; i<n; i++){
        //     pq.push(arr[i]);
        // }
        
        // long long cost  = 0;
        // while(pq.size() > 1){
        //     long long first  =  pq.top();
        //     pq.pop();
            
        //     long long second =  pq.top();
        //     pq.pop();
            
        //     long long mergeLength =  first + second;
        //     cost =  cost +  mergeLength;
            
        //     pq.push(mergeLength);
        // }
        
        // return cost;
        
        priority_queue<long long,vector<long long>,greater<long long>>minheap;
        for(long long i=0;i<n;i++){
            minheap.push(arr[i]);
        }
        long long sum=0;
        while(minheap.size()>1){
            long long val1=minheap.top();
            minheap.pop();
            long long val2=minheap.top();
            minheap.pop();
           long long val3=val1+val2;
           sum=sum+val3;
           minheap.push(val3);
        }
        return sum;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends