/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
   struct Node {
      int data;
      Node* left;
      Node* right;
   }
*/

    bool checkBST(Node* root){
        if(!root){
            return true;
        }
        int min = -1;
        int max = 10001;
        return checkBST(root->left, min, root->data) && checkBST(root->right, root->data, max);
    }

    bool checkBST(Node* root, int min, int max){
        //
        // root is a BST if it and its subnodes follow the ordering rules:
        // - root->left->data < root->data < root->right->data
        // - there are no duplicate values
        //
        // ordering rules are violated if root->data <= min  or if root->data >= max.
        // if ordering rules are not violated then there are no duplicates.
        //
        
        // check if the node is null
        if(!root){
            return true;
        }
        // check if this node violates ordering rules
        if(root->data <= min || root->data >= max){
            return false;
        }
        // check if subnodes violate ordering rules
        bool isBST = true;
        if(root->left){
            isBST = checkBST(root->left, min, root->data);
        }
        if(root->right){
            isBST = isBST && checkBST(root->right, root->data, max);
        }
        return isBST;
    }
