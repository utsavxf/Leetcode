class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
      long long sum1=0;
      int zerocount1=0;
      long long sum2=0;
      int zerocount2=0;
      for(auto it:nums1){
        if(it==0)zerocount1++;
        sum1+=it;
      }      
      for(auto it:nums2){
        if(it==0)zerocount2++;
        sum2+=it;
      }  

      cout<<sum1<<" "<<zerocount1<<endl;
      cout<<sum2<<" "<<zerocount2<<endl;

      long long ans=0;
      
      if(sum1+zerocount1>sum2+zerocount2){
        if(zerocount2==0)ans=-1;
        else ans=sum1+zerocount1;
      }
      else if(sum2+zerocount2>sum1+zerocount1){
        if(zerocount1==0)ans=-1;
        else ans=sum2+zerocount2;
      }
      else ans=sum1+zerocount1;

      return ans;

    }
};
