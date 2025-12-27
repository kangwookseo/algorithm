#include <iostream>
#include <cmath>


int main() {
    int T;
    std::cin >> T;
    while (T--) {
        int x1, y1, r1, x2, y2, r2;
       std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        int dx = x2 - x1;
        int dy = y2 - y1;
        double d = sqrt(dx * dx + dy * dy); // 중심 사이 거리

        if (x1 == x2 && y1 == y2) {
            if (r1 == r2) 
            std::cout << "-1\n";
            else 
                std::cout << "0\n";
        }
        else {
            if (d > r1 + r2 || d < abs(r1 - r2)) 
                std::cout << "0\n";
            else if (d == r1 + r2 || d == abs(r1 - r2)) 
                std:: cout << "1\n";
            else 
                std::cout << "2\n";
        }
    }
    return 0;
}
