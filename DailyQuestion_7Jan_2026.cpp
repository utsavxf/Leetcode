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
    
    int MOD=1e9+7;

    long long calculateTotalSum(TreeNode*root){
        if(!root) return 0;
        return root->val+calculateTotalSum(root->left)+calculateTotalSum(root->right);
    }

    long long traverse(TreeNode*root,long long &ans,long long totalSum){
        if(!root)return 0;
        long long left=traverse(root->left,ans,totalSum);
        long long right=traverse(root->right,ans,totalSum);
        //now I will be detaching you from you parent, let's calculate
        long long currSum=left+right+root->val;
        long long product = (currSum * (totalSum - currSum))%MOD;
        ans=max(ans,product);
        //answer is calculated now give back the combined sum of you and your children
        return currSum;
    }
   
    int maxProduct(TreeNode* root) {
        //forget trees for now, consider normal array, how will you approach this
        //consider 2 numbers 5,3,6 where will you put the partition, cuz on both sides we want big numbers or where we can say the delta will be small, this will be our parition
        //this I came to the conclusion on pen and paper

        //so Intuition is I will start at the bottom and ask the node, I am detaching you from your parent, you have the sum that you have carried till now and remaining sum I can find out from totalSum and then calculate the product
        long long totalSum=calculateTotalSum(root);
        long long ans=INT_MIN;
        long long temp=traverse(root,ans,totalSum);
        return ans%MOD; 
    }
};
