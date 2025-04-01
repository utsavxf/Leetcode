class Solution {
public:
    
    bool isPrime(int n){
        if(n==0 || n==1)return false;
        if(n==2)return true;
        for(int i=2;i*i<=n;i++){
            if(n%i==0)return false;
        }
        return true;
    }

  


    bool primeSubOperation(vector<int>& nums) {
        //prime numbers means sieve of erastosthenese
        //we can pick each index once and even skip some indexes
        //e.g 7,8,3 here we have to make not only 8 smaller than 3 but also 7
        //prime to be subtracted from both of them should be greater than (8-3) and less than 8, I think we can have negative numbers after subtraction, that should be allowed
       //no wrong the number p should be greater less than each element hence no element can be negative

       //we will start from back as starting from front we have to accomodate the elements covered till that index also, i.e. the previous elements
       
       int n=nums.size();
       int maxi=0;
       for(auto it:nums)maxi=max(maxi,it);

       //sieve of eratosthenese
     vector<int> prime(maxi+ 1, 1);
    
    // 0 and 1 are not prime
    prime[0] = prime[1] = 0; 
    
    // Apply Sieve of Eratosthenes
    for (int i = 2; i <= sqrt(n); ++i) {
        if (prime[i] == 1) {
            for (int j = i * i; j <= n; j += i) {
                prime[j] = 0; 
            }
        }
    }







       for(int i=n-2;i>=0;i--){
         if(nums[i]>=nums[i+1]){
            //so ab nums[i] ko just chota kardo nums[i+1] se
            //i.e. find a prime number just bigger then nums[i]-nums[i+1] and obviously smaller than nums[i] as given in the question
            bool flag=false;
            for(int p=nums[i]-nums[i+1]+1;p<nums[i];p++){   //YOU ARE SMART NOW YOU CAN REPLACE THIS FOR LOOP AND FURTHER OPTIMIZE IT BY USING BINARY SEARCH
                if(prime[p]){
                    nums[i]-=p;  //not good practice modifying input
                    flag=true;
                    break;
                }
            }
            if(!flag)return false;
         }
       }
       
       return true; 
    }
};
