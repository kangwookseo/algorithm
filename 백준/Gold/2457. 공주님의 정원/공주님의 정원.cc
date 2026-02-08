#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> flower;

    for (int idx = 0; idx< N; ++idx) 
    {
        int sm, sd, em, ed;
        std::cin >> sm >> sd >> em >> ed;

        int start_date = sm * 100 + sd;
        int end_date = em * 100 + ed;

        flower.emplace_back(start_date, end_date);
    }

    std::sort(flower.begin(), flower.end());

    int current_t = 301; 
    int count = 0;
    int idx = 0;

    while (current_t <= 1130) 
    {
        int max_end = 0; 
        bool found = false;

        while (idx < N && flower[idx].first <= current_t) 
        {
            max_end = std::max(max_end, flower[idx].second);
            idx++;
            found = true;
        }

        if (found == false || max_end <= current_t) 
        {
            std::cout << 0;
            return 0;
        }

        count++;
        current_t = max_end;
    }

    std::cout << count;

    return 0;
}
