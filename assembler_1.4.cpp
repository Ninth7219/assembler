#include <iostream>
#include <cmath>

using namespace std;

int main(){

    setlocale(LC_ALL, "Rus");

    double A, B, C, D, X, Res;
    cout << "Данная программа вычисляет значение выражения A*X3 + B*X2 + C div X + (D div X) div X";
    cout << "Введите число A";
    cin >> A;
    cout << "Введите число B";
    cin >> B;
    cout << "Введите число C";
    cin >> C;
    cout << "Введите число D";
    cin >> D;
    cout << "Введите число X";
    cin >> X;

    Res = A*pow(X,3) + B*pow(X,2) + C/X + (D/X)/X;
    _asm{
        mov eax, A
        imul X
        imul X
        imul X
        mov A,eax
        mov eax, B
        imul X
        imul X
        add A, eax
        mov eax, C
        cdq
        idiv X
        add A, eax
        add eax, D
        cdq
        idiv X
        cdq
        idiv X
        add A, eax
    }
    cout << "Результат вычислений на языке ассемблера:" << A << endl;
    cout << "Результат вычислений на языке C/C++:" << Res << endl;
    return 0;
}
