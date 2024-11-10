#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <ctime>
#include <locale>

using namespace std;

double find_mean(const vector<int>& data) {
    int sum = 0;
    for (int num : data) {
        sum += num;
    }
    return static_cast<double>(sum) / data.size();
}

double find_median(vector<int> data) {
    sort(data.begin(), data.end());
    int size = data.size();
    if (size % 2 == 0) {
        return (data[size / 2 - 1] + data[size / 2]) / 2.0;
    }
    else {
        return data[size / 2];
    }
}

int find_mode(const vector<int>& data) {
    map<int, int> frequency;
    for (int num : data) {
        frequency[num]++;
    }

    int mode = data[0];
    int max_count = 0;
    for (const auto& pair : frequency) {
        if (pair.second > max_count) {
            max_count = pair.second;
            mode = pair.first;
        }
    }
    return mode;
}

int main() {
    setlocale(LC_ALL, "ukr"); 
    int N;
    cout << "Введiть номер студента: ";
    cin >> N;

    int size = N + 10;
    vector<int> data(size);

    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < size; i++) {
        data[i] = rand() % (N + 1) + 1;
    }

    cout << "Згенерована послiдовнiсть: ";
    for (int num : data) {
        cout << num << " ";
    }
    cout << endl;

    double mean = find_mean(data);
    double median = find_median(data);
    int mode = find_mode(data);

    cout << "Середнє арифметичне: " << mean << endl;
    cout << "Медiана: " << median << endl;
    cout << "Мода: " << mode << endl;

    return 0;
}
