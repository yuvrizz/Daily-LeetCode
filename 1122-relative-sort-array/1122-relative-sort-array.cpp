class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {

        map <int,int> m;
        vector<int> ans;

        for(int i=0; i<arr1.size(); i++){
            m[arr1[i]]++;
        }

        for(int i=0; i<arr2.size(); i++){
            for(int j=0; j < m[arr2[i]]; j++){
                ans.push_back(arr2[i]);
            }
            m.erase(arr2[i]);
        }

        for (const auto &v : m){
            for(int i=0; i<v.second; i++){
                ans.push_back(v.first);
            }
        }

        return ans;
    }
};