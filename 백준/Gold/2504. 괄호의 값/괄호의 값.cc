#include <iostream>
#include <string>
#include <stack>

int main()
{
	std::string input_string;
	std::stack<char> store;
	int tmp = 1;
	int ans = 0;
	
	// Push only opening brackets onto the stack.

	std::cin >> input_string;

	for (int idx = 0; idx<input_string.length(); ++idx)
	{
		char c = input_string[idx];

		if (c=='(')
		{
			store.push(c);
			tmp *= 2;
		}
		else if (c == '[')
		{
			store.push('[');
			tmp *= 3;
		}
		else if (c == ')')
		{
			if (store.empty() == true || (store.top() =='(') == false)
			{
				std::cout << 0;
				return 0;
			}

			// ans += tmp runs only if input_string[i-1] == '('.
			else if(input_string[idx-1] == '(')
			{
				ans += tmp;
			}
			store.pop();
			tmp /= 2;
		}
		else
		{
			if (store.empty() == true || (store.top() == '[') == false)
			{
				std::cout << 0;
				return 0;
			}

			// ans += tmp runs only if input_string[i-1] == '['.
			else if (input_string[idx-1] == '[')
			{
				ans += tmp;
			}
			store.pop();
			tmp /= 3;
		}

	}
	if (store.empty())
	{
		std::cout << ans;
	}
	else
	{
		std::cout << 0;
	}
}