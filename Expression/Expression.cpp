#include <iostream>

using namespace std;

unsigned int X[25];
char sign[25];
int S, N;
void input()
{
    cin >> N >> S;
    if (N < 2 || N > 25)
        cout << "No solution";
    for (int i = 0; i < N; i++)
        cin >> X[i];
}
void output()
{
    cout << X[0];
    for (int i = 1; i < N; i++)
        cout << sign[i] << X[i];
    cout << "=" << S;
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
    cout << "No solution";
}
int main()
{
    input();
    solution();
    return 0;
}