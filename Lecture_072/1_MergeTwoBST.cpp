// Step 1: convert both bst into  link list.
// Step 2: now merge them into single link list.
// Step 3: now convert link list into bst.

/*************************************************************/

// Step 1: convert both bst into  link list.
void convertIntoSotedDDL(TreeNode<int>*root,TreeNode<int>*&head){
    if(root==NULL) return ;
    convertIntoSotedDDL(root->right,head);
    root->right=head;
    if(head!=NULL)
    head->left=root;
    head=root;
    convertIntoSotedDDL(root->left,head);
}
// Step 2: now merge them into single link list.
TreeNode<int>* mergeLinkList(TreeNode<int>*head1,TreeNode<int>*head2){
    TreeNode<int>*head=NULL;
    TreeNode<int>*tail=NULL;
    while(head1!=NULL && head2!=NULL){
        if(head1->data<head2->data){
           if(head==NULL){
            head=head1;
            tail=head1;
            head1=head1->right;
           }
           else{
            tail->right=head1;
            head1->left=tail;
            tail=head1;
            head1=head1->right;
           }
        }
        else{
            if(head==NULL){
            head=head2;
            tail=head2;
            head2=head2->right;
            } 
            else{
            tail->right=head2;
            head2->left=tail;
            tail=head2;
            head2=head2->right;
            }
        }
    }
    while(head1!=NULL){
            tail->right=head1;
            head1->left=tail;
            tail=head1;
            head1=head1->right;
    }
    while(head2!=NULL){
            tail->right=head2;
            head2->left=tail;
            tail=head2;
            head2=head2->right;
    }
     
    return head;
}
//count no of nodes
int countNodes(TreeNode<int>*head){
    int cnt=0;
    TreeNode<int>*temp=head;
    while(temp!=NULL){
        cnt++;
        temp=temp->right;
    }
    return cnt;
}
// Step 3: now convert link list into bst.
TreeNode<int>* sortedLinklistToBst(TreeNode<int>*&head,int n){
    if(n<=0 || head== NULL) return NULL;
 
    TreeNode<int>*left=sortedLinklistToBst(head,n/2);

    TreeNode<int>*root=head;
    root->left=left;
    head=head->right;
    root->right=sortedLinklistToBst(head,n-n/2-1);

    return root;
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    // Write your code here.
    TreeNode<int> *head1=NULL;
    convertIntoSotedDDL(root1,head1);     //step-1
    head1->left=NULL; 

    TreeNode<int> *head2=NULL;
    convertIntoSotedDDL(root2,head2);     //step-1
    head2->left=NULL;

    TreeNode<int> *head=mergeLinkList(head1,head2);        //step-2
    
    int n=countNodes(head);
    return sortedLinklistToBst(head,n);        ////s3ep-2
}