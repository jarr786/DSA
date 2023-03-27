#include <bits/stdc++.h> 

// Qsn-cdnjas   Shortest path in an unweighted graph
//undirected graph

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// creating adjecency list
    unordered_map<int,list<int>>adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
	
	// do bfs
	unordered_map<int,bool>visited;

	// making parent array ready
	unordered_map<int,int>parent;

	queue<int>q;
	q.push(s);
	parent[s]=-1;
	visited[s]=true;

	while(!q.empty()){
		int front=q.front();
		q.pop();
		for(auto i:adj[front]){
			if(!visited[i]){
				visited[i]=true;
				// impo
				parent[i]=front;
				q.push(i);
			}
		}
	}
	// now parent array is ready
	// shortest path finding
	vector<int>ans;
	int currNode=t;
	ans.push_back(currNode);
	while(currNode!=s){
		currNode=parent[currNode];
		ans.push_back(currNode);
	}
	reverse(ans.begin(),ans.end());
	return ans;
}
