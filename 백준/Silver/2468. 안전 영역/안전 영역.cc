#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void bfs(int a, int b, int height, 
	std::vector<std::vector<int>>& graph, std::vector<std::vector<bool>>& visited)
{
	int N = graph.size();
	std::queue<std::pair<int, int>> q;
	
	q.emplace(a, b);
	visited[a][b] = true;

	while (q.empty() == false)
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		
		for (int idx = 0; idx < 4; ++idx)
		{
			int nx = cx + dx[idx];
			int ny = cy + dy[idx];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N)
			{
				if (visited[nx][ny] == false && graph[nx][ny] > height)
				{
					visited[nx][ny] = true;
					q.emplace(nx, ny);
				}

			}
		}
	
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	
	int N;
	std::cin >> N;

	std::vector<std::vector<int>> graph(N, std::vector<int>(N));

	int max_value = 0;
	for (int row = 0; row < N; ++row)
	{
		for (int col = 0; col < N; ++col)
		{
			std::cin >> graph[row][col];
			max_value = std::max(max_value, graph[row][col]);
		}
	}

	int max_count = 0;

	for (int h = 0;h <=max_value; ++h)
	{
		std::vector<std::vector<bool>> visited(N, std::vector<bool>(N, false));
		int cur = 0;

		for (int r = 0; r < N; ++r)
		{
			for (int c = 0; c < N; ++c)
			{
				if (graph[r][c] > h && visited[r][c] == false)
				{
					cur++;
					bfs(r, c, h, graph, visited);
				}
			}
		}
		max_count = std::max(max_count, cur);
	}
	std::cout << max_count;
}
