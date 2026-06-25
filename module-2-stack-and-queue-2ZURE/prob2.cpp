#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int arr[100];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (k <= 0 || k > n) return 0;

    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += arr[i];
    }

    cout << sum;

    for (int i = k; i < n; i++) {
        sum = sum - arr[i - k] + arr[i];
        cout << " " << sum;
    }

    return 0;
}