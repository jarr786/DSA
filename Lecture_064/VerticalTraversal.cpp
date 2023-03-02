class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        //we will create a mapping :    horizontalDistance- >(map(level-->vector)
        //HD->level->vector     mapping table just like
        map<int,map<int,vector<int>>>nodes;
        
        //making queue<node,pair<horizontalDist,level>
        queue<pair<Node*,pair<int,int>>>q;
        q.push(make_pair(root,make_pair(0,0)));
        
        while(!q.empty()){
            pair<Node*,pair<int,int>>temp=q.front();
            q.pop();
            Node*front=temp.first;
            int hd=temp.second.first;
            int lvl=temp.second.second;
            //making an entry to our map nodes
            nodes[hd][lvl].push_back(front->data);
            
            //pushing childs of the node into the Queue
            if(front->left) q.push(make_pair(front->left,make_pair(hd-1,lvl+1)));
            if(front->right) q.push(make_pair(front->right,make_pair(hd+1,lvl+1)));
        }
        // HD->level->vector
        for(auto i:nodes){
            for(auto j:i.second){
                for(auto k:j.second){
                    ans.push_back(k);
                }
            }
        }
        return ans;
    }
};
