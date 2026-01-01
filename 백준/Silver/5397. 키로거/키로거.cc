#include <iostream>
#include <stack>
#include <string>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int count;
	std::cin >> count;


	while (count-- > 0)
	{
		std::string input;
		std::cin >> input;
		
		std::stack<char> output;
		std::stack<char> imm;

		for (char c : input)
		{
			if (c == '<')
			{
				if (output.empty() == false)
				{
					imm.push(output.top());
					output.pop();
				}
			}
			else if (c == '-')
			{
				if (output.empty() == false)
				{
					output.pop();
				}
			}
			else if (c == '>')
			{
				if (imm.empty() == false)
				{
					output.push(imm.top());
					imm.pop();
				}
			}
			else
			{
				output.push(c);
			}
		}

		while (output.empty() == false)
		{
			imm.push(output.top());
			output.pop();
		}

		while (imm.empty() == false)
		{
			std::cout << imm.top();
			imm.pop();
		}
		std::cout << '\n';
	}
}