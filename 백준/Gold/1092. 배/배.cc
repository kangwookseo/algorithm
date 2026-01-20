#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int N;
	std::cin >> N;						
	std::vector<int> crane(N);

	for (int idx = 0; idx < N; ++idx)
	{
		std::cin >> crane[idx];
	}

	int M;
	std::cin >> M;
	std::multiset<int> box;

	for (int idx = 0; idx < M; ++idx)
	{
		int w;
		std::cin >> w;
		box.insert(w);
	}

	sort(crane.begin(), crane.end(), std::greater<int>());

	if (box.empty() == false && *box.rbegin() > crane[0])
	{
		std::cout << -1;
		return 0;
	}
	
	int min = 0;

	while (box.empty() == false)
	{
		for (int c : crane)
		{
			auto it = box.upper_bound(c);
			if (it == box.begin())
			{
				continue;
			}
			--it;
			box.erase(it);

			if (box.empty())
			{
				break;
			}
		}
		++min;
		
	}
	std::cout << min;


}