class Solution {
public:
    
    int getDigitSum(int n){
        int sum=0;
        while(n>0){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }

    int countLargestGroup(int n) {
      //brute force digit sum->map->1 traversal
      unordered_map<int,int>m;
      for(int i=1;i<=n;i++){
        m[getDigitSum(i)]++;
      } 
      int largestSize=0;
      int cntGrps=0;
      for(auto it:m){
        if(it.second>largestSize){
            largestSize=it.second;
            cntGrps=1;
        }
        else if(it.second==largestSize)cntGrps++;
        
      }

      return cntGrps;   
    }
};
