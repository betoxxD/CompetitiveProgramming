#include <iostream>

using namespace std;

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    int max_segments = 0;

    for (int x = 0; x <= n/a; x++) {
        for (int y = 0; y <= n/b; y++) {
            int z = (n - a*x - b*y) / c;

            // Verificar si x, y, z son números enteros no negativos
            if (z >= 0 && a*x + b*y + c*z == n) {
                int segments = x + y + z;
                max_segments = max(max_segments, segments);
            }
        }
    }

    cout << max_segments << endl;

    return 0;
}
