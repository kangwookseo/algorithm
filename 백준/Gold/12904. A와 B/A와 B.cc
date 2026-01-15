#include <iostream>
#include <string>
#include <algorithm> 


int main() 
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string S, T;
    std::cin >> S >> T;

    while (T.length() > S.length()) 
    {
        char lastChar = T.back();
        T.pop_back();

        if (lastChar == 'B') 
        {           
            reverse(T.begin(), T.end());
        }
    }

    if (T == S) 
    {
        std::cout << 1 << '\n';
    } 
    else 
    {
        std::cout << 0 << '\n';
    }

    return 0;
}
