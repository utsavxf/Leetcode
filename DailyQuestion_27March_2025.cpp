class Solution {
public:

    int findDominantElement(vector<int>&nums){
        int n=nums.size();
        //For this we have an algorithm-> Moore's Voting Algorithm
        int element=nums[0];
        int occurrence=1;
        for(int i=1;i<n;i++){
            if(nums[i]!=element)occurrence--;
            else occurrence++;

            if(occurrence==0){
                element=nums[i];
                occurrence=1;
            }
        }
        return element;
    } 

    int minimumIndex(vector<int>& nums) {
        //obviously there can only be 1 dominant element
        //it is clear that the dominant element that those 2 subarrays will have is equal to the dominant element of the array
        int n=nums.size();
        //we can easily do it in O(n) using precomputation
        int x=findDominantElement(nums);
         vector<int> times(n, 0);
         cout<<x;
         times[0] = (nums[0] == x) ? 1 : 0;
         for (int i = 1; i < n; i++) {
           times[i] = times[i - 1] + (nums[i] == x ? 1 : 0);
         }
        //now again traverse to find actual answer
        for(int i=0;i<n-1;i++){
          int leftLen=i+1;
          int rightLen=n-leftLen;
          bool isLeftDominant=times[i]>(leftLen/2);
          bool isRightDominant=(times[n-1]-times[i])>(rightLen/2);
          if(isLeftDominant and isRightDominant) return i;
        }

        return -1;
    }
};
