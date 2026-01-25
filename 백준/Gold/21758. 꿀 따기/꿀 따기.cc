#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int N;
	std::cin >> N;

	std::vector<int> bee_h(N);
	std::vector<long long> sum(N);


	for (int idx = 0; idx < N; ++idx)
	{
		std::cin >> bee_h[idx];
		if (idx == 0)
		{
			sum[idx] = bee_h[idx];
		}
		else
		{
			sum[idx] = sum[idx - 1] + bee_h[idx];
		}
	}
	
	long long total_sum = sum[N-1];
	long long ans = 0;

	
	for (int idx = 1; idx <= N - 2; ++idx)
	{
		long long bee1 = total_sum - bee_h[0] - bee_h[idx];
		long long bee2 = total_sum - sum[idx];

		ans = std::max(ans, bee1 + bee2);
	}
	
	for (int idx = 1; idx <= N - 2; ++idx)
	{
		long long bee1 = total_sum - bee_h[N - 1] - bee_h[idx];
		long long bee2 = sum[idx - 1];
		
		ans = std::max(ans, bee1 + bee2);
	}

	for (int idx = 1; idx<= N - 2; ++idx)
	{
		long long current = (total_sum - bee_h[0] - bee_h[N - 1]) + bee_h[idx];
		ans = std::max(ans, current);
	}

	std::cout << ans << '\n';
}