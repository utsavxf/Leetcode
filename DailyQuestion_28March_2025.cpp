class Solution {
public:
    
    bool check(int row,int col,int m,int n){
        return row>=0 and row<m and col>=0 and col<n;
    }


    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
      //since we start at the top left, we can only go down and right from there
      //No we have to go in all 4 directions, it's easy to visualize
      //I think we can do m*n k times it will be within the constraints and I can do this I guess
      //as expected brute is giving tle but it should not, anyways brute force is a medium level question so it makes sense
      
      /*
      OPTIMIZED
      see as queries keep on increasing so does the points right?
      when query[i]=2 points=1, when 5 and points 5 when 6 then points 8
      so we can sort the queries and failed positions (only for grid[i][j]>=limit condition) we can store in another queue
      so next time we will start from same points and another queue, using this we can avoid redundant traversals
      but answer we have to give in order so I guess we will create a mapping for that before our operations
      */
 
      int m=grid.size();
      int n=grid[0].size();
      int k=queries.size();
      vector<int>ans(k,0);
      int delX[4]={-1,1,0,0};
      int delY[4]={0,0,-1,1};
      
      /*mapping for returning answer
       unordered_map<int,int>mapping;
       for(int i=0;i<k;i++)mapping[queries[i]]=i;
      */
      //the above will be wrong for duplicate queries
      vector<pair<int,int>>v;
      for(int i=0;i<k;i++)v.push_back({queries[i],i});  //store queries with their indices
      sort(v.begin(),v.end()); //klogk
      
      vector<vector<int>>vis(m,vector<int>(n,0));
      priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
      int points=0;
      pq.push({grid[0][0],{0,0}});
      vis[0][0]=1;
      //worst case when pq has all cells O(k)*O(m*nlog(m*n)) as push and pop is log(size of pq)
      for(auto it:v){
        int limit=it.first;
        int index=it.second;
        while(!pq.empty()){
           int value=pq.top().first;
           int row=pq.top().second.first;
           int col=pq.top().second.second;
           if(value>=limit)break;
           points++;
           pq.pop();
           //check in all 4 directions
           for(int i=0;i<4;i++){
            int nrow=row+delX[i];
            int ncol=col+delY[i];
            if(check(nrow,ncol,m,n) and !vis[nrow][ncol]){
                pq.push({grid[nrow][ncol],{nrow,ncol}});
                vis[nrow][ncol]=1;
            }
           }
        }
        ans[index]=points;
      }
      return ans;
    }
};
