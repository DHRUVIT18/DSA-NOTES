bool f(TreeNode<int> *root,TreeNode<int> *leaf,stack<TreeNode<int> *>&st){
    st.push(root);
    
    if(!root->left and !root->right){
        if(root->data==leaf->data){
            return true;
        }else{
            st.pop();
            return false;
        }
    }
    if(root->left){
        if(f(root->left,leaf,st))return true;
    }
    if(root->right){
        if(f(root->right,leaf,st))return true;
    }
    st.pop();
    return false;
}

TreeNode<int> * invertBinaryTree(TreeNode<int> *root, TreeNode<int> *leaf)
{
    if(!root)return NULL;
    stack<TreeNode<int> *>st;
    bool flag=f(root,leaf,st);
   // cout<<st.size()<<endl;
    auto new_root=st.top();
    st.pop();
    auto par=new_root;
    while(!st.empty()){
        auto curr=st.top();
        st.pop();
        if(curr->left==par){
            curr->left=NULL;
            par->left=curr;
        }else{
            curr->right=curr->left;
            curr->left=NULL;
            par->left=curr;
        }
        par=curr;
    }
    return new_root;
}