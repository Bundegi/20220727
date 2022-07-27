#include <string>
#include <vector>
#include <cmath>

using namespace std;
//프로그래머스 삼각달팽이
vector<int> solution(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) sum += i;
    vector<int> answer(sum, 0);
    int count = 0;
    int loc = 0;
    int index = 0;
    int ct1 = 0;
    for (int i = 1; i <= sum; i++) {
        if (count == 0) {
            loc += index;
            answer[loc] = i;
            index++;
            ct1++;
            if (ct1 == n) {
                n--;
                count++;
                ct1 = 0;
                continue;
            }
        }
        else if (count == 1) {
            loc++;
            ct1++;
            answer[loc] = i;
            if (ct1 == n) {
                n--;
                count++;
                ct1 = 0;
                continue;
            }
        }
        else {
            loc -= index;
            index--;
            ct1++;
            answer[loc] = i;
            if (ct1 == n) {
                n--;
                count = 0;
                ct1 = 0;
                continue;
            }
        }
    }
    return answer;
}
int main() {
    solution(6);
}