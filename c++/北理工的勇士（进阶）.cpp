#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Warrior {
    int x;
    int y;
};

// 按y坐标升序排序
bool compareY(const Warrior &a, const Warrior &b) {
    return a.y < b.y;
}

int main() {
    int N;
    cin >> N;

    vector<Warrior> warriors(N);
    for (int i = 0; i < N; i++) {
        cin >> warriors[i].x >> warriors[i].y;
    }

    sort(warriors.begin(), warriors.end(), compareY);

    long long totalMoves = 0;
    for (int i = 0; i < N; i++) {
        totalMoves += abs(warriors[i].y - i); // 通过将y坐标调整为i来保证移动次数最少
    }

    cout << totalMoves << endl;

    return 0;
}