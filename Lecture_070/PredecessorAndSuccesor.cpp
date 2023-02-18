//find predecessor and successor when root and a key is given

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
     BinaryTreeNode<int>*temp=root;
     int pred=-1;
     int succ=-1;
     while(temp->data!=key){
         if(temp->data>key){
             succ=temp->data;
             temp=temp->left;
         }
         else{
             pred=temp->data;
             temp=temp->right;
         }
     }
     //pred
     BinaryTreeNode<int>*ln=temp->left;
     while(ln!=NULL){
         pred=ln->data;
         ln=ln->right;
     }
     //succ
     BinaryTreeNode<int>*rn=temp->right;
     while(rn!=NULL){
         succ=rn->data;
         rn=rn->left;
     }
     return {pred,succ};
}
