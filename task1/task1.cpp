// task1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <vector>
#include <iostream>
using namespace std;

void input(double** matrix, int n, int m)
{
    cout << "Введите матрицу [" << n << " x " << m << "]: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
}

void task(double** matrix, int n, int m, vector<bool>& vect)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            if ((matrix[i][j] < 0 && matrix[i][j + 1] < 0) ||
                (matrix[i][j] > 0 && matrix[i][j + 1] > 0))
            {
                vect[i] = false;
                break;
            }
        }
    }
}

void output(const vector<bool>& vect)
{
    cout << "Результирующий вектор:" << endl;
    for (int i = 0; i < vect.size(); i++)
    {
        cout << vect[i] << " ";
    }
    cout << endl;
}


int main()
{
    setlocale(LC_ALL, "Russian");
    int n, m;
    cout << "Введите размер матрицы [n x m]: ";
    cin >> n >> m;

    //выделение памяти
    double** matrix = new double*[n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new double[m];
    }

    //ввод матрицы
    input(matrix, n, m);

    vector<bool> vect(n, true);
    //построение логического вектора
    task(matrix, n, m, vect);

    //вывод вектора
    output(vect);

    //освобождение памяти
    for (int i = 0; i < n; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    system("pause");
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
