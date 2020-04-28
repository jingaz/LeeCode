#include <iostream>
#include <vector>
using namespace std;
long long C(long long cnt) { return cnt * (cnt - 1) / 2; }
int main() {
    long long N, D;
    cin >> N >> D;
    vector<long long> pos(N);
    long long ans = 0;
    for (int i = 0, j = 0; i < N; i++) {
        cin >> pos[i];
        while (i >= 2 && pos[i] - pos[j] > D) {
            j++;
        }
        ans += C(i - j);
    }
    cout << ans % 99997867 << endl;
}
