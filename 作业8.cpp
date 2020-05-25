#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <cstring>
using namespace std;
const int MAXN = 25;
const int inf = 0x3f3f3f3f;
int s[MAXN][MAXN];
void find_div(int l, int r) 
{
    if (!s[l][r])
        return;
    else
        printf("%d\t", s[l][r]);
    find_div(l, s[l][r]);
    find_div(s[l][r] + 1, r);
}
void min_multi_martix(int P[], int n)
{
    int dp[MAXN][MAXN];
    memset(dp, inf, sizeof(dp));
    if (n >= 2) 
        for (int i = 1; i <= n - 1; i++)
        {
            dp[i][i + 1] = P[i] * P[i + 1] * P[i + 2];
            dp[i][i] = 0;
        }

    for (int len = 3; len <= n; len++)
        for (int i = 1; i <= n - len + 1; i++)
        {
            int j = i + len - 1;
            for (int k = i; k < j; k++)
                if (dp[i][j] > dp[i][k] + dp[k + 1][j] + P[i] * P[k + 1] * P[j + 1])
                {
                    dp[i][j] = dp[i][k] + dp[k + 1][j] + P[i] * P[k + 1] * P[j + 1];
                    s[i][j] = k;
                }
        }
    printf("æÿ’Û¡¥◊Ó…Ÿ≥À∑®¥Œ ˝∞=%d\n", dp[1][n]);
    printf("∑÷∏Óµ„");
    find_div(1, n);
}
int main()
{
    int P[] = { 0,3,5,4,8,2 };
    min_multi_martix(P, 4);
    return 0;
}
