#include <iostream>
#include <queue>
#include <algorithm>

int n, m;

int dx[4] = {-1, 1, 0 , 0};
int dy[4] = {0,0,-1,1};

int bfs(int start_x, int start_y,  const std::vector<std::vector<int>> &matrix, std::vector<std::vector<bool>> &visited )
{
	std::queue<std::pair <int, int>> q;
	q.emplace(start_x, start_y);
	visited[start_x][start_y] = true;
	
	int area = 1;
	
	while (q.empty() == false)
	{
		std::pair <int, int> cur = q.front();
		q.pop();
		
		for (int idx = 0; idx<4; ++idx)
		{
			int nx = cur.first + dx[idx];
			int ny = cur.second + dy[idx];
			
			if (nx >=0 && nx<n && ny >=0 && ny <m )
			{
				if (visited[nx][ny] == false && matrix[nx][ny] == 1)
				{
					visited[nx][ny] = true;
					q.emplace(nx, ny);
					area++;
				}
			}
		}
	}
	return area;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
		
	std::cin>>n>>m;
	
	std::vector<std::vector<int>> matrix(n, std::vector<int>(m));
	std::vector<std::vector<bool>> visited(n, std::vector<bool>(m , false));
	
	for (int idx = 0; idx< n; ++idx)
	{
		for (int s_idx = 0; s_idx<m; ++s_idx)
		{
			std::cin>>matrix[idx][s_idx];
		}
	}
	
	int pic_count = 0;
	int max_area = 0;
	
	for (int idx = 0; idx<n ; ++idx)
	{
		for (int s_idx = 0; s_idx<m; ++s_idx)
		{
			if (matrix[idx][s_idx] == 1 && visited[idx][s_idx] == false)
			{
				pic_count++;
				
				int current_area = bfs(idx,s_idx, matrix, visited);
				max_area = std::max(max_area, current_area);
			}
		}
	}
	
	std::cout<<pic_count<<'\n';
	std::cout<<max_area;
	
}
