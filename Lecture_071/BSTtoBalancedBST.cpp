
// Qsn-Normal BST to Balanced BST
 
void inorder( Node *root,vector<int>&v){
        if(root==NULL) return;
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
Node* solve(vector<int>&v,int s ,int e){
        if(s>e) return NULL;
        // else we will creatr a new node
        int mid=(s+e)/2;
        Node*root=new Node(v[mid]);
        root->left=solve(v,s,mid-1);
        root->right=solve(v,mid+1,e);
        return root;
}
Node* buildBalancedTree(Node* root)
{
	    vector<int>v;
        inorder(root,v);
        int s=0; int e=v.size()-1;
        Node* newroot=solve(v,s,e);
        return newroot;
}
