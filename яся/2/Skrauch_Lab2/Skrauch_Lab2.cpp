#include <thread>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <mutex>

using namespace std;

mutex m;

vector<int> v0(0);

vector<int> v1(10);
vector<int> v2(100);
vector<int> v3(1000);
vector<int> v4(100000);

void func(int start, int end)
{
    m.lock();
    for (int i = start; i < end; ++i)
    {
        v1[i] *= 2;
    }
    m.unlock();
}

int main()
{
	setlocale(0, "Russian");
    
    //zadanie 1
    /*
    int n = 0;
    cout << "Введите длинну вектора >> "; cin >> n;

    vector<int> v0(n);

    cout << "\n" << "Исходный вектор >> ";

    for (int i = 0; i < n; ++i)
    {
        v0[i] = rand();
        cout << v0[i] << " ";
        v0[i] *= 2;
    }

    cout << "\n" << "Результат >> ";

    for (int i = 0; i < n; ++i)
    {
        cout << v0[i] << " ";
    }
    */
    //*************************************************************

    //zadanie 2
    /*
    int M = 0;
    
    cout << "Кол-во потоков >> "; cin >> M;

    vector<int> v0 = { 3, 2, 4, 5, 1 };

    for (int i = 0; i < v0.size(); ++i)
    {
        cout << v0[i];
    }

    vector<thread> t(M);

    for (int i = 0; i < M - 1; ++i)
    {
        t[i] = thread(func, i * (v0.size() / M), (i + 1) * (v0.size() / M));
        t[i].join();
    }

    t[M - 1] = thread(func, (M - 1) * (v0.size() / M), v0.size());
    t[M - 1].join();

    cout << endl;

    for (int i = 0; i < v0.size(); ++i)
    {
        cout << v0[i];
    }
    */
    //*************************************************************
    
    //zadanie 3
    
    for (int i = 0; i < v1.size(); ++i)
    {
        v1[i] = i;
    }

    for (int i = 0; i < v2.size(); ++i)
    {
        v2[i] = i;
    }

    for (int i = 0; i < v3.size(); ++i)
    {
        v3[i] = i;
    }

    for (int i = 0; i < v4.size(); ++i)
    {
        v4[i] = i;
    }

    vector<int> M = { 2, 3, 4, 5, 10 };

    //>>>>>>>>>>>>>>>>>>>>>>>>>>>   N 10

    v2 = v0;

    cout << " | ";

    for (int i = 0; i < M.size(); ++i)
    {
        vector<thread> threads(M[i]);

        cout << "M" << "(" << M[i] << "): ";

        unsigned int start_time = clock();

        for (int j = 0; j < threads.size() - 1; ++j)
        {
            threads[j] = thread(func, j * (M.size() / threads.size()), (j + 1) * (M.size() / threads.size()));
            threads[j].join();
        }

        threads[threads.size() - 1] = thread(func, (threads.size() - 1) * (v1.size() / threads.size()), v1.size());
        threads[threads.size() - 1].join();

        unsigned int end_time = clock();
        unsigned int search_time = end_time - start_time;

        cout << search_time << " время" << " | ";
    }

    //>>>>>>>>>>>>>>>>>>>>>>>>>>>   N 100

    v0 = v2;

    cout << endl << " | ";

    for (int i = 0; i < M.size(); ++i)
    {
        vector<thread> threads(M[i]);

        cout << "M" << "(" << M[i] << "): ";

        unsigned int start_time = clock();

        for (int j = 0; j < threads.size() - 1; ++j)
        {
            threads[j] = thread(func, j * (M.size() / threads.size()), (j + 1) * (M.size() / threads.size()));
            threads[j].join();
        }

        threads[threads.size() - 1] = thread(func, (threads.size() - 1) * (v1.size() / threads.size()), v1.size());
        threads[threads.size() - 1].join();

        unsigned int end_time = clock();
        unsigned int search_time = end_time - start_time;

        cout << search_time << " время" << " | ";
    }

    //>>>>>>>>>>>>>>>>>>>>>>>>>>>   N 1000

    v0 = v3;

    cout << endl << " | ";

    for (int i = 0; i < M.size(); ++i)
    {
        vector<thread> threads(M[i]);

        cout << "M" << "(" << M[i] << "): ";

        unsigned int start_time = clock();

        for (int j = 0; j < threads.size() - 1; ++j)
        {
            threads[j] = thread(func, j * (M.size() / threads.size()), (j + 1) * (M.size() / threads.size()));
            threads[j].join();
        }

        threads[threads.size() - 1] = thread(func, (threads.size() - 1) * (v1.size() / threads.size()), v1.size());
        threads[threads.size() - 1].join();

        unsigned int end_time = clock();
        unsigned int search_time = end_time - start_time;

        cout << search_time << " время" << " | ";
    }

    //>>>>>>>>>>>>>>>>>>>>>>>>>>>   N 100000

    v1 = v4;

    cout << endl << " | ";

    for (int i = 0; i < M.size(); ++i)
    {
        vector<thread> threads(M[i]);

        cout << "M" << "(" << M[i] << "): ";

        unsigned int start_time = clock();

        for (int j = 0; j < threads.size() - 1; ++j)
        {
            threads[j] = thread(func, j * (M.size() / threads.size()), (j + 1) * (M.size() / threads.size()));
            threads[j].join();
        }

        threads[threads.size() - 1] = thread(func, (threads.size() - 1) * (v1.size() / threads.size()), v1.size());
        threads[threads.size() - 1].join();

        unsigned int end_time = clock();
        unsigned int search_time = end_time - start_time;

        cout << search_time << " время" << " | ";



    }
}