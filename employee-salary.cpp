#include <iostream>
#include <string>

using namespace std;

const double OVERTIME_RATE = 200.0;
const double TAX_RATE = 0.15;

double calculateOvertimePayment(double hours);
double calculateTax(double grossSalary);
double calculateNetSalary(double basicSalary, double overtimePayment, double tax);

void displayPayroll(int id, string name, double basic, double otPayment, double tax, double net);

int main() {
  int empID;
  string empName;
  double basicSalary, otHours;

  cout << endl;

  cout << "             -- Employee Salary Analyzer --           " << endl;
  cout << "______________________________________________________" << endl;

  cout << endl;

  cout << "Enter Employee ID: ";
  cin >> empID;
  cin.ignore();

  cout << "Enter Employee Name: ";
  getline(cin, empName);

  cout << "Enter Basic Salary (ETB): ";
  cin >> basicSalary;

  cout << "Enter Overtime Hours: ";
  cin >> otHours;

  double otPayment = calculateOvertimePayment(otHours);
  double tax = calculateTax(basicSalary + otPayment);
  double net = calculateNetSalary(basicSalary, otPayment, tax);

  displayPayroll(empID, empName, basicSalary, otPayment, tax, net);

  return 0;
}

double calculateOvertimePayment(double hours) {
  return hours * OVERTIME_RATE;
}

double calculateTax(double grossSalary) {
  return grossSalary * TAX_RATE;
}

double calculateNetSalary(double basicSalary, double overtimePayment, double tax) {
  return (basicSalary + overtimePayment) - tax;
}

void displayPayroll(int id, string name, double basic, double otPayment, double tax, double net) {
  cout << "\n========================================\n";
  cout << "           EMPLOYEE PAYROLL             \n";
  cout << "========================================\n";

  cout << "Employee ID:       " << id << "\n";
  cout << "Employee Name:     " << name << "\n";
  cout << "Basic Salary:      " << basic << " ETB\n";
  cout << "Overtime Payment:  " << otPayment << " ETB\n";
  cout << "Gross Salary:      " << (basic + otPayment) << " ETB\n";
  cout << "Tax Deduction:     " << tax << " ETB\n";
  cout << "----------------------------------------\n";
  cout << "NET SALARY:        " << net << " ETB\n";
  cout << "========================================\n";
}