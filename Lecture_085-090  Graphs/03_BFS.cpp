#include <unordered_map> 
#include <queue> 
#include <list> 
#include <set> 
void makelist(unordered_map<int,set<int>>&adjlist,vector<pair<int, int>>&edges){
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        adjlist[u].insert(v);
        adjlist[v].insert(u);
    }
}
void bfs(unordered_map<int,set<int>>adjlist,unordered_map<int,bool>&visited,vector<int>&ans,int i){
    queue<int>q;
    q.push(i);
    visited[i]=1;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        // store
        ans.push_back(front);
        // traverse all the neighbour
        for(auto i: adjlist[front]){
            if(!visited[i]){
                q.push(i);
                visited[i]=1;
            }
        }
    }
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int,set<int>>adjlist;
    // making list of neighbouring nodes
    makelist(adjlist,edges);

    vector<int>ans;
    unordered_map<int,bool>visited;

    // traverse all component of a graph
    for(int i=0;i<vertex;i++){
      if (!visited[i]) {
        bfs(adjlist, visited, ans, i);
      }
    }
    return ans;
}