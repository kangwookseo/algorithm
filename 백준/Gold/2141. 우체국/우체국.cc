#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	long long N;
	std::cin >> N;
	
	std::vector<std::pair<long long, long long>> vil(N);

	long long total = 0;

	for (int idx = 0; idx < N; ++idx)
	{
		std::cin >> vil[idx].first >> vil[idx].second;
		total += vil[idx].second;
	}
	
	std::sort(vil.begin(), vil.end());

	long long sum = 0;
	for (int idx = 0; idx < N; ++idx)
	{
		sum += vil[idx].second;
		
		if (sum * 2 >= total)
		{
			std::cout << vil[idx].first;
			return 0;
		}
	}
}


