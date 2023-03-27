#include <bits/stdc++.h> 

//Kahn's algorithm to find topological sort

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    queue<int>q;
    // creating adjecency list
    unordered_map<int,list<int>>adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
    }

    // counting indgreess
    vector<int>indgree(v);
    for(auto x:adj){
        for(auto y:x.second){
            indgree[y]++;
        }
    }
    //0 indegree walo ko push kardo queue
    for(int i=0;i<v;i++){
        if(indgree[i]==0) q.push(i);
    }

    // do bfs
    vector<int>ans;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        //ans store
        ans.push_back(front);
        for(auto neighbour:adj[front]){
            indgree[neighbour]--;
            if(indgree[neighbour]==0) q.push(neighbour);
        }
    }
    return ans;
}