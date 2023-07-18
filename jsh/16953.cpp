// https://www.acmicpc.net/problem/16953
#include <iostream>
#include <queue>

using namespace std;

#define ll long long

int main()
{
    ll A, B;
    queue<pair<ll, ll>> q;
    cin >> A >> B;

    q.push({A, 0});

    while (!q.empty())
    {
        pair<ll, ll> cur = q.front();
        if (cur.first == B)
        {
            cout << cur.second + 1;
            break;
        }
        int visited = cur.second + 1;

        q.pop();

        ll case1 = cur.first * 10 + 1;
        if (case1 <= B)
        {
            q.push({case1,
                    visited});
        }

        ll case2 = cur.first * 2;
        if (case2 <= B)
        {
            q.push({case2, visited});
        }
    }

    if (q.empty())
        cout << -1;

    return 0;
}