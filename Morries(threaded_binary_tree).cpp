#include<bits/stdc++.h>
using namespace std;




int main(){
    

    //here tree is already constructed named "root"

        TreeNode *curr=root;

        while(curr!=NULL){
            
            if(curr->left!=NULL){
                TreeNode *prev=curr->left;
            
                while(prev->right && prev->right!=curr){
                    prev=prev->right;
                    
                }
                if(prev->right==NULL){
                
                    prev->right=curr;

                    cout<<curr->val<<" ";

                    curr=curr->left;
                }
                else{
                   
                    prev->right=NULL;
                    curr=curr->right;
                }
            }
            else{
                cout<<curr->val<<" ";
                
                curr=curr->right;
            }
        }


   
    return 0;
}
