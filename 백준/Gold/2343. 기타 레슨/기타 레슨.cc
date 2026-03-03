#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL);

	int N, M;
	std::cin >> N >> M;
	
	std::vector<int> cont(N);
	long long left = 0;
	long long right = 0;

	for (int idx = 0; idx < N; ++idx)
	{
		std::cin >> cont[idx];

		if (cont[idx] > left)
		{
			left = cont[idx];
		}
		right += cont[idx];
	}
	
	long long ans = right;

	while (left <= right)
	{
		long long mid = (left + right) / 2;
		long long sum = 0;
		int cnt = 1;

		for (int idx= 0; idx < N; ++idx)
		{
			if (sum + cont[idx] > mid)
			{
				cnt++;
				sum = cont[idx];
			}
			else
			{
				sum += cont[idx];
			}
		}

		if (cnt > M)
		{
			left = mid + 1;
		}
		else
		{
			ans = mid;
			right = mid - 1;
		}
	}

	std::cout << ans << '\n';
}