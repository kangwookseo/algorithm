#include <iostream>
#include <vector>
#include <deque>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, w, L; 
    std::cin >> n >> w >> L;

   std::vector<int> trucks(n);
    for (int idx = 0; idx < n; ++idx) 
    {
        std::cin >> trucks[idx];
    }

    std::deque<int> bridge(w, 0);

    int time = 0;
    int current_weight = 0; 
    int truck_idx = 0;      

    while (truck_idx < n || current_weight > 0) 
    {
        time++;

        int leaving = bridge.front();
        bridge.pop_front();
        current_weight -= leaving;

        if (truck_idx < n) 
        {
            if (current_weight + trucks[truck_idx] <= L) 
            {
                bridge.push_back(trucks[truck_idx]);
                current_weight += trucks[truck_idx];
                truck_idx++;
            }
            else 
            {
                bridge.push_back(0);
            }
        }
        else 
        {
            if (current_weight > 0) 
            { 
                bridge.push_back(0);
            }
        }
    }

    std::cout << time << '\n';

    return 0;
}
