#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> arr;
void printSubset()
{
    int power = pow(2, n) - 1;
    cout << "Total Subsets: " << power << endl; 
    for (int i = 0; i <= power; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                cout << arr[j] << ", ";
            }
        }
        cout << endl;
    }
}
int main()
{
    cin >> n;
    arr.assign(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    printSubset();
    return 0;
}