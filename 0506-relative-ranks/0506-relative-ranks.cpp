class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
        priority_queue <int> pq (score.begin(), score.end());
        unordered_map<int,int> mp;
        vector<string> ans;
        int pos = 1; 

        for(int i=0; i<score.size(); i++){
            mp[pq.top()] = pos;
            pq.pop(); 
            pos++;
        }

        for(int i=0; i<score.size(); i++){
            if(mp[score[i]] == 1){
                ans.push_back("Gold Medal");
            }
            else if(mp[score[i]] == 2){
                ans.push_back("Silver Medal");
            }
            else if(mp[score[i]] == 3){
                ans.push_back("Bronze Medal");
            }
            else{
                ans.push_back(to_string(mp[score[i]]));
            }
        }

        return ans;
    }
};