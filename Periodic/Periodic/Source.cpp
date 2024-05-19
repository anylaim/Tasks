#include <iostream>

using namespace std;

bool IsKPeriodic(const char* s, int K)
{
    if (K <= 0)
    {
        return false;
    }

    int n = 0;

    while (s[n] != '\0')
    {
        n++;
    }

    if (n % K != 0)
    {
        return false;
    }

    for (int i = 0; i < K; i++)
    {
        for (int j = i + K; j < n; j += K)
        {
            if (s[i] != s[j])
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    cout << IsKPeriodic("abcabcabcabc", 3) << endl;
    cout << IsKPeriodic("abcdabcd", 4) << endl;
    cout << IsKPeriodic("abcabcabcab", 3) << endl;

    return 0;
}