#include <iostream>
#include <string>

int main()
{
	std::string input;
	std::cin >> input;

	int result = 0;
	std::string num = "";
	bool isMin = false;

	for (int idx = 0; idx<=input.size() ; ++idx)
	{
		if (idx == input.size() || input[idx] == '+' || input[idx] == '-')
		{
			if (isMin == true)
			{
				result -= std::stoi(num);
			}
			else
			{
				result += std::stoi(num);
			}

			if (idx < input.size() && input[idx] == '-')
			{
				isMin = true;
			}

			num = "";
		}
		else
		{
			num += input[idx];
		}
	}
	std::cout << result;

}