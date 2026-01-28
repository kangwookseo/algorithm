#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, M;
	std::cin >> N >> M;

	std::vector<int> loc_p;
	std::vector<int> loc_m;

	for (int idx = 0; idx < N; ++idx)
	{
		int x;
		std::cin >> x;
		if (x > 0)
		{
			loc_p.emplace_back(x);
		}
		else
		{
			loc_m.emplace_back(abs(x));
		}
	}

	std::sort(loc_p.begin(), loc_p.end());
	std::sort(loc_m.begin(), loc_m.end());
	

	int ans = 0;

	for (int idx = loc_p.size()-1; idx >= 0; idx-= M)
	{
		ans += loc_p[idx] * 2;
	}
	for (int idx = loc_m.size()-1; idx >= 0; idx -= M)
	{
		ans += loc_m[idx] * 2;
	}

	int max_p = 0;
	int max_m = 0;
    if(loc_p.empty()== false)
    {
        max_p = loc_p.back();
    }
	if(loc_m.empty() == false)
    {
        max_m = loc_m.back();
    }

	ans -= std::max(max_p, max_m);
	
	std::cout << ans;
	

}