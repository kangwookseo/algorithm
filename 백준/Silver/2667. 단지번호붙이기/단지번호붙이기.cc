#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

int n;
std::vector<std::string > map;

int dx[4] = { -1 ,1, 0, 0 };
int dy[4] = { 0,0,-1,1 };

int bfs(int sx, int sy)
{
	std::queue<std::pair<int, int>> q;
	q.emplace(sx, sy);
	map[sx][sy] = '0';
	int count = 1;

	while (q.empty() == false)
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int idx = 0; idx < 4; ++idx)
		{
			int nx = x + dx[idx];
			int ny = y + dy[idx];

			if (nx >= 0 && nx < n && ny >= 0 && ny < n && map[nx][ny] == '1')
			{
				map[nx][ny] = '0';
				q.emplace(nx, ny);
				count++;
			}
		}
	}
	return count;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	
	std::cin >> n;
	map.resize(n);
	for (int idx = 0; idx < n; ++idx)
	{
		std::cin >> map[idx];
	}
	
	std::vector<int> comp;

	for (int idx = 0; idx < n; ++idx)
	{
		for (int idx_2 = 0; idx_2 < n; ++idx_2)
		{
			if (map[idx][idx_2] == '1')
			{
				comp.emplace_back(bfs(idx, idx_2));
			}
		}
	}

	std::sort(comp.begin(), comp.end());

	std::cout<<comp.size() << '\n';
	for (int size : comp)
	{
		std::cout << size << '\n';
	}


	
}
