#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int t;
	std::cin >> t;

	while (t-- > 0)
	{
		int n,k;
		std::cin >>n>>k;

		std::vector<int> cont(n);
		
		for (int idx = 0; idx < n; ++idx)
		{
			std::cin >> cont[idx];
		}
		std::sort(cont.begin(), cont.end());

		int l_p = 0;
		int r_p = n - 1;

		int min_diff = 200000011;
		int count = 0;

		while(l_p <r_p)
		{
			int sum = cont[l_p] + cont[r_p];
			int diff = std::abs(sum - k);

			if (diff<min_diff)
			{
				min_diff = diff;
				count = 1;
			}
			else if (min_diff == diff)
			{
				count++;
			}

			if (sum < k)
			{
				l_p++;
			}
			else
			{
				r_p--;
			}
		}
		std::cout << count << '\n';
	}
}
