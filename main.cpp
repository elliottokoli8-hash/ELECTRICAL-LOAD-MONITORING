#include <iostream>
#include <vector>
using namespace std;

class Appliance {
public:
    string name;
    double power;   // watts
    double hours;   // daily usage
};

vector<Appliance> appliances;

void menu() {
    cout << "\n=== Electrical Load Monitor ===\n";
    cout << "1. Add Appliance\n";
    cout << "2. View Appliances\n";
    cout << "3. Exit\n";
    cout << "Choose: ";
}

int main() {
    int choice;

    do {
        menu();
        cin >> choice;

        if (choice == 1) {
            Appliance a;
            cout << "Name: ";
            cin >> a.name;
            cout << "Power (W): ";
            cin >> a.power;
            cout << "Hours: ";
            cin >> a.hours;

            appliances.push_back(a);
        }
        else if (choice == 2) {
            for (auto &a : appliances) {
                cout << a.name << " | "
                     << a.power << "W | "
                     << a.hours << "h\n";
            }
        }

    } while (choice != 3);

    return 0;
}
