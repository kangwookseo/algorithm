#include <iostream>
#include <string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string L, R;
    std::cin >> L >> R;

    if ((L.size() == R.size()) == false) 
    {
        std::cout << 0;
        return 0;
    }

    int cnt = 0;

    for (size_t idx = 0; idx < L.size(); ++idx) 
    {
        if (L[idx] != R[idx])
        {
            break;
        }
        if (L[idx] == '8')
        {
            cnt++;
        }
    }
    std::cout << cnt;
    return 0;
}
