#include <iostream>
#include "include/hanoi.h"

using namespace std;

int main() {
    int n;

    cout << "Digite o numero de discos (1 a 10): ";
    cin >> n;

    if (n < 1 || n > 10) {
        cout << "Valor invalido!" << endl;
        return 0;
    }

    executarHanoi(n);

    return 0;
}
