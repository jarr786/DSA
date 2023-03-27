// build dfs function
void dfs(int node,unordered_map<int,bool>&visited,unordered_map<int,list<int>>&adj,vector<int>&component){
    component.push_back(node);
    visited[node]=true;
    
    // recursive call for every connected node
    for(auto i:adj[node]){
        if(!visited[i]){
            dfs(i,visited,adj,component);
        }
    }

}
// QSN-traversal of disconnected grap
//    given function
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{   
    vector<vector<int>>ans;
    // prepare adjucency list
    unordered_map<int,list<int>>adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    unordered_map<int,bool>visited;
    
    // calling dfs
    for(int i=0;i<V;i++){
        if(!visited[i]){
            vector<int>component;
            dfs(i,visited,adj,component);
            ans.push_back(component);
        }
    }
    return ans;
}

