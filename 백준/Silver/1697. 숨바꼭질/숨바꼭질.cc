#include <iostream>
#include <queue>
#include <algorithm>

int N, K;
int visited[100001];

int bfs(int start, int target)
{
	std::queue<int> stor;
	stor.emplace(start);

	visited[start] = 1;

	while (stor.empty() == false)
	{
		int cur = stor.front();
		stor.pop();

		if (cur == target)
		{
			return visited[cur] - 1;
		}

		int next_pos[3] = { cur - 1, cur + 1, cur * 2 };

		for (int idx = 0; idx < 3; ++idx)
		{
			int next = next_pos[idx];
			
			if (next >= 0 && next <= 100000 && visited[next] == 0)
			{
				visited[next] = visited[cur] + 1;
				stor.emplace(next);
			}
		}
	}
	return 0;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> N>> K;

	std::cout << bfs(N, K);
}