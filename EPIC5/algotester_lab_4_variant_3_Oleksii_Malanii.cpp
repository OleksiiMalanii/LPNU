#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

int main() {
    // Зчитуємо кількість чисел у масиві
    int N;
    std::cin >> N;

    // Зчитуємо елементи масиву
    std::vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> arr[i];
    }

    // Розділяємо масив на три частини по остачі від ділення на 3
    std::vector<int> remainder0, remainder1, remainder2;

    for (int i = 0; i < N; ++i) {
        if (arr[i] % 3 == 0) {
            remainder0.push_back(arr[i]);
        } else if (arr[i] % 3 == 1) {
            remainder1.push_back(arr[i]);
        } else {
            remainder2.push_back(arr[i]);
        }
    }

    // Сортуємо за умовами задачі
    std::sort(remainder0.begin(), remainder0.end());
    std::sort(remainder1.rbegin(), remainder1.rend()); // У спадаючому порядку
    std::sort(remainder2.begin(), remainder2.end());

    // Об'єднуємо три частини в один масив
    std::vector<int> result;
    result.insert(result.end(), remainder0.begin(), remainder0.end());
    result.insert(result.end(), remainder1.begin(), remainder1.end());
    result.insert(result.end(), remainder2.begin(), remainder2.end());

    // Видаляємо дублікати
    std::unordered_set<int> uniqueSet(result.begin(), result.end());
    result.assign(uniqueSet.begin(), uniqueSet.end());

    // Виводимо результат
    int M = result.size();
    std::cout << M << std::endl;

    for (int i = 0; i < M; ++i) {
        std::cout << result[i] << " ";
    }

    return 0;
}
