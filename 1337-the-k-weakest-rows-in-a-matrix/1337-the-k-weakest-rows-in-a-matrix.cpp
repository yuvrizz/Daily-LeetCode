class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        vector<pair<int,int>> p; 

        for(int i=0; i<mat.size(); i++){
            int count = 0;
            for(int j=0; j<mat[0].size(); j++){
                if(mat[i][j] == 0){
                    break;
                }
                count++;
            }
            p.push_back(make_pair(count,i));
        }

        priority_queue < pair<int,int>,  vector<pair<int,int>>,  greater<pair<int,int>>> pq(p.begin(),p.end());
        vector<int> ans;

        for(int i=0; i<k; i++){
            int top = pq.top().second;
            ans.push_back(top);
            pq.pop();
        }

        return ans;
    }
};