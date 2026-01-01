class Solution {
public:
    int bestClosingTime(string customers) {
        //if you close the shop at jth hour, then afterwards whatever Y will be there will incurr in penalty
        //and before whatever N will be there will incurr in penalty so we have to keep both of them to a minimum
        //I think it can easily be done by making 2 traversals, one from left to right, then from right to left and maintaining a vector
        
        int n=customers.size();
        vector<int>count(n,0);

        //left traversal, we are assuming at the ith hour shop is closed
        int countN=0;
        for(int i=0;i<n;i++){
           count[i]=countN;
           if(customers[i]=='N')countN++;
        }

        //right traversal, we are assuming at the ith hour shop is closed
        int countY=0;
        int minCount=countN; //there is a case of closing the shop at the last hour (Nth hour)
        int index=n;
        for(int i=n-1;i>=0;i--){
           if(customers[i]=='Y')countY++;
           if(minCount>=count[i]+countY){
            minCount=count[i]+countY;
            index=i; //we are deliberately overriding the index as we want the smallest as asked in the problem
           }
           
        }

        return index;

    }
};
