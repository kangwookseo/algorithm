#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int N;
	long long L;
	std::cin >> N >> L;

	std::vector<std::pair<int, int>> loc(N);
	
	for (int idx = 0; idx < N; ++idx)
	{
		std::cin >> loc[idx].first >> loc[idx].second;
	}
	
	std::sort(loc.begin(), loc.end());

	long long ans = 0;
	long long cur= 0;

	for (int idx = 0; idx < N; ++idx)
	{
		int x = loc[idx].first;
		int y = loc[idx].second;

		if (cur >= y)
		{
			continue;
		}
		if (cur < x)
		{
			cur = x;
		}

		long long dis = y - cur;

		long long count = (dis + L - 1) / L;

		ans += count;

		cur += count * L;
	}
	std::cout << ans	;


}