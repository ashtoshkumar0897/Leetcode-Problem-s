/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int index=0;
    TreeNode* build(vector<int>& pre,vector<int>& post,int s,int e){
        if(s>e or index>pre.size()-1) return NULL;
        TreeNode* root=new TreeNode(pre[index]);
        index++;
        if(s==e) return root;
        int ni=0;
        for(int i=s;i<=e-1;i++){
            if(post[i]==pre[index]){
                ni=i;
                break;
            }
        }
        root->left=build(pre,post,s,ni);
        root->right=build(pre,post,ni+1,e-1);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return build(preorder,postorder,0,preorder.size()-1);
    }
};