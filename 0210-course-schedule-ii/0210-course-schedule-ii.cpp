class Solution {
public:

    int hasCycle(int src, vector <vector<int>> &graph, vector<bool> &visited, vector<bool> &recPath){

        visited[src] = true;
        recPath[src] = true;

        vector <int> neighbours = graph[src];

        for(int v : neighbours){
            if(!visited[v]){
                if(hasCycle(v,graph,visited,recPath)){
                    return true;
                }
            }
            else if(recPath[v]){
                return true;
            }
        }

        recPath[src] = false;

        return false;
    }

    void topoSortHelper(int src,vector <vector<int>> &graph, vector<bool> &visited, stack <int> &st){

        visited[src] = true;
        vector <int> neighbours = graph[src];

        for(int v : neighbours){
            if(!visited[v]){
                topoSortHelper(v,graph,visited,st);
            }
        }

        st.push(src);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector <vector<int>> adjlist(numCourses);
        vector <bool> visited(numCourses,false);
        vector <int> ans;

        for(auto &p : prerequisites){
            adjlist[p[1]].push_back(p[0]);
        }

        vector <bool> recPath(numCourses,false);

        for(int i=0; i<numCourses; i++){
            if(!visited[i]){
                if(hasCycle(i,adjlist,visited,recPath)){
                    return {};
                }
            }
        }

        visited.assign(visited.size(), false);
        stack<int> st;
        
        for(int i=0; i<numCourses; i++){
            if(!visited[i]){
                topoSortHelper(i,adjlist,visited,st);
            }
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};