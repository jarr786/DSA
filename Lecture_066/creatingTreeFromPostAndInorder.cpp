
    //instead of finding position we can also use mapping to get better time complexity
int findPosition(int in[],int x,int n){
        for(int i=0;i<n;i++){
            if(in[i]==x) return i;
        }
        return -1;
    }
    Node*solve(int in[],int post[],int &index,int inorderStart,int inorderEnd, int n){
        if(index<0 || inorderStart>inorderEnd){
             return NULL;
        }
        int element=post[index--];
        Node*root=new Node(element);
        
        int position=findPosition(in,element,n);
        
        root->right=solve(in,post,index,position+1,inorderEnd,n);
        root->left=solve(in,post,index,inorderStart,position-1,n);
        
        return root;
    }
//Function to return a tree created from postorder and inoreder traversals.
Node *buildTree(int in[], int post[], int n) {
    // Your code here
     int preOderindex=n-1;
        Node*ans=solve(in,post,preOderindex ,0, n-1,n);
        return ans;
}
