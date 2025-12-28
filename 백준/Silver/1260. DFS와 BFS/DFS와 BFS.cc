#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

//queue
void bfs(int start, std::vector<bool> &visited , std::vector<std::vector<int>> &graph)
{
	std::queue<int> q;
	q.push(start);
	visited[start] = true;

	while (q.empty() == false)
	{
		int cur = q.front();
		q.pop();
		std::cout << cur << " ";
		
		for (int next : graph[cur])
		{
			if (visited[next] == false)
			{
				visited[next] = true;
				q.push(next);
			}
		}
	}
}

//stack
void dfs(int start, std::vector<bool> &visited, std::vector<std::vector<int>> &graph)
{
	std::stack<int> s;
	s.push(start);

	while (s.empty() == false)
	{
		int cur = s.top();
		s.pop();

		if (visited[cur])
			continue;
		visited[cur] = true;
		std::cout << cur << " ";

		for (int idx = graph[cur].size() - 1; idx >= 0; --idx)
		{
			int next = graph[cur][idx];
			if (visited[next]==false)
			{
				s.push(next);
			}
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, M, V;
	std::cin >> N >> M >> V;

	std::vector<std::vector<int>> graph(N+1);
	std::vector<bool> visited(N+1,false);

	for (int idx = 0; idx < M; ++idx)
	{
		int a, b;
		std::cin >> a >> b;
		
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int idx = 1; idx <= N; ++idx)
	{
		std::sort(graph[idx].begin(), graph[idx].end());
	}

	dfs(V, visited, graph);
	std::cout << '\n';

	//Clear visited flags for BFS execution.
	std::fill(visited.begin(), visited.end(), false);

	bfs(V, visited, graph);
	std::cout << '\n';
	

}