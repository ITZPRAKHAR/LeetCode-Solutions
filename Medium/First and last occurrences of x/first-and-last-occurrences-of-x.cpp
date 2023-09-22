//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
   int right(int arr[],int n,int x){
        int i=0,j=n-1;
        int ans=-1;
        while(i<=j){
            int mid=(i+j)/2;
            
            if(arr[mid]==x){
                ans=mid;
                i=mid+1;
            }
            else if(arr[mid]<x){
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return ans;
    }


    int left(int arr[],int n,int x){
        int i=0,j=n-1;
        int ans=-1;
        while(i<=j){
            int mid=(i+j)/2;
            
            if(arr[mid]==x){
                ans=mid;
                j=mid-1;
            }
            else if(arr[mid]>x){
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return ans;
    }
    
    public :
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        int leftSide=left(arr,n,x);
        int rightSide=right(arr,n,x);
        vector<int>v;
        v.push_back(leftSide);
        v.push_back(rightSide);
        return v;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends