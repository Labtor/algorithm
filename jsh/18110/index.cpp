#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> difficulties;
    for (int i = 0; i < n; i++)
    {
        int difficulty;
        cin >> difficulty;
        difficulties.push_back(difficulty);
    }

    sort(difficulties.begin(), difficulties.end());

    int fi = round(n * 0.15);

    int sum = 0;
    for (int i = fi; i < n - fi; i++)
    {
        sum += difficulties[i];
    }

    cout << (n < 1 ? 0 : round(sum / round(n - (fi * 2))));
}