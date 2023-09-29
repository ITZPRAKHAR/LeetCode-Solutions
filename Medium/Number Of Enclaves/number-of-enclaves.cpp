//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
         int dx[4]={-1,0, 0, 1};
        int dy[4]={0 ,-1, 1, 0};
        queue<pair<int, int>>q;
        for(int i=0; i<grid[0].size(); i++){
            if(grid[0][i]==1){q.push({0, i});}
            if(grid[grid.size()-1][i]==1){q.push({grid.size()-1, i});}
        }
        for(int i=1; i<grid.size()-1; i++){
            if(grid[i][0]==1){q.push({i, 0});}
            if(grid[i][grid[0].size()-1]==1){q.push({i, grid[0].size()-1});}
        }
        while(q.size()){
            auto a=q.front(); q.pop();
            int x=a.first, y=a.second;
            grid[x][y]=0;
            for(int i=0; i<4; i++){
                int newx=x+dx[i], newy=y+dy[i];
                if(newx>=0 and newx<grid.size() and newy>=0 and newy<grid[0].size() and grid[newx][newy]==1){
                    q.push({newx, newy});
                }
            }
        }
        int ans=0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                ans+=(grid[i][j]==1);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends