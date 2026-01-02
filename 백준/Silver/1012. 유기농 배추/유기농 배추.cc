#include <iostream>
#include <vector>
#include <stack>


void dfs(int start_y, int start_x,int N, int M,std::vector<std::vector<bool>> &visited, 
	const std::vector<std::vector<int>> &field)
{
	int dy[4] = { -1,1,0,0 };
	int dx[4] = { 0,0,-1,1 };
	
	std::stack<std::pair<int, int>> s;
	s.push({ start_y,start_x });

	while (s.empty() == false)
	{
		std::pair<int, int> cur = s.top();
		s.pop();

		int cy = cur.first;
		int cx = cur.second;

		if (visited[cy][cx] == true)
		{
			continue;
		}
		visited[cy][cx] = true;
		
		for (int idx = 0; idx<4; ++idx)
		{
			int ny = cy + dy[idx];
			int nx = cx + dx[idx];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
			{
				continue;
			}
			if (field[ny][nx] == 1 && visited[ny][nx] == false)
			{
				s.push({ ny,nx });
			}
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T;

	std::cin >> T;
	for (int idx = 0; idx < T; ++idx)
	{
		int M, N, K;
		std::cin >> M >> N >> K;

		std::vector<std::vector<int>> field(N,std::vector<int>(M,0));
		std::vector<std::vector<bool>> visited(N,std::vector<bool>(M,false));

		for (int idx_ = 0; idx_ < K; ++idx_)
		{
			int X, Y;
			std::cin >> X >> Y;
			field[Y][X] = 1;
		}

		int count = 0;

		for (int y = 0; y < N; ++y)
		{
			for (int x = 0; x < M; ++x)
			{
				if (field[y][x] == 1 && visited[y][x] == false)
				{
					count++;
					dfs(y, x, N, M, visited, field);
				}
			}
		}
		std::cout << count << '\n';
	}
}
