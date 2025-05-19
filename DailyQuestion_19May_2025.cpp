class Solution {
public:
    string triangleType(vector<int>& nums) {
      int a=nums[0];
      int b=nums[1];
      int c=nums[2];
      if(a>=b+c || b>=a+c || c>=a+b)return "none";
      else if(a==b and b==c)return "equilateral";
      else if(a==b || a==c || b==c) return "isosceles";
      else return "scalene";   
    }
};
