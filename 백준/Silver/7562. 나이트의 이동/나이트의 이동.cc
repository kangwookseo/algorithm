#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

int L;
int dx[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

int bfs(int startx, int starty, int targetx, int targety, std::vector<std::vector<int>>&chess, std::vector<std::vector<bool>>& visited)
{
	std::queue<std::pair<int, int>> q;

	q.emplace(startx, starty);
	visited[startx][starty] = true;
	chess[startx][starty] = 0;

	while (q.empty() == false)
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		if (cx == targetx && cy == targety)
		{
			return chess[cx][cy];
		}

		for (int idx = 0; idx < 8; ++idx)
		{
			int nx = cx + dx[idx];
			int ny = cy + dy[idx];

			if (nx >= 0 && nx < L && ny >=0 && ny < L)
			{
				if (visited[nx][ny] == false)
				{
					visited[nx][ny] = true;
					chess[nx][ny] = chess[cx][cy] + 1;
					q.emplace(nx, ny);
				}
			}
		}
	}
	return 0;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	
	int T;
	std::cin >> T;
	
	while (T-- > 0)
	{
		int start_x, start_y, target_x, target_y;
		std::cin >> L;
		std::cin >> start_x >> start_y;
		std::cin >> target_x >> target_y;

		std::vector<std::vector<int>> chess(L, std::vector<int>(L, 0));
		std::vector<std::vector<bool>> visited(L, std::vector<bool>(L,false));

		int result = bfs(start_x, start_y, target_x, target_y, chess, visited);
		std::cout << result << '\n';
	}
}
