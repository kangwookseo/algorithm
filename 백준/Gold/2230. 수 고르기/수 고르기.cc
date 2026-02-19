#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	
	long long N, M;
	std::cin >> N >> M;
	std::vector<long long> arr;
	arr.reserve(N);

	for (int idx = 0; idx < N; ++idx)
	{
		long long x;
		std::cin >> x;
		arr.emplace_back(x);
	}

	int left = 0, right = 0;
	long long min_div = 20000000001;

	std::sort(arr.begin(), arr.end());

	while(right < N)
	{
		long long div= arr[right] - arr[left];

		if (div >= M)
		{
			if (div < min_div)
			{
				min_div = div;
			}
			left++;

			if (left > right)
			{
				right = left;
			}
		}
		else 
		{
			right++;
		}
	}
		std::cout << min_div;

}