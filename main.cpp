#include <iostream>
#include <cmath>
#include <limits>
#include <iomanip>
using namespace std;

double piecewise(double x) {
    if (x <= 0) {
        // y = cos³(x²) - sin²(x²)
        return pow(cos(x * x), 3) - pow(sin(x * x), 2);
    } else if (x > 0 && x <= 1) {
        // y = x² - 0.75
        return x * x - 0.75;
    } else if (x > 1 && x < 3.2) {
        // y = (1.4 + x) / ln(x)
        return (1.4 + x) / log(x);
    } else {
        cout << "Function not defined for x >= 3.2\n";
        return NAN;
    }
}

int main() {
    cout << fixed << setprecision(6);

    while (true) {
        cout << "Enter x: ";
        double x;
        if (!(cin >> x)) {
            cout << "Invalid input\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        double y = piecewise(x);

        if (!isnan(y)) {
            cout << "y = " << y << "\n";
        }

        cout << "Again? (y/n): ";
        char c;
        cin >> c;
        if (c != 'y' && c != 'Y') break;
    }

    return 0;
}
