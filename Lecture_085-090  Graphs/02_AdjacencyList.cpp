#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;
class graph{
    public:
    unordered_map<int,list<int>>adj;
    void addEdge(int u,int v,bool direction){
        // direction: 1 for ordered graph and 0 for unorderd graph
        adj[u].push_back(v);
        if(direction==0){
           adj[v].push_back(u);
        }
    }
    void printlist(){
        for(auto i:adj){
            cout<<i.first<<" -> ";
            for(auto x:i.second){
                cout<<x<<",";
            }
            cout<<endl;
        }
    }
};
int main(){
    int n;
    cout<<"enter the number of nodes"<<endl;
    cin>>n;
    int m;
    cout<<"enter the number of edges"<<endl;
    cin>>m;

    graph g;
    
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        //creating undired graph
        g.addEdge(u,v,0);
    }
    g.printlist();
return 0;
}