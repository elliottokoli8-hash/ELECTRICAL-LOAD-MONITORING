#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

class Appliance {
public:
    string name;
    double powerRating;
    double usageHours;

    // Calculate energy in kWh
    double calculateEnergy() {
        return (powerRating * usageHours) / 1000;
    }
};

// Global array
Appliance appliances[MAX];
int count = 0;

// Function to register appliance
void registerAppliance() {
    if (count >= MAX) {
        cout << "Storage full!\n";
        return;
    }

    cout << "\nEnter Appliance Name: ";
    cin.ignore();
    getline(cin, appliances[count].name);

    if (appliances[count].name.empty()) {
        cout << "Name cannot be empty!\n";
        return;
    }

    cout << "Enter Power Rating (Watts): ";
    cin >> appliances[count].powerRating;

    if (appliances[count].powerRating <= 0) {
        cout << "Invalid power rating!\n";
        return;
    }

    cout << "Enter Usage Hours per day: ";
    cin >> appliances[count].usageHours;

    if (appliances[count].usageHours < 0 || appliances[count].usageHours > 24) {
        cout << "Usage hours must be between 0 and 24!\n";
        return;
    }

    count++;
    cout << "Appliance added successfully!\n";
}

// Function to view appliances
void viewAppliances() {
    if (count == 0) {
        cout << "\nNo appliances registered yet.\n";
        return;
    }

    cout << "\n--- Registered Appliances ---\n";
    for (int i = 0; i < count; i++) {
        cout << i + 1 << ". "
             << appliances[i].name
             << " | Power: " << appliances[i].powerRating << "W"
             << " | Usage: " << appliances[i].usageHours << " hrs/day"
             << " | Energy: " << appliances[i].calculateEnergy() << " kWh\n";
    }
}

// Function to search appliance
void searchAppliance() {
    if (count == 0) {
        cout << "No appliances available.\n";
        return;
    }

    string searchName;
    cout << "Enter appliance name to search: ";
    cin.ignore();
    getline(cin, searchName);

    bool found = false;

    for (int i = 0; i < count; i++) {
        if (appliances[i].name == searchName) {
            cout << "\nFound:\n";
            cout << appliances[i].name
                 << " | Power: " << appliances[i].powerRating << "W"
                 << " | Usage: " << appliances[i].usageHours << " hrs/day"
                 << " | Energy: " << appliances[i].calculateEnergy() << " kWh\n";
            found = true;
        }
    }

    if (!found) {
        cout << "Appliance not found.\n";
    }
}

// Function to calculate total energy
void calculateTotalEnergy() {
    if (count == 0) {
        cout << "No appliances available.\n";
        return;
    }

    double totalEnergy = 0;

    for (int i = 0; i < count; i++) {
        totalEnergy += appliances[i].calculateEnergy();
    }

    cout << "\nTotal Energy Consumption: " << totalEnergy << " kWh\n";
}

// Main menu
int main() {
    int choice;

    do {
        cout << "\n===== ELECTRICAL LOAD MONITOR =====\n";
        cout << "1. Register Appliance\n";
        cout << "2. View Appliances\n";
        cout << "3. Search Appliance\n";
        cout << "4. Calculate Total Energy\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            registerAppliance();
            break;
        case 2:
            viewAppliances();
            break;
        case 3:
            searchAppliance();
            break;
        case 4:
            calculateTotalEnergy();
            break;
        case 5:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}