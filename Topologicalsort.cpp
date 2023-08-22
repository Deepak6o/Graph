#include<bits/stdc++.h>
void toposort(int node,unordered_map<int,bool> &visited, stack<int> &s,unordered_map<int,list<int>> &adj)
{
	visited[node]=1;
	for(auto i: adj[node])
	{
		if(!visited[i])
		{
			toposort(i,visited,s,adj);
		}
	}
	s.push(node);
}
vector<int> topologicalSort(vector<pair<int,int>>& edges, int N, int M)
{
	/* 
	   Write your code here
	   Return any valid topolocial Sort
	   Verdict: 'Valid' or 'Invalid'

	*/
	unordered_map<int,list<int>> adj;
	for(int i=0;i<M;i++)
	{
		int u=edges[i].first;
		int v=edges[i].second;

		adj[u].push_back(v);
	}

	unordered_map<int,bool> visited;
	stack<int> s;
	for(int i=1;i<=N;i++)
	{
		if(!visited[i])
		{
			toposort(i,visited,s,adj);
		}
	}
	vector<int> ans;
	while(!s.empty())
	{
		ans.push_back(s.top());
		s.pop();
	}
	return ans;
} 
