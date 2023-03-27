
// Qsn-cdnj Bridges In A Graph
// Bridges is an edge if we erase that edge it will divide graph into more components

#include<unordered_map>
#include<list>
void dfs(int node,int parent,int &timer,vector<int>&disc,vector<int>&low,vector<vector<int>>&result,unordered_map<int,list<int>>&adj,unordered_map<int,bool>&vis){
    vis[node]=true;
    disc[node]=low[node]=timer++;

    for(auto nbr:adj[node]){
        if(nbr==parent){
            continue;
        }
        if(!vis[nbr]){
            dfs(nbr,node,timer,disc,low,result,adj,vis);
            low[node]=min(low[node],low[nbr]);
            //check brdge
            if(low[nbr]>disc[node]){
                vector<int>ans;
                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
            }
        }
        else{
                //back edge
                low[node]=min(low[node],disc[nbr]);
            }
    }
}

// main function
vector<vector<int>> findBridges(vector<vector<int>>&edges,int v,int e){

    vector<vector<int>>result;
    // adj list
    unordered_map<int,list<int>>adj;

    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer=0;
    vector<int>disc(v,-1);
    vector<int>low(v,-1);
    int parent=-1;

    unordered_map<int,bool>vis;

    for(int i=0;i<v;i++){
        if(!vis[i]){
            dfs(i,parent,timer,disc,low,result,adj,vis);
        }
    }
    return result;
}