// https://www.acmicpc.net/problem/9465
#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;

    int n, j;
    for (int i = 0; i < T; i++)
    {
        cin >> n;
        int sticker[2][100001] = {};
        for (j = 0; j < n; j++)
            cin >> sticker[0][j];

        for (j = 0; j < n; j++)
            cin >> sticker[1][j];

        int dp[2][100001] = {};
        dp[0][0] = sticker[0][0];
        dp[1][0] = sticker[1][0];

        dp[0][1] = dp[1][0] + sticker[0][1];
        dp[1][1] = dp[0][0] + sticker[1][1];

        for (j = 2; j < n; j++)
        {
            dp[0][j] = max(dp[1][j - 1], dp[1][j - 2]) + sticker[0][j];
            dp[1][j] = max(dp[0][j - 1], dp[0][j - 2]) + sticker[1][j];
        }

        cout << max(dp[0][n - 1], dp[1][n - 1]) << endl;
    }
}
