#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <variant>

int M, N;
int dx[4] = { -1, 1, 0, 0};
int dy[4] = {0,0,-1,1};

int bfs(int y, int x, std::vector<std::vector<int>> &matrix, std::vector<std::vector<bool>> &visited)
{
	std::queue<std::pair<int,int>> q;
	q.emplace(y,x);
	visited[y][x]  = true;
	int area = 1;
	
	while (q.empty() == false)
	{
		int cury = q.front().first;
		int curx = q.front().second;
		q.pop();
		
		for (int idx=  0; idx<4; ++idx)
		{
			int ny = cury + dy[idx];
			int nx = curx + dx[idx];
			
			if (ny >=0 && ny< M && nx>=0 && nx<N)
			{
				if (visited[ny][nx] == false && matrix[ny][nx] == 0)
				{
					visited[ny][nx] = true;
					q.emplace(ny,nx);
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
	
	int K;
	std::cin>>M>>N>>K;
	
	std::vector<std::vector<int>> matrix(M, std::vector<int>(N, 0));
	std::vector<std::vector<bool>> visited(M, std::vector<bool>(N, false));
	
	for (int idx  = 0; idx<K ;++idx)
	{
		//x1,y1 = left, x2,y2 = right
		int x1, x2, y1, y2; 
		std::cin>>x1>>y1>>x2>>y2;
		for (int y = y1; y<y2; ++y)
		{
			for (int x = x1; x <x2; ++x)
			{
				matrix[y][x] = 1;
			}
		}
	}
	
	std::vector<int> res;
	for (int idx = 0; idx<M ; ++idx)
	{
		for (int s_idx = 0; s_idx <N; ++s_idx)
		{
			if (matrix[idx][s_idx] == 0 && visited[idx][s_idx] == false)
			{
				res.emplace_back(bfs(idx, s_idx, matrix,visited));
			}
		}
	}
	
	std::sort(res.begin(), res.end());
	std::cout<<res.size()<<'\n';
	for (int a : res)
	{
		std::cout<<a<<" ";
	}
}
