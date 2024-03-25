#include <iostream>
#include <vector>

using namespace std;

vector<int> z_function(string const& s) {
    int n = (int) s.length();
    vector<int> z(n);
    int l = 0;
    for (int i = 1; i < n; i++) {
        z[i] = max(0, min(z[i - l], z[l] + l - i));
        while (i + z[i] < n && s[z[i]] == s[z[i] + i]) {
            z[i]++;
        }
        if (i + z[i] > l + z[l]) {
            l = i;
        }
    }
    z[0] = n;
    return z;
}

template <typename T>
void print_vector(vector<T> const& v) {
    for (T const& x: v) {
        cout << x << " ";
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;
    print_vector(z_function(s));
}
