#ifndef HANOI_H
#define HANOI_H

#include <stack>

using namespace std;

void mostrarEstado(stack<int> A, stack<int> B, stack<int> C);

void moverDisco(stack<int>& origem, stack<int>& destino,
                char o, char d,
                stack<int>& A, stack<int>& B, stack<int>& C);

void hanoi(int n,
           stack<int>& origem,
           stack<int>& auxiliar,
           stack<int>& destino,
           char o, char a, char d,
           stack<int>& A, stack<int>& B, stack<int>& C);

void executarHanoi(int n);

#endif
