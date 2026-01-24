#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int N, K;
	std::cin >> N >> K;

	std::vector<int> comb(N);
	std::vector<int> dif;

	for (int idx = 0; idx < N; ++idx)
	{
		std::cin >> comb[idx];
		if (idx >= 1)
		{
			int value = 0;
			value = comb[idx] - comb[idx-1];
			dif.emplace_back(value);
		}
	}

	std::sort(dif.begin(), dif.end());
	
	long long ans = 0;

	for (int idx = 0; idx < N - K; ++idx)
	{
		ans += dif[idx];
	}
	std::cout << ans;
}