	#include <iostream>
	#include <vector>
	#include <set>
	#include <algorithm>

	int main()
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
	
		int N, K;
		std::cin >> N;
		std::cin >> K;

		std::vector<int> loc(N);
		for (int idx = 0; idx < N; ++idx)
		{
			std::cin >> loc[idx];
		}
		sort(loc.begin(), loc.end());

		
		std::vector<int> dis(N-1);
		for (int idx = 0; idx < N - 1; ++idx)
		{
			dis[idx] = loc[idx + 1] - loc[idx];
		}

		sort(dis.begin(), dis.end(), std::greater<int>());

		long long sum = 0;
		for (int idx = K - 1; idx < dis.size(); ++idx)
		{
			sum += dis[idx];
		}
		std::cout << sum << '\n';

	}