#include <iostream>
#include <vector>
#include <queue>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N;
	std::cin >> N;
	
	std::vector<int> left(N);
	for (int idx = 0; idx<N; ++idx)
	{
		std::cin >> left[idx];
	}
	std::vector<int> ans(N, 0);

	for(int idx = 0; idx<N; ++idx)
	{
		int count = left[idx];
		for (int _idx = 0; _idx < N; ++_idx)
		{
			if (ans[_idx] == 0)
			{
				if (count > 0)
				{
					count--;
				}
				else
				{
					ans[_idx] = idx + 1;
					break;
				}
			}
		}
	}
	for (int idx = 0; idx < N; ++idx)
	{
		std::cout << ans[idx] << " ";
	}
}