//using dummy node
// Step 2: now merge them into single link list.
TreeNode<int>* mergeLinkList(TreeNode<int>*head1,TreeNode<int>*head2){
    TreeNode<int>*dummy=new TreeNode<int>(-1);
    TreeNode<int>*head=dummy;
    TreeNode<int>*tail=dummy;
    while(head1!=NULL && head2!=NULL){
        if(head1->data<head2->data){
            tail->right=head1;
            head1->left=tail;
            tail=head1;
            head1=head1->right;
        }
        else{
           tail->right=head2;
            head2->left=tail;
            tail=head2;
            head2=head2->right;
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
    //important changes
     TreeNode<int>*dlt=head; 

     head=head->right;
     dlt->right=NULL;
     head->left=NULL;

     delete dlt;
     return head;
}



//we can also di this question 
//first save both bst inorder traveral in a vector and sort them 
//them make inorder to bst as previously explained