class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<bool> visited(n,false);
        queue <int> q;
        vector<int> color(n,-1);

        for(int i = 0; i < n; i++){

            if(visited[i]){
                continue;
            }

            q.push(i);
            visited[i] = true;
            color[i] = 0;

            while(q.size()){
   
                int u = q.front();
                q.pop();

                vector <int> neighbours = graph[u];

                for(int v : neighbours){

                    if(visited[v] == false){
                        if(color[u] == 0){
                            color[v] = 1;
                        }
                        else{
                            color[v] = 0;
                        }

                        visited[v] = true;
                        q.push(v);
                    }
                    else{
                        if(color[u] == color[v]){
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};