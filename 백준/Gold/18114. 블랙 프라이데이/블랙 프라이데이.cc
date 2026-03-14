#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int x, y;
	std::cin >> x >> y;

	std::vector<int> cont(x);

	for (int idx = 0; idx < x; ++idx)
	{
		std::cin >> cont[idx];
		if (cont[idx] == y)
		{
			std::cout << "1";
			return 0;
		}
	}
	std::sort(cont.begin(), cont.end());

	int l_idx = 0;
	int r_idx = x - 1;
	bool find = false;

	while (l_idx < r_idx)
	{
		int sum = cont[l_idx] + cont[r_idx];
		
		if (sum > y)
		{
			r_idx--;
		}
		else if (sum < y)
		{
			int target = y - sum;

			if ((target == cont[l_idx]) == false && (target == cont[r_idx]) == false)
			{
				if (std::binary_search(cont.begin(), cont.end(), target))
				{
					std::cout<<"1";
					return 0;
				}
			}
			l_idx++;
		}
		else
		{
			std::cout << "1";
			return 0;
		}
	}
	std::cout << "0";
}
