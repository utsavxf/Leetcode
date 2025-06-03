class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        
       
       /*APPROACH
       ->IF THERE IS AN OPEN BOX WE CAN COLLECT CANDIES FROM IT, AFTER THAT WE WOULD
       LOOK IN IT'S CONTAINED BOXES TO SEE IF THEY ARE OPEN OR NOT
       ->NOW THERE CAN BE 2 CASES EITHER THE CONTAINED BOX IS OPEN, IN THIS WE CAN SIMPLY TAKE IT'S CANDIES AND LOOK IN IT'S CONTAINED BOXES
       ->OR IT COULD BE CLOSED, BUT THERE IS A CHANCE THAT LATER WE WOULD FIND A KEY FOR IT AND THEN IT WOULD BE OPEN

       SO ONE THING IS CLEAR WE CANNOT DO SIMPLE 1-WAY TRAVERSAL HERE AS WE WOULD COME BACK FOR CLOSED BOXED WITH THEIR KEYS LATER ON
       SO LET'S PUT ALL THE OPEN BOXES IN A QUEUE AND ALL THE CLOSED BOXES IN A SEPERATE D.S SUCH AS UNORDERED SET

       TAKE AN OPEN BOX FROM QUEUE ADD IT'S CANDIES AND THEN CHECK IT'S CONTAINED BOXES, IF THEY ARE OPEN PUSH THEM TO QUEUE TO BE PROCESSED LATER AND IF THEY ARE CLOSED PUSH THEM TO THE SET

       NOW TRAVERSE THROUGH THE KEYS IN THE CURRENT BOX, IF KEY IS OF A BOX THAT IS ALREADY TRAVERSED AND IS IN SET THEN PUSH IT INTO QUEUE AND ERASE FROM SET
       OR IF THE KEY IS FOUND FOR A BOX THAT IS NOT YET TRAVERSED MARK THE STATUS OF THAT BOX'S STATUS AS 1 SO WHEN IT WILL BE TRAVERSED WE WILL JUST PUSH IT INTO QUEUE
       */
       
       
       
       
       
       int totalCandies=0;
       unordered_set<int>s;
       queue<int>q;
       for(auto it:initialBoxes){
        if(status[it])q.push(it);
        else s.insert(it);
       }
       

       while(!q.empty()){
        int label=q.front();
        q.pop();
        totalCandies+=candies[label];
        //contained boxes
        for(auto it:containedBoxes[label]){
            if(status[it])q.push(it);
            else
            s.insert(it);
        }
        //now keys
        for(auto it:keys[label]){
           //what if it is a key of a boz which is traversed and in locked set
           if(s.find(it)!=s.end()){
              q.push(it);
              s.erase(it);
           }else{
            //means the box is not yet traversed
              status[it]=1; 
           }
        }
       }

       //now in our set we have those boxes left that are still locked
       return totalCandies;
    }
};
