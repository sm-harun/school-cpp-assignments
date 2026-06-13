#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Patient {
  int id;
  string name;
  int age;
  double cost;
};

int main() {
  cout << endl;

  cout << "                  -- Patient Records --               " << endl;
  cout << "______________________________________________________" << endl;

  cout << endl;

  int numPatients;

  cout << "Enter the number of patients to record: ";
  cin >> numPatients;
  cin.clear();
  cin.ignore(1000, '\n');

  cout << endl;

  // Dynamic Memory Allocation
  Patient* patientList = new Patient[numPatients];

  double totalCost = 0.0;

  // Input patient records
  for (int i = 0; i < numPatients; i++) {
    cout << "\n--- Recording Patient " << i + 1 << " ---" << endl;
    cout << "Patient ID: ";
    cin >> (patientList + i)->id;
    cin.ignore();

    cout << "Name: ";
    getline(cin, (patientList + i)->name);

    cout << "Age: ";
    cin >> (patientList + i)->age;

    cout << "Treatment Cost: ";
    cin >> (patientList + i)->cost;

    totalCost += (patientList + i)->cost;
  }

  Patient* highestCostPatient = &patientList[0];

  for (int i = 1; i < numPatients; i++) {
    if ((patientList + i)->cost > highestCostPatient->cost) {
      highestCostPatient = &patientList[i];
    }
  }

  cout << "\n==============================================" << endl;
  cout << "ID\tName\t\tAge\tCost" << endl;
  cout << "----------------------------------------------" << endl;

  for (int i = 0; i < numPatients; i++) {
    cout << (patientList + i)->id << "\t" 
         << (patientList + i)->name << "\t\t" 
         << (patientList + i)->age << "\t$" 
         << (patientList + i)->cost << endl;
  }

  cout << "==============================================" << endl;
  cout << "Total Treatment Cost: $" << totalCost << endl;
  cout << "Highest Cost Patient: " << highestCostPatient->name 
       << " ($" << highestCostPatient->cost << ")" << endl;

  // Release allocated memory
  delete[] patientList;
  patientList = nullptr;

  cout << "\nMemory successfully released. Exiting program." << endl;

  return 0;
}