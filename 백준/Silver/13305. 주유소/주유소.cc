#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;

    std::vector<long long> dist(N - 1);
    std::vector<long long> price(N);

    for (int i = 0; i < N - 1; i++) {
        std::cin >> dist[i];
    }

    for (int i = 0; i < N; i++) {
        std::cin >> price[i];
    }

    long long total_cost = 0;
    long long min_price = price[0]; 

    for (int i = 0; i < N - 1; i++) {
        if (price[i] < min_price) {
            min_price = price[i];
        }

        total_cost += min_price * dist[i];
    }

    std::cout << total_cost << "\n";

    return 0;
}
