#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);


	int T;
	std::cin >> T;
	
	while (T-- > 0)
	{
		std::priority_queue<long long, std::vector<long long>, std::greater<long long>> arr;

		int K;
		std::cin >> K;
		for (int idx = 0; idx < K; ++idx)
		{
			int x;
			std::cin >> x;
			arr.emplace(x);
		}

		long long total = 0;

		while (arr.size() > 1)
		{
			long long x = arr.top();
			arr.pop();
			long long y = arr.top();
			arr.pop();

			long long value = x + y;

			total += value;

			arr.emplace(value);
		}
		std::cout << total<<'\n';
	}
}
