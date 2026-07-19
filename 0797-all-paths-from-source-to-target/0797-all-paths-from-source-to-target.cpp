class Solution {
public:

    vector<vector<int>> ans;

    void helper(vector<vector<int>>& graph, vector<bool> visited, int src, int dest, vector<int> &path){

        visited[src] = true;
        path.push_back(src);

        if(src == dest){
            ans.push_back(path);
            path.pop_back();
            return;
        }

        for(int v : graph[src]){
            if(!visited[v]){
                helper(graph,visited,v,graph.size()-1,path);
            }
        }

        visited[src] = false;
        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<bool> visited (n,false);
        vector<int> path;

        helper(graph,visited,0,n-1,path);

        return ans;
    }
};