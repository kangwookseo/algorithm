#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N;
	std::cin >> N;

	std::vector<long long> word(26, 0);
	for (int idx = 0; idx < N; ++idx)
	{
		std::string s;
		std::cin >> s;

		long long p = 1;
		for (int idx_1 = s.size() - 1; idx_1 >= 0; --idx_1)
		{
			word[s[idx_1] - 'A'] += p;
			p *= 10;
		}
	}

	sort(word.begin(), word.end(), std::greater<long long>());

	long long ans = 0;
	int digit = 9;
	for (int idx = 0; idx < 26 && digit >= 0; ++idx)
	{
		if (word[idx] == 0)
			break;
		ans += word[idx] * digit;
		digit--;
	}
	std::cout << ans << '\n';

}