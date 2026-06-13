#include <iostream>

using namespace std;

const int TOTAL_DAYS = 30;

int main() {
    start: 

    cout << endl;

    cout << "                -- SALES ANALYZER --                  " << endl;
    cout << "______________________________________________________" << endl;

    cout << endl;

    options:

    cout << "1. Start" << endl;
    cout << "2. Quit" << endl;

    cout << endl;

    int answer;

    cout << "Answer using the option's index: ";
    cin >> answer;

    cout << endl;

    if (answer < 1 || answer > 2) {
        cout << "Unknown command! Please select a valid option!" << endl;

        cout << endl;

        goto options;
    }

    if (answer == 2) {
        return 0;
    }

    int dailySalesTarget;

    cout << "Daily sales target: ";
    cin >> dailySalesTarget;

    int totalSales = 0;

    // Highest and lowest are set to -1 to make it easy to give them the values of the first day
    int highestSale = -1;
    int highestSaleDay = 1;

    int lowestSale = -1;
    int lowestSaleDay = 1;

    int satisfiedDays = 0;

    int currentSale;

    for (int i = 1; i <= TOTAL_DAYS; i++) {
        cout << "Daily sales for day " << i << ": ";
        cin >> currentSale;

        if (currentSale < 0) {
            cout << "You can't enter negative values." << endl;
            i--;
            continue;
        }

        totalSales += currentSale;

        if (currentSale > highestSale) {
            highestSale = currentSale;
            highestSaleDay = i;
        }

        // Setting the value if it hadn't been set by another day yet.
        if (lowestSale == -1 || currentSale < lowestSale) {
            lowestSale = currentSale;
            lowestSaleDay = i;
        }

        if (highestSale == -1 || currentSale >= dailySalesTarget) {
            satisfiedDays += 1;
        }
    }

    cout << endl;

    cout << "______________________________________________________" << endl;

    cout << endl;

    cout << "Total monthly sales: " << totalSales << endl;
    cout << "Average daily sales: " << (float)totalSales / TOTAL_DAYS << endl;
    cout << "Highest sale: " << highestSale << " on day " << highestSaleDay << endl;
    cout << "Lowest sale: " << lowestSale << " on day " << lowestSaleDay << endl;
    cout << "Number of days over sales target: " << satisfiedDays << endl;

    cout << endl;

    goto start;

    return 0;
}