class Solution {
public:

    // Topological Sorting Question.
    // We do not need to do Topological sort, we just need to find whether we can do it.
    // Checking condition for Directed Acyclic Graph. 

    int isCycle(int src, vector<vector<int>>& graph, vector<bool> &visited, vector<bool> &recPath) {

        visited[src] = true;
        recPath[src] = true;
        vector <int> neighbours = graph[src];

        for(int v : neighbours){
            if(!visited[v]){
                if(isCycle(v,graph,visited,recPath)){
                    return true;
                }
            }
            else{
                if(recPath[v]){
                    return true;
                }
            }
        }

        recPath[src] = false;

        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<bool> visited(numCourses,false);
        vector<vector<int>> adjlist(numCourses);

        for(auto &p : prerequisites){
            adjlist[p[1]].push_back(p[0]);
        }

        vector<bool> recPath(numCourses, false);

        for(int i=0; i<numCourses; i++){
            if(isCycle(i,adjlist,visited,recPath)){
                return false;
            }
        }

        return true;
    }
};