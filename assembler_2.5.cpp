#include <iostream>

using namespace std;

int main(){

    setlocale(LC_ALL, "Rus");
    int A[3], B[3], C[3], X, Y, D = 0;
    cout << "Данная программа вычисляет значение выражения: Summ(|Ai|*|Bi|)*X - Summ(|Ci|)*Y" << endl;
    for(int i = 0; i < 3; i++){
        cout << "Введите значение элемента A["<< i+1 <<"]:";
        cin  >> A[i];
    }
    cout << endl;
    for(int i = 0; i < 3; i++){
        cout << "Введите значение элемента B["<< i+1 <<"]:";
        cin  >> B[i];
    }
    cout << endl;
    for(int i = 0; i < 3; i++){
        cout << "Введите значение элемента C["<< i+1 <<"]:";
        cin  >> C[i];
    }
    cout << endl;
    cout << "Введите число Х:";
    cin  >> X;
    cout << "Введите число Y:";
    cin  >> Y;

    int res = ((abs(A[0])+abs(A[1])+abs(A[2]))*(abs(B[0])+abs(B[1])+abs(B[2])))*X-(abs(C[0])+abs(C[1])+abs(C[2]))*Y;
    __asb{
        mov eax, 0
        mov esi, 0
        mov ecx, 6
        lea ebx, A
        lea ebx, B
        cycl1:
            mov esi, [ebx]
            cmp esi, 0
            jge m1
            neg esi
        cycl2:
            mov esi, [edx]
            cmp esi, 0
            jge m2
            neg esi
        m1:
            mov eax, esi
            add ebx, 4
            loop cyc12
        m2:
            imul esi
            add edx, 4
            add D, eax
            loop cyc11
        mov eax, D
        imul X
        mov X, eax
        mov eax, 0
        mov esi, 0
        mov ecx, 3
        lea ebx, C
        cycl3:
            mov esi, [edx]
            cmp esi, 0
            jge m3
            neg esi
        m3:
            add eax, esi
            add ebx, 4
            loop cyc13
        imul Y
        sub x, eax
    }
    cout << "Результат вычислений на языке C/C++:" << res << endl;
    cout << "Результат вычислений на языке ассемблера:" << X << endl;
    return 0;
}
