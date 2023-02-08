
class Solution {
    //creating mapping
    Node* createParentNodemapping(Node* root, int target,map<Node*,Node*>&nodeToParent){
        
        Node*targetNode=NULL;
        
        queue<Node*>q;
        
        q.push(root);
        nodeToParent[root]=NULL;
        
        while(!q.empty()){
            Node*temp=q.front();
            q.pop();
            //checking for target node to store it 
            if(temp->data==target){
                targetNode=temp;
            }
            //making parent node mapping
            if(temp->left){
            nodeToParent[temp->left]=temp;
                q.push(temp->left);
            }
            //making parent node mapping
            if(temp->right){
            nodeToParent[temp->right]=temp;
                q.push(temp->right);
            }
        }
        return targetNode;
    }
    int burnTree(Node*targetNode,map<Node*,Node*>&nodeToParent){
        
        map<Node*,bool>visited;
        queue<Node*>q;
        
        int ans=0;
        
        q.push(targetNode);
        visited[targetNode]=true;
        
        while(!q.empty()){
            int size=q.size();
            bool flag=false;
            
            for(int i=0;i<size;i++){
                Node*front=q.front();
                q.pop();
                //processing neighbour nodes
                if(front->left && !visited[front->left]){
                    q.push(front->left);
                    visited[front->left]=true;
                    flag=true;
                }
                if(front->right && !visited[front->right]){
                    q.push(front->right);
                    visited[front->right]=true;
                    flag=true;
                }
                if(nodeToParent[front] && !visited[nodeToParent[front]]){
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]]=true;
                    flag=true;
                }
            }
            //if there is any push into queue then there is time count
            if(flag==true) ans++;
        }
        return ans;
    }
  public:
    int minTime(Node* root, int target) 
    {
        // algo
        // step1:nodeToParent mapping
        // step2:get the target node
        // step3:burn the tree
        map<Node*,Node*>nodeToParent;
        Node*targetNode=createParentNodemapping(root,target,nodeToParent);
        int ans=burnTree(targetNode,nodeToParent);
        return ans;
    }
};