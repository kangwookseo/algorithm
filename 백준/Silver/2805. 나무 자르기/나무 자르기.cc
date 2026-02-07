#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	long long N, M;
	std::cin >> N >> M;

	std::vector<long long> trees(N);
	long long max_h = 0;

	for (int idx = 0; idx < N; ++idx)
	{
		std::cin >> trees[idx];
		if (trees[idx] > max_h)
		{
			max_h = trees[idx];
		}
	}

	long long low = 0;
	long long high = max_h;
	long long res = 0;

	while (low <= high)
	{
		long long mid = (low + high) / 2;
		long long sum = 0;

		for (int idx = 0; idx < N; ++idx)
		{
			if (trees[idx] > mid)
			{
				sum += (trees[idx] - mid);
			}
		}

		if (sum >= M)
		{
			res = mid;
			low = mid + 1;
		}
	
		else
		{
			high = mid - 1;
		}
	}
	
	std::cout << res;
}

