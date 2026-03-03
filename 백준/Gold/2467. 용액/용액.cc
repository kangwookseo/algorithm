#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL);

	int N;
	std::cin >> N;

	std::vector<long long> cont(N);
	
	for (int idx = 0; idx < N; ++idx)
	{
		std::cin >> cont[idx];
	}

	std::sort(cont.begin(), cont.end());

	int left = 0;
	int right = N-1;
	long long diff = 20000000000;

	int ans_left = 0;
	int ans_right = 0;

	while (left < right)
	{
		long long sum = cont[right] + cont[left];

		if (abs(sum) < diff)
		{
			diff = abs(sum);
			ans_left = cont[left];
			ans_right = cont[right];
		}

		if (sum == 0)
		{
			break;
		}
		else if (sum < 0)
		{
			left++;
		}
		else
		{
			right--;
		}
	}
	std::cout << ans_left << " " << ans_right << '\n';
}