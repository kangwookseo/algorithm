#include <iostream>
#include <vector>

std::vector<std::vector<int>> graph;
std::vector<bool> visited;

void dfs(int cur)
{
	visited[cur] = true;

	for (int next_node : graph[cur])
	{
		if (visited[next_node] == false)
		{
			dfs(next_node);
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int N, M;

	std::cin >> N >> M;
	graph.resize(N + 1);
	visited.resize(N + 1, false);

	for (int idx = 0; idx < M; ++idx)
	{
		int u, v;
		std::cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);

	}
	int connect = 0;

	for (int idx = 1; idx <= N; ++idx)
	{
		if (visited[idx] == false)
		{
			dfs(idx);
			connect++;
		}
	}

	std::cout << connect<<'\n';
}