class Solution {
public:

    int f(int i,int j,int n1,int n2,bool isEmpty,vector<int>&nums1,vector<int>&nums2,vector<vector<vector<int>>>&dp){
        if(i==n1)return isEmpty?INT_MIN:0;
        if(j==n2)return isEmpty?INT_MIN:0;
        if(dp[i][j][isEmpty]!=INT_MIN)return dp[i][j][isEmpty];
        int takeBoth=nums1[i]*nums2[j]+f(i+1,j+1,n1,n2,false,nums1,nums2,dp);
        int skipI=f(i+1,j,n1,n2,isEmpty,nums1,nums2,dp);
        int skipJ=f(i,j+1,n1,n2,isEmpty,nums1,nums2,dp);
        return dp[i][j][isEmpty]=max({takeBoth,skipI,skipJ});
    }


    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        //the main thing is here atleast 1 pair should be chosen
        int n1=nums1.size();
        int n2=nums2.size();
        bool isEmpty=true;
        vector<vector<vector<int>>>dp(n1,vector<vector<int>>(n2,vector<int>(2,INT_MIN)));
        return f(0,0,n1,n2,isEmpty,nums1,nums2,dp);
    }
};
