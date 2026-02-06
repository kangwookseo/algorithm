#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int main()
{
	int n;
	std::cin >> n;
	std::vector<std::pair<int, int>> lec;
	std::priority_queue<int, std::vector<int>, std::greater<int>> stor;

	lec.reserve(n);
	
	for (int idx = 0; idx < n; ++idx)
	{
		int p, d; //p가 금액 d가 일수
		std::cin >>  p>>d;

		lec.emplace_back(d, p);
	}


	std::sort(lec.begin(), lec.end());

	for (int idx = 0; idx < n; ++idx)
	{
		stor.emplace(lec[idx].second);

		if (stor.size() > lec[idx].first)
		{
			stor.pop();
		}
	}

	int sum = 0;
	while(stor.empty() == false)
	{
		sum += stor.top();
		stor.pop();
	}
	std::cout << sum;

}