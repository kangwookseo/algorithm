#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL);

	int N, C;
	std::cin >> N>>C;

	std::vector<long long> cont(N);

	for (int idx = 0; idx < N; ++idx)
	{
		std::cin >> cont[idx];
	}

	std::sort(cont.begin(), cont.end());

	long long low = 1;
	long long high = cont[N - 1] - cont[0];
	long long ans = 0;

	while(low <= high)
	{
		long long mid = (low + high) / 2;

		int i_count = 1;
		long long l_loc = cont[0];

		for (int idx = 1; idx < N; ++idx)
		{
			if (cont[idx] - l_loc >= mid)
			{
				i_count++;
				l_loc = cont[idx];
			}
		}

		if (i_count >= C)
		{
			ans = mid;
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}

	std::cout << ans << '\n';

}