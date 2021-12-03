#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
int n;
int getmax()
{
    int maxe = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxe = max(arr[i], maxe);
    }
    return maxe;
}
void countSort(int e)
{
    vector<int> output(n);
    vector<int> count(10, 0);
    for (int i = 0; i < n; i++)
    {
        count[(arr[i] / e) % 10] += 1;
    }
    for (int i = 1; i < 10; i++)
    {
        count[i] = count[i] + count[i - 1];
    }
    for (int i = n-1; i >= 0; i--)
    {
        output[count[(arr[i] / e) % 10] - 1] = arr[i];
        count[(arr[i]/ e)%10]--;
    }
    arr.assign(output.begin(), output.end());
}
void radixSort()
{
    int m = getmax();
    for (int i = 1; m / i > 0; i = i * 10)
    {
        countSort(i);
    }
}
int main()
{

    cin >> n;
    arr = vector<int>(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    radixSort();
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}