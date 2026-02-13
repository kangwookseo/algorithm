#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N;
	std::cin >> N;

	std::vector<long long> good(N);

	for (int idx = 0; idx < N; ++idx)
	{
		std::cin >> good[idx];
	}

	std::sort(good.begin(), good.end());

	int count = 0;

	for (int idx = 0; idx < N; ++idx)
	{
		long long target = good[idx];
		int left = 0;
		int right = N-1;

		while (left < right)
		{
			long long sum = good[left] + good[right];

			if (sum == target)
			{
				if ((left == idx) == false && (right == idx) == false)
				{
					count++;
					break;
				}
				else if (left == idx)
				{
					left++;
				}
				else if (right == idx)
				{
					right--;
				}
			}
			else if (sum < target)
			{
				left++;
			}
			else
			{
				right--;
			}
			
		}
	}
	std::cout << count;
}