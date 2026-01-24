#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int N, K;
	std::cin >> N >> K;

	std::vector<int> dif;
	dif.reserve(N - 1);

	int preValue;
	std::cin >> preValue;

	for (int idx = 1; idx < N; ++idx)
	{
		int curValue;
		std::cin >> curValue;

		dif.emplace_back(curValue - preValue);
		preValue = curValue;
	}

	std::sort(dif.begin(), dif.end());

	long long ans = 0;

	for (int idx = 0; idx < N - K; ++idx)
	{
		ans += dif[idx];
	}
	std::cout << ans;
}