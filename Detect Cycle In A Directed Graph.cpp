#include<bits/stdc++.h>
bool checkcycle(int node, unordered_map<int,bool> &visited,  unordered_map<int,bool> &dfsvisited,  unordered_map<int,list<int>> &adj)
{
  visited[node]=true;
  dfsvisited[node]=true;

  for(auto i: adj[node])
  {
    if(!visited[i])
    {
      bool cycleDetected=checkcycle(i,visited,dfsvisited,adj);
      if(cycleDetected)
      {
        return true;
      }
    }
    else if(dfsvisited[i])
    {
      return true;
    }
  }
  dfsvisited[node]=false;
  return false;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  unordered_map<int,list<int>> adj;
  for(int i=0;i<edges.size();i++)
  {
    int u=edges[i].first;
    int v=edges[i].second;

    adj[u].push_back(v);
  }

  unordered_map<int,bool> visited;
  unordered_map<int,bool> dfsvisited;
  for(int i=1;i<=n;i++)
  {
    if(!visited[i])
    {
      bool cycleFound=checkcycle(i,visited,dfsvisited,adj);
      if(cycleFound)
      {
        return true;
      }
    }
  }
  return false;
}
