#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N;
	std::cin >> N;

	std::vector<std::pair<int, int>> meetings(N);

	for(int idx = 0; idx<N; ++idx)
	{
		std::cin >> meetings[idx].second >> meetings[idx].first;
	}

	std::sort(meetings.begin(), meetings.end());

	int count = 0;
	int end = 0;

	for (int idx = 0; idx < N; ++idx)
	{
		if (meetings[idx].second >= end)
		{
			end = meetings[idx].first;
			++count;
		}
	}

	std::cout << count <<'\n';

}