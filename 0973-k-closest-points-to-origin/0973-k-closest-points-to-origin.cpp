// Not optimized TC
// because each insertion costs O(logn) TC, so overall it becomes (nlogn) for n elements.


// class Solution {
// public:
//     vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
//         priority_queue <pair<int,vector<int>>, vector<pair<int,vector<int>>>, greater<pair<int,vector<int>>>> pq;

//         for(int i=0; i<points.size(); i++){

//             int x = points[i][0];
//             int y = points[i][1];

//             int dist = x*x + y*y;
//             pq.push({dist,points[i]});
//         }

//         vector<vector<int>> ans;

//         for(int i=0; i<k; i++){
//             ans.push_back(pq.top().second);
//             pq.pop();
//         }

//         return ans;
//     }
// };

// -----------------------------------------------------------------------------

// Optimal TC
// Max heap of size k - O(n logk)

// Calculating distances     O(n)
// n pushes                  O(n log k)
// up to n pops              O(n log k)
// ------------------------------------
// Total                     O(n log k)

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue <pair<int,vector<int>>> pq;

        for(int i=0; i<points.size(); i++){

            int x = points[i][0];
            int y = points[i][1];

            int dist = x*x + y*y;

            pq.push({dist,points[i]});

            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<vector<int>> ans;

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};