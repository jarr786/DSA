
class Solution{
    //instead of finding position we can also use mapping to get better time complexity
    int findPosition(int in[],int x,int n){
        for(int i=0;i<n;i++){
            if(in[i]==x) return i;
        }
        return -1;
    }
    Node*solve(int in[],int pre[],int &index,int inorderStart,int inorderEnd,, int n){
        if(index>=n || inorderStart>inorderEnd){
             return NULL;
        }
        int element=pre[index++];
        Node*root=new Node(element);
        
        int position=findPosition(in,element,n);
        
        root->left=solve(in,pre,index,inorderStart,position-1,n);
        root->right=solve(in,pre,index,position+1,inorderEnd,n);
        
        return root;
    }
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        int preOderindex=0;
        Node*ans=solve(in,pre,preOderindex ,0, n-1,n);
        return ans;
    }
};
