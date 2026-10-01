#include "../include/hanoi.h"
#include <iostream>

using namespace std;

int movimentos = 0;

void mostrarEstado(stack<int> A, stack<int> B, stack<int> C) {
    cout << "A: [";
    while (!A.empty()) {
        cout << A.top();
        A.pop();
        if (!A.empty()) cout << ", ";
    }
    cout << "] ";

    cout << "B: [";
    while (!B.empty()) {
        cout << B.top();
        B.pop();
        if (!B.empty()) cout << ", ";
    }
    cout << "] ";

    cout << "C: [";
    while (!C.empty()) {
        cout << C.top();
        C.pop();
        if (!C.empty()) cout << ", ";
    }
    cout << "]" << endl;
}

void moverDisco(stack<int>& origem, stack<int>& destino,
                char o, char d,
                stack<int>& A, stack<int>& B, stack<int>& C) {

    int disco = origem.top();
    origem.pop();
    destino.push(disco);

    movimentos++;

    cout << "Mover disco " << disco << " de " << o << " para " << d << endl;
    mostrarEstado(A, B, C);
}

void hanoi(int n,
           stack<int>& origem,
           stack<int>& auxiliar,
           stack<int>& destino,
           char o, char a, char d,
           stack<int>& A, stack<int>& B, stack<int>& C) {

    if (n == 1) {
        moverDisco(origem, destino, o, d, A, B, C);
        return;
    }

    hanoi(n - 1, origem, destino, auxiliar, o, d, a, A, B, C);
    moverDisco(origem, destino, o, d, A, B, C);
    hanoi(n - 1, auxiliar, origem, destino, a, o, d, A, B, C);
}

void executarHanoi(int n) {
    stack<int> A, B, C;

    for (int i = n; i >= 1; i--) {
        A.push(i);
    }

    cout << "Estado inicial:" << endl;
    mostrarEstado(A, B, C);
    cout << endl;

    hanoi(n, A, B, C, 'A', 'B', 'C', A, B, C);

    cout << endl << "Total de movimentos: " << movimentos << endl;
}
