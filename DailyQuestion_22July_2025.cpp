class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
      //alright so simply choose a subarray where in each element is unique and there sum is maximum
      int n=nums.size();
      //we can obviously do the brute force
      //ok so it's kind of a sliding window
      unordered_set<int>s;
      int maximumSum=0;
      int currentSum=0;
      int left=0;
      int right=0;
      while(right<n){
           //remove duplicate elements
           while(s.find(nums[right])!=s.end() and left<right){
             currentSum-=nums[left];
             s.erase(nums[left]);
             left++;
           }

         //now ok duplicate element has been removed, add this element 
           s.insert(nums[right]);
           currentSum+=nums[right];
           maximumSum=max(maximumSum,currentSum);
           right++;
      }  
      return maximumSum;
    }
};
