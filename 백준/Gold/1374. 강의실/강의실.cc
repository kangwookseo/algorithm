#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>


int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int N;
	std::cin >> N;

	std::vector<std::pair<int, int>> room(N);
	for (int idx = 0; idx < N; ++idx)
	{
		int x;
		std::cin >> x >> room[idx].first >> room[idx].second;
	}

	std::sort(room.begin(), room.end());
	
	std::priority_queue<int, std::vector<int>, std::greater<int>> fin;


	for (int idx = 0; idx < N; ++idx)
	{
		int start = room[idx].first;
		int end = room[idx].second;

		if (fin.empty() == false && fin.top() <= start)
		{
			fin.pop();
		}
		fin.emplace(end);
	}
	std::cout << fin.size();

}