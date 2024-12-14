#include "Array.h"

using namespace std;

long long int func(Array& arr, int val2)
{
    return arr.run(val2);
}

int create()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(100, 100000);

    return dist(gen);
}

mutex result_mutex;

int main()
{


    vector<thread> threads;

    int N;

    int M;

    cout << "Enter array size: ";
    cin >> N;

    cout << "Enter threads count: ";
    cin >> M;

    int sub_N = N;
    long long int result = 0;

    unsigned int val = N % M;
    int val2 = (N - val) / M;

    for (int i = 0; i < M; ++i)
    {
        threads.emplace_back([val, val2, &result]()
            {
                Array arr;
                int count = val > 0 ? val2 + 1 : val2; // Распределение по частям
                long long int partial_result = func(arr, count);

                // Блокировка для безопасного доступа к result
                lock_guard<mutex> lock(result_mutex);
                result += partial_result;
            });

        if (val > 0) --val;
    }

    for (auto& th : threads)
    {
        th.join();
    }

    cout << result;

    return 0;
}