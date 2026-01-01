class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
       //if the last digit isn't 9 then question over, if 9 then we'll check previous and like that we will keep on checking
       //so it's a classic carry over game
       int n=digits.size();
       vector<int>result;
       int carry=1;
       int i=n-1;
       
       for(i;i>=0;i--){
         if(digits[i]==9){
            result.push_back(0);
            carry=1;
         }else
         break;
       }

       while(i>=0){
            result.push_back(digits[i]+carry);
            carry=0;
            i--;
        } 
       if(carry)result.push_back(1);

       reverse(result.begin(),result.end());
       return result;
    }
};
