#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0,0,-1,1};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
		
	int M,N;
	std::cin>>M>>N;
	
	std::vector<std::vector<int>> tomato(N, std::vector<int> (M));
	std::queue<std::pair<int,int>> start;
	
	for (int idx = 0; idx<N; ++idx)
	{
		for (int s_idx = 0; s_idx<M; ++s_idx)
		{
			std::cin>>tomato[idx][s_idx];
			if (tomato[idx][s_idx] == 1)
			{
				start.emplace(idx, s_idx);
			}
		}
	}
	
	auto bfs = [&]()
	{
		while (start.empty() == false)
		{
			int x = start.front().first;
			int y = start.front().second;
			start.pop();
			
			for (int idx = 0; idx<4; ++idx)
			{
				int nx = x + dx[idx];
				int ny = y + dy[idx];
				
				if (nx >= 0 && nx < N && ny >= 0 && ny < M)
				{
					if (tomato[nx][ny] == 0)
					{
						tomato[nx][ny] = tomato[x][y] +1;
						start.emplace(nx, ny);
					}
				}
			}
		}
	};
	
	bfs();
	
	int result = 0;
	for (int idx = 0; idx<N ; ++idx)
	{
		for (int s_idx = 0; s_idx<M; ++s_idx)
		{
			if (tomato[idx][s_idx] == 0)
			{
				std::cout<<-1;
				return 0;
			}
			result = std::max(result, tomato[idx][s_idx]);
		}
	}
	std::cout<<result-1;
}
