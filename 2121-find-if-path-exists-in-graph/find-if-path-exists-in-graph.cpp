class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool>vis(n , 0);
        vector<int>graph[n];
        for(auto &i : edges){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);     
        }
        queue<int>q;
        q.push(source);
        vis[source] = 1;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            if(node == destination){
                return true;
            }

            for(auto neigh : graph[node]){
                if(!vis[neigh]){
                    q.push(neigh);
                    vis[neigh] = 1;
                }
            }
        }
        return false;
    }
};