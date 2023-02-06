class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        // map<horiDistance,node->data>
        map<int,int>topNode;
        //map<node,horizontalDistance>
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            pair<Node*,int>temp=q.front();
            Node*front=temp.first;
            q.pop();
            int hd=temp.second;
            //if one value is present for a hd then do nothing
            if(topNode.find(hd)==topNode.end()){
                topNode[hd]=front->data;
            }
            if(front->left) q.push({front->left,hd-1});
            if(front->right) q.push({front->right,hd+1});
        }
        // <horiDistance,node->data>----->topNode
        for(auto i: topNode){
            ans.push_back(i.second);
        }
        return ans;
    }

};