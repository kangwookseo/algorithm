#include <iostream>
#include <string>
#include <vector>

int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s;
    std::cin >> s;

    int n = 0;     
    int ptr = 0;   

    while (ptr < s.length()) 
    {
        n++; 
        std::string num_str = std::to_string(n); 

        for (char c : num_str) 
        {
            if (ptr >= s.length())
                break; 
            if (c == s[ptr]) 
            {
                ptr++;
            }
        }
    }

    std::cout << n;
}