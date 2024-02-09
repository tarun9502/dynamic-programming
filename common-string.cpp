#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>

std::string calculateCommonString(const std::string &s1, const std::string &s2) {
    int len1 = s1.size(), len2 = s2.size();
    std::vector<std::vector<int> > dp(len1+1, std::vector<int>(len2+1, 0));
    std::pair<int, int> maxPos(0, 0);

    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                if (dp[i][j] > dp[maxPos.first][maxPos.second]) {
                    maxPos.first = i;
                    maxPos.second = j;
                }
            }
        }
    }

    std::deque<char> dq;
    while (dp[maxPos.first][maxPos.second] != 0) {
        dq.push_front(s1[maxPos.first-1]);
        --maxPos.first;
        --maxPos.second;
    }

    return std::string(dq.begin(), dq.end());
}

int main() {
    std::string s1, s2;
    std::cout << "Input string 1: ";
    std::cin >> s1;
    std::cout << "Input string 2: ";
    std::cin >> s2;

    std::string lcs = calculateCommonString(s1, s2);
    std::cout << "Longest common substring: " << lcs << std::endl;
    return 0;
}
