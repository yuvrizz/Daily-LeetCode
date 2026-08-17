class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        
        int nearest = INT_MAX;
        int idx = -1;

        for(int i=0; i<drones.size(); i++){
            int dis = abs(target[0]-drones[i][0]) + abs(target[1]-drones[i][1]);
            if (dis <= drones[i][2]){
                if(dis < nearest){
                    nearest = min(nearest,dis);
                    idx = i;
                }
            }
        }

        return idx;
    }
};
