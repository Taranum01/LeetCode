class Solution {
public:
    
    bool kahnsAlgo(vector<vector<int>>&adj, int n, vector<int>&inDegree, vector<int>&ans){

        queue<int> q;
        
	    for (int i = 0; i < n; i++)
		if (inDegree[i] == 0)
			q.push(i);
        
        int count=0;

        while (!q.empty())
	    {
		int curr = q.front();
		q.pop();
            for (auto a : adj[curr])
		{
			inDegree[a]--;
			if (inDegree[a] == 0)
				q.push(a);
		}
            ans.push_back(curr);
            count++;
        }
        
        if (count != n)
		   return false;
	    return true;
}
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        int n= prerequisites.size();

        vector<vector<int>>adj(numCourses);
        vector<int>inDegree(numCourses,0);
        
        for (int i = 0; i < n; i++)
	    {
		adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
		inDegree[prerequisites[i][0]]++;
	    }
        
        vector<int>ans;

	    if (kahnsAlgo(adj, numCourses, inDegree, ans))
		return ans;
        
        vector<int> empty;

	    return empty;
    }
};

