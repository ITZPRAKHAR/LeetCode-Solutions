//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
         void dfs(int node,vector<int>&visited,vector<int> adjls[]){
        visited[node]=1;
        
        for(auto it:adjls[node]){
            if(visited[it]==0){
                dfs(it,visited,adjls);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // here the given list is the adjacency matrix but not the list so we can first  convert the matrix into list
        vector<int>adjls[V];
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j] == 1 && i!=j){
                    adjls[i].push_back(j);
                    adjls[j].push_back(i);
                }
            }
        }
        int count=0;
        vector<int>visited(V,0);
        for(int i=0;i<V;i++){
            if(visited[i] == 0){
                count++;
                dfs(i,visited,adjls);
            }
        }
        return count;
    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends