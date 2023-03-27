#include <bits/stdc++.h> 

// topological sort function
void topsort(int node,vector<bool>&visited,stack<int>&s,unordered_map<int,list<int>>&adj){
    visited[node]=true;
    for(auto neighbour:adj[node]){
        if(!visited[neighbour]){
            topsort(neighbour,visited,s,adj);
        }
    }
    // while retturning put node into stack
    s.push(node);
}
// given function
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    stack<int>s;
    // creating adjecency list
    unordered_map<int,list<int>>adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
    }

     //call dfs topological sort for all component
    vector<bool>visited(v);
    for(int i=0;i<v;i++){
      if(!visited[i]){
        topsort(i,visited,s,adj);
      }
    }
    vector<int>ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}