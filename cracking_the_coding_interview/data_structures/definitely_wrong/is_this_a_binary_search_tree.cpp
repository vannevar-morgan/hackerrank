#include <map>
    bool checkBST(Node* root){
        std::map<int, unsigned int> tree_vals;
        if(!root){
            return true;
        }
        tree_vals[root->data]++;
        return checkBST(root, tree_vals);
    }

    bool checkBST(Node* root, std::map<int, unsigned int>& tree_vals) {
        //
        // Check whether a binary tree is a BST.
        // A binary tree is a BST if:
        //  -left_node < current_node
        //  -right_node > current_node
        //  -the binary tree does not contain duplicate values
        //
        if(root->left){
            if(root->left->data >= root->data){
                return false;
            }
            if(tree_vals[root->left->data]++){
                return false;
            }
            checkBST(root->left, tree_vals);
        }
        if(root->right){
            if(root->right->data <= root->data){
                return false;
            }
            if(tree_vals[root->right->data]++){
                return false;
            }
            checkBST(root->right, tree_vals);
        }
        return true;
    }
