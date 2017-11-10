#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;

bool read_numbers(int *a, unsigned int n) {
    string string;
    int k;
    getline(cin, string);
    istringstream stream(string);
    for (int i = 0; i < n; ++i) {
        if (!(stream >> a[i])) {
            return false;
            break;
        }
    }
    if (stream >> n){
        return false;
        exit(0);
    }
        return true;
}

void revers(int *a, unsigned int n){
    for (unsigned int i = 0; i < n/2; i++){
        swap(a[i], a[n-i-1]);
    }
}


int main() {
    int *a;
    int n;
    cin >> n;
    if (n >= 0) {
        cin.get();
        a = new int[n];
        if (read_numbers(a, n)) {
            revers(a, n);
            for (int i = 0; i < n; i++) {
                cout << a[i] << " ";
            }
        } else {
            cout << "An error has occured while reading input data";
        }
    }
    else {
        cout << "An error has occured while reading input data";
    }
    cin.get();
    return 0;
}
