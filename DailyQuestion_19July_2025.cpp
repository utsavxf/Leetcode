class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
    int n=folder.size(); 
    //we can sort the strings on the basis of size so that we will traverse the strings level wise
     
     sort(folder.begin(),folder.end());

    //   for(int i=0;i<n;i++)
    //   cout<<folder[i]<<endl;

      unordered_set<string>s1;
      vector<string>result;
      for(auto it:folder){
        //I have to check each parents of this string and determine whether they exist in the map or not, if not add this string to the map, if yes ignore and move forward but how the fuck do I do that? am I that dumb?
        string temp="";
        bool flag=false;
        for(auto s:it){
            
            if(s=='/' and !temp.empty()){
                 //right now we have a parent, check for this before moving onto smaller parent
                 if(s1.find(temp)!=s1.end()){
                    flag=true;
                    break;
                 }
            }
            temp+=s;
        }
        if(!flag){
         s1.insert(temp);
         result.push_back(temp);
        }
      }

      return result; 
    }
};
