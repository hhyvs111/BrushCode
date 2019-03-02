class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        //课程安排，这里的意思是给你一个序列队，必须按顺序，看是否能完成，比如01，代表完成课程0需要先完成1.
        //那么用一个map寸这个课程，有课程就置为1，然后看是否有这个值
        //这里好像不对啊，主要看是否有冲突，如果有冲突则不行。那么看是否有冲突的pair
        
        //用图DFS遍历，看是否有回路。可以递归也可以用队列。
        //初始化一个二维矩阵,其实就是节点到节点的值
        vector<vector<int>> graph(numCourses, vector<int>(0));
        //1为其他节点正在访问该节点，0为未访问,-1为节点已经被访问了，如果再次访问则直接返回false
        vector<int> visit(numCourses, 0);
        //建图
        for(auto it : prerequisites)
        {
            graph[it.second].push_back(it.first);
        }
        for(int i = 0;i < numCourses; i++)
        {
            if(!dfs(graph, i, visit)) return false;
        }
        return true;
        
    }
    
    bool dfs(vector<vector<int>> & graph, int node,vector<int> &visit)
    {
        //这个节点已经被自己给访问过了
        if(visit[node] == -1) return false;
        //这个节点被其他节点访问，直接返回，这里是dfs的一处优化
        if(visit[node] == 1) return true;
        visit[node] = -1;
        for (auto a : graph[node]) {
            if (!dfs(graph, a, visit)) return false;
        }
        //访问完毕，此时代表该节点被node给访问了。
        visit[node] = 1;
        return true;
    }
};

//明天用拓扑排序做一下