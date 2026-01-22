#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	long long N;
	std::cin >> N;
	
	std::vector<int> dice(6);

	for (int idx = 0; idx < 6; ++idx)
	{
		std::cin >> dice[idx];
	}
	
	if (N == 1)
	{
		sort(dice.begin(), dice.end());

		long long sum = 0;

		for (int idx = 0; idx < 5; ++idx)
		{
			sum += dice[idx];
			
		}
		std::cout << sum << '\n';
		return 0;
	}

	long long min_side[3];
	min_side[0] = std::min(dice[0], dice[5]);
	min_side[1] = std::min(dice[1], dice[4]);
	min_side[2] = std::min(dice[2], dice[3]);

	std::sort(min_side, min_side + 3);

	long long min1 = min_side[0];
	long long min2 = min_side[0] + min_side[1];
	long long min3 = min_side[0] + min_side[1] + min_side[2];

	long long n3 = 4;
	long long n2 = 4 * (N - 1) + 4 * (N - 2);
	long long n1 = (N - 2) * (N - 2) + 4 * (N - 1) * (N - 2);

	long long ans = (n1 * min1) + (n2 * min2) + (n3 * min3);

	std::cout << ans << '\n';
}