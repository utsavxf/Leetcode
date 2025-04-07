class Solution {
public:
   
    bool f(int i,int n,int remainingSum,vector<int>&nums){
        if(remainingSum==0)return true;
        if(i==n)return false;
        bool take=false;
        if(nums[i]<=remainingSum)take=f(i+1,n,remainingSum-nums[i],nums);
        bool not_take=f(i+1,n,remainingSum,nums);
        return take || not_take; 
    }

    bool canPartition(vector<int>& nums) {
        //the question reduces to can we find a subset which is equal to S/2 where S refers to the total sum
        int n=nums.size();
        int totalSum=0;
        for(auto it:nums)totalSum+=it;
        if(totalSum&1)return false; //it cannot be odd
        // return f(0,n,totalSum/2,nums);
        
        //in tabulation we can think in the direction like can we find a subset with total sum as dp[i] or not
        vector<int>dp(totalSum/2+1,0);
        dp[0]=1; //0 element subset
        
        //we can even sort the array as we are only concerned with subsets
        sort(nums.begin(),nums.end());
        
        //THE BELOW APPROACH IS WRONG IT TAKES INTO ACCOUNT INFINITE SUPPLY OF EACH ELEMENT
        // for(int sum=1;sum<=totalSum/2;sum++){ACCC
        //     for(int i=0;i<n;i++){
        //        if(nums[i]>sum)break;
        //        if(dp[sum-nums[i]]){
        //         dp[sum]=1;
        //         break;
        //        }
        //     }
        // }

        //WE HAVE TO MAKE SURE EACH ELEMENT IS USED ONLY ONCE SO WE'LL INTERCHANGE THE LOOPS
        //WE HAVE TO ALSO CHANGE THE DIRECTION TO MAKE SURE WE ARE NOT USING THE SAME ELEMENT TWICE 
        for(int i=0;i<n;i++){
            for(int sum=totalSum/2;sum>=nums[i];sum--){
                if(dp[sum-nums[i]])dp[sum]=1;
            }
        }
        return dp[totalSum/2];
    }
};
