#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

int bfs(int start, int N, const std::vector<std::vector<int>> &graph)
{
	std::vector<int> dist(N+1, -1);
	std::queue<int> q;
	q.emplace(start);
	dist[start] = 0;
	
	int total_bacon = 0;
	
	while (q.empty() == false)
	{
		int curr = q.front();
		q.pop();
		
		for (int next : graph[curr])
		{
			if (dist[next] == -1)
			{
				dist[next] = dist[curr] +1;
				total_bacon += dist[next];
				
				q.emplace(next);
			}
		}
	}
	return total_bacon;
	
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
		
	int N, M;
	std::cin>>N>>M;
	
	std::vector<std::vector<int>> graph(N+1);
	
	while (M-- > 0)
	{
		int x, y;
		std::cin>>x>>y;
		
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	
	int min_bacon = 999999;
	int ans  = 0;
	
	for (int idx = 1 ; idx<=N; ++idx)
	{
		int cur_bacon = bfs(idx, N, graph);
		
		if (cur_bacon < min_bacon)
		{
			min_bacon = cur_bacon;
			ans = idx;
		}
	}
	std::cout<<ans;
	
}
