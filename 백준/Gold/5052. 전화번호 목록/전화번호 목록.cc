#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int t;
	std::cin >> t;

	for (int idx = 0; idx < t; ++idx)
	{
		int n;
		std::cin >> n;

		std::vector<std::string> cont;
		
		for (int idx = 0; idx < n; ++idx)
		{
			std::string num;
			std::cin >> num;
			cont.emplace_back(num);
		}

		std::sort(cont.begin(), cont.end());

		bool cons = true;

		for (int idx = 0; idx < n - 1; ++idx)
		{
			if (cont[idx].length() > cont[idx + 1].length())
			{
				continue;
			}
			if (cont[idx] == cont[idx + 1].substr(0, cont[idx].length()))
			{
				cons = false;
				break;
			}
		}

		if (cons)
		{
			std::cout << "YES\n";
		}
		else
		{
			std::cout << "NO\n";
		}
	}
}