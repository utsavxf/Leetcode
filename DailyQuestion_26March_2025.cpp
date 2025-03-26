class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
       //do grid is even significant here, we can simply a sequence of arrays anyway
       //let's say there are 2 numbers a,b where a<b so b-a must be divisible by x to make them equal
       //man I am stuck
       //so abs(difference between any 2) should be divisible by x then only we can make them equal otherwise -1

       //let's extract in a vector and sort, look at the constraint we can do that
       int m=grid.size();
       int n=grid[0].size();
       vector<int>v;
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            v.push_back(grid[i][j]);
        }
       }      
       //O(m*nlog(m*n)) and m*n<=1e5
       sort(v.begin(),v.end());

       //if differences are alright then we can move all of them to the middle
       
       // I am basically combining the check all differences are divisible by x and finding minimum operations in 1 step
       if(v.size()==1)return 0;
       int median=v[v.size()/2];
       int operations=(median-v[0])/x;
       for(int i=1;i<v.size();i++){
          if((v[i]-v[i-1])%x!=0)return -1;
          else operations+=abs(median-v[i])/x;
        }
       
       return operations;
    }
};
