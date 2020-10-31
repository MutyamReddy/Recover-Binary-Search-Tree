class Solution {
public:
    void recoverTree(TreeNode* root) {
       TreeNode* curr=root,*first=NULL,*second=NULL,*prev=NULL;
        stack<TreeNode* >s;
        while(curr or !s.empty()){
            if(curr){
                s.push(curr);
                curr=curr->left;
            }
            else{
                TreeNode* temp=s.top();
                s.pop();
                if(prev and prev->val>temp->val){
                    if(first==NULL){
                        first=prev;
                    }
                    second=temp;
                }
                prev=temp;
                curr=temp->right;
            }
        }
        if(first and second){
            swap(first->val,second->val);
        }
    }
};
