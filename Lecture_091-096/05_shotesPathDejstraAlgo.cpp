#include <bits/stdc++.h> 

// Qsn-cdnjs Dijkstra's shortest path
//   u have been given an undirected graph

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    
    //creating adjecency list
        //   pair<distance,node>
    unordered_map<int,list<pair<int,int>>>adj;
    for(int i=0;i<edges;i++){
        int u=vec[i][0];
        int v=vec[i][1];
        int w=vec[i][2];
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
// creation of distance array with infinite value initially
    vector<int>dist(vertices);
    for(int i=0;i<vertices;i++){
        dist[i]=INT_MAX;
    }
        //   pair<distance,node>
    set<pair<int,int>>st;
    dist[source]=0;
    st.insert({0,source});

    while(!st.empty()){
        //fetch top record
        auto top=*(st.begin());

        int nodedistance=top.first;
        int topNode=top.second;
        
        // remove top record
        st.erase(st.begin());

        // traverse neighbour
        for(auto neighbour:adj[topNode]){
            if(nodedistance+neighbour.second<dist[neighbour.first]){
                auto record=st.find(make_pair(dist[neighbour.first],neighbour.first));
                // if found
                if(record!=st.end()){
                    st.erase(record);
                }
                // distance update
                dist[neighbour.first]=nodedistance+neighbour.second;
                //record push in set
                st.insert(make_pair(dist[neighbour.first],neighbour.first));
            }
        }
    }
    return dist;
}
