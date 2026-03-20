#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

int dx[4] = { -1, 1, 0 ,0 };
int dy[4] = { 0,0,-1, 1 };
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, M;
	std::cin >> N >> M;

	std::vector<std::string> maze(N);

	std::vector<std::vector<int>>dist(N, std::vector<int>(M, 0));


	for (int idx = 0; idx < N; ++idx)
	{
		std::cin >> maze[idx];
	}
	std::queue<std::pair<int, int>> que;

	que.emplace(0, 0);
	dist[0][0] = 1;

	while (que.empty() == false)
	{
		int x = que.front().first;
		int y = que.front().second;
		que.pop();

		for (int idx = 0; idx < 4; ++idx)
		{
			int nx = x + dx[idx];
			int ny = y + dy[idx];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M)
			{
				if (maze[nx][ny] == '1' && dist[nx][ny] == 0)
				{
					dist[nx][ny] = dist[x][y] + 1;
					que.emplace(nx, ny);
				}
			}
		}
    }
	std::cout << dist[N - 1][M - 1];
}
