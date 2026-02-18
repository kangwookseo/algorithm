#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	
	int N;
	std::cin >> N;
	std::vector<std::pair<long long, long long>> line(N);

	for (int idx = 0; idx < N; ++idx)
	{
		std::cin >> line[idx].first >> line[idx].second;
	}
	
	std::sort(line.begin(), line.end());
	
	long long cur_start = line[0].first;
	long long cur_end = line[0].second;
	long long length = 0;

	for (int idx = 1; idx < line.size(); ++idx)
	{
		
		if (line[idx].first <= cur_end)
		{
			if (line[idx].second > cur_end)
			{
				cur_end = line[idx].second;
			}
		}
		else
		{
			length += (cur_end - cur_start);

			cur_start = line[idx].first;
			cur_end = line[idx].second;
		}
	}

	length += (cur_end - cur_start);
	std::cout << length;
}