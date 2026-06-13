#include <iostream>

using namespace std;

int main() {
  const int SIZE = 10;
  string cities[SIZE];
  double temps[SIZE];
  double sum = 0.0;

  int hottestIdx = 0;
  int coldestIdx = 0;

  cout << endl;

  cout << "             -- City Temprature Analysis --           " << endl;
  cout << "______________________________________________________" << endl;

  cout << endl;

  cout << "Enter the name and average temperature for " << SIZE << " cities" << endl;

  cout << endl;

  for (int i = 0; i < SIZE; i++) {
    cout << "City " << i + 1 << " name: ";
    cin >> cities[i];
    cout << "City " << i + 1 << " average temperature: ";
    cin >> temps[i];
    sum += temps[i];

    if (temps[i] >= temps[hottestIdx]) {
        hottestIdx = i;
    }

    if (temps[i] <= temps[coldestIdx]) {
        coldestIdx = i;
    }
  }

  cout << "\n--- Statistics ---" << endl;

  cout << "Hottest City: " << cities[hottestIdx] << " (" << temps[hottestIdx] << " units)" << endl;
  cout << "Coldest City: " << cities[coldestIdx] << " (" << temps[coldestIdx] << " units)" << endl;

  cout << "Overall Average Temperature: " << sum / SIZE << endl;

  // Bubble Sorting of the array
  for (int i = 0; i < SIZE - 1; i++) {
    for (int j = 0; j < SIZE - i - 1; j++) {
      if (temps[j] < temps[j + 1]) {
        double tempVal = temps[j];
        temps[j] = temps[j + 1];
        temps[j + 1] = tempVal;

        string tempName = cities[j];
        cities[j] = cities[j + 1];
        cities[j + 1] = tempName;
      }
    }
  }

  cout << "\n--- Cities Sorted by Temperature (Descending) ---" << endl;
  for (int i = 0; i < SIZE; i++) {
    cout << cities[i] << ": " << temps[i] << endl;
  }

  search:

  string searchName;
  bool found = false;
  cout << "\nEnter a city name to search for its temperature: ";
  cin >> searchName;

  for (int i = 0; i < SIZE; i++) {
    if (cities[i] == searchName) {
      cout << "The temperature in " << cities[i] << " is " << temps[i] << endl;
      found = true;
      break;
    }
  }

  if (!found) {
    cout << "City not found in the records." << endl;
  }

  goto search;

  return 0;
}