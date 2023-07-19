// https://www.acmicpc.net/problem/11660

#include <iostream>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    int prefix_sum[1045][1045] = {};
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        prefix_sum[i][0] = x;
        for (int j = 1; j < N; j++)
        {
            cin >> x;
            prefix_sum[i][j] = x + prefix_sum[i][j - 1];
        }
    }

    for (int i = 0; i < M; i++)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        long long int sum = 0;
        for (int j = x1 - 1; j < x2; j++)
        {
            if (y1 < 2)
                sum += prefix_sum[j][y2 - 1];
            else
                sum += prefix_sum[j][y2 - 1] - prefix_sum[j][y1 - 2];
        }

        cout << sum << "\n";
    }

    return 0;
}
