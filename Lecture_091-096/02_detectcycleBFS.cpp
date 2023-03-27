#include <bits/stdc++.h> 

// using Kahn'algorithm (detection of cycle)
// if(count is equal to n mean right topological order)
// else wrong topological order means cycyle present

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
   queue<int>q;
    // creating adjecency list
    unordered_map<int,list<int>>adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first-1;
        int v=edges[i].second-1;
        adj[u].push_back(v);
    }

    // counting indgreess
    vector<int>indgree(n);
    for(auto x:adj){
        for(auto y:x.second){
            indgree[y]++;
        }
    }
    //0 indegree walo ko push kardo queue
    for(int i=0;i<n;i++){
        if(indgree[i]==0) q.push(i);
    }

    // do bfs
    int count=0;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        
        count++;
        
        for(auto neighbour:adj[front]){
            indgree[neighbour]--;
            if(indgree[neighbour]==0) q.push(neighbour);
        }
    }
    if(count==n) return false;  //acyclic
    
    else return true;        //cyclic
}