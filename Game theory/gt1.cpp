
#include <iostream>

using namespace std;

int findMaxBucks(int pile[], int n, int start, int end)
{
    int matrix[n][n];
    matrix[0][1] = max(pile[0], pile[1]);
    for (int i = 0; i < n; i++)
    {
        matrix[i][i] = pile[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        matrix[i][i + 1] = max(pile[i], pile[i + 1]);
    }
    for (int k = 3; k <= end + 1; k++)
    {
        for (int i = 0; i < end; i++)
        {
            int j = i + k - 1;

            matrix[i][j] = max(pile[i] + min(matrix[i + 1][j - 1], matrix[i + 2][j]),
                               pile[j] + min(matrix[i][j - 2], matrix[i + 1][j - 1]));
        }
    }

    return matrix[0][end];
}
int main()
{
    int pile[] = {8, 15, 3, 7};
    int size = sizeof(pile) / sizeof(int);
    cout << findMaxBucks(pile, size, 0, size - 1) << endl;
    cin >> size;
}