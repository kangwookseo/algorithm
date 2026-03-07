#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL);

	long long M, N;
	std::cin >> N >> M;

	std::vector<long long> v(N);
	long long max = 0;

	for (int idx = 0; idx < N; ++idx)
	{
		std::cin >> v[idx];
		if (v[idx] > max)
		{
			max = v[idx];
		}
	}

	long long left = 1;
	long long right = max * M;
	long long answer = right;

	while (left <= right) 
	{
		long long mid = (left + right) / 2;
		long long total_people = 0;

		for (int idx = 0; idx < N; ++idx)
		{
			total_people += mid / v[idx];

			if (total_people >= M)
			{
				break;
			}
		}

		if (total_people >= M)
		{
			answer = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	std::cout << answer << '\n';
}