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

    void levelOrderTraversal(TreeNode*root,int&maxDepth,int&countDeepLeaves){
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            TreeNode*node=q.front().first;
            int level=q.front().second;
            q.pop();
            if(level>maxDepth){
                maxDepth=level;
                countDeepLeaves=1;
            }else if(level==maxDepth){
                countDeepLeaves++;
            }
            if(node->left)q.push({node->left,level+1});
            if(node->right)q.push({node->right,level+1});
        }       
    }

    int dfs(TreeNode*root,int lvl,int maxDepth,int countDeepLeaves,TreeNode*&ans){
       if(!root)return 0;
       if(!root->left and !root->right and lvl==maxDepth){
          if(countDeepLeaves==1)ans=root;
          return 1;
       }
       int left=dfs(root->left,lvl+1,maxDepth,countDeepLeaves,ans);
       int right=dfs(root->right,lvl+1,maxDepth,countDeepLeaves,ans);
       if(left+right==countDeepLeaves and !ans)ans=root;
       return left+right;
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        //If I get to know the level and the count of deepest leaves, then I can do it
        //level order traversal will good for that
        int maxDepth=0;
        int countDeepLeaves=0;
        levelOrderTraversal(root,maxDepth,countDeepLeaves);
        cout<<"maxDepth: "<<maxDepth<<" leaves: "<<countDeepLeaves<<endl;
        //now I will use the lca logic that if some node is getting countDeepLeaves from below, then I will return that node
        TreeNode*ans=NULL;
        int lvl=0;
        dfs(root,lvl,maxDepth,countDeepLeaves,ans);
        return ans;
    }
};
