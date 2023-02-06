class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        //base case 
         if(node==NULL) return 0;
         //nahi to ye karo
         int hLeft=height(node->left);
         int hRight=height(node->right);
         //ans=left vali or right valli height ka max plus one
         return max(hLeft,hRight)+1;
    }
};


