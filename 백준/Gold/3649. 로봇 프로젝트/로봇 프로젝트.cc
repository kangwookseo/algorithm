#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int x;

	while (std::cin >> x)
	{
		int n;
		std::cin >> n;

		std::vector<int> length(n);

		for (int idx = 0; idx < n; ++idx)
		{
			std::cin >> length[idx];
		}
		std::sort(length.begin(), length.end());

		int l_idx = 0;
		int r_idx = n - 1;
		bool found = false;

		int target = x * 10000000;

		while (l_idx < r_idx)
		{
			int sum = length[l_idx] + length[r_idx];

			if (sum == target)
			{
				std::cout << "yes " << length[l_idx] << " " << length[r_idx] << '\n';
				found = true;
				break;
			}
			else if (sum > target)
			{
				r_idx--;
			}
			else
			{
				l_idx++;
			}
		}

		if (found == false)
		{
			std::cout << "danger" << '\n';
		}
	}
}
