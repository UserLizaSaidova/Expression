#include <iostream>
#include <fstream>

using namespace std;

unsigned int X[25];
char sign[25];
int S, N;
void input()
{
    ifstream fromfile("..\\TestExpression\\input.txt");
    fromfile >> N >> S;
    for (int i = 0; i < N; i++)
        fromfile >> X[i];
    fromfile.close();
}
void output()
{
    ofstream tofile("..\\Expression\\output.txt", ios::trunc);
    tofile << X[0];
    for (int i = 1; i < N; i++)
        tofile << sign[i] << X[i];
    tofile << "=" << S;
    tofile.close();
    exit(0);
}

void rec(int Sum, int Index)
{
    if (Sum == S) // ответ найден
        output();
    if (Index == N) // терминальное условие
        return;

    sign[Index] = '+';
    rec(Sum + X[Index], Index + 1);

    sign[Index] = '-';
    rec(Sum - X[Index], Index + 1);
}
void solution()
{
    rec(X[0], 1);
    ofstream tofile("..\\Expression\\output.txt", ios::trunc);
    tofile << "No solution";
    tofile.close();
}
int main()
{
    input();
    solution();
    return 0;
}
