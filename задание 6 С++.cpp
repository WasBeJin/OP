#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n <= 1) {
        return 0;
    }

    // Инициализация массивов для хранения максимальной прибыли
    vector<int> firstTransactionProfit(n, 0);
    vector<int> secondTransactionProfit(n, 0);

    // Находим максимальную прибыль после первой транзакции
    int minPrice = prices[0];
    for (int i = 1; i < n; ++i) {
        minPrice = min(minPrice, prices[i]);
        firstTransactionProfit[i] = max(firstTransactionProfit[i - 1], prices[i] - minPrice);
    }

    // Находим максимальную прибыль после второй транзакции
    int maxPrice = prices[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        maxPrice = max(maxPrice, prices[i]);
        secondTransactionProfit[i] = max(secondTransactionProfit[i + 1], maxPrice - prices[i]);
    }

    // Находим общую максимальную прибыль после двух транзакций
    int maxProfit = 0;
    for (int i = 0; i < n; ++i) {
        maxProfit = max(maxProfit, firstTransactionProfit[i] + secondTransactionProfit[i]);
    }

    return maxProfit;
}

int main() {
    int n;
    cout << "Введите размер массива цен: ";
    cin >> n;

    vector<int> prices(n);
    cout << "Введите цены на акции: ";
    for (int i = 0; i < n; ++i) {
        cin >> prices[i];
    }

    int result = maxProfit(prices);
    cout << "Максимальная прибыль: " << result << endl;

    return 0;
}