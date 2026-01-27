#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> meetings(N);
    for (int idx = 0; idx< N; ++idx) 
    {
        std::cin >> meetings[idx].first >> meetings[idx].second;
    }

    std::sort(meetings.begin(), meetings.end());

    std::priority_queue<int, std::vector<int>, std::greater<int>> ans;

    for (const auto& meeting : meetings) 
    {
        if (ans.empty() == false && ans.top() <= meeting.first) 
        {
            ans.pop();
        }
        ans.push(meeting.second);
    }

    std::cout << ans.size();

    return 0;
}
