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
        for (int j = 0; j < N; j++)
        {
            int x;
            cin >> x;

            if (j == 0)
                prefix_sum[i][j] = x;
            else
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
            // 음수인덱스 접근이 있긴한데 상관없을 것 같아서 그냥 둠
            sum += prefix_sum[j][y2 - 1] - prefix_sum[j][y1 - 2];
        }

        cout << sum << "\n";
    }

    return 0;
}
