#include <iostream>
using namespace std;

// ---------- PATIENT STRUCT ----------
struct Patient {
    int id;
    int severity;
};

// ---------- SELECTION SORT ----------
void selectionSortPatients() {
    int n;
    cout << "Enter number of patients: ";
    cin >> n;

    Patient p[n];

    // Input patient details
    for(int i = 0; i < n; i++) {
        cout << "Enter Patient ID: ";
        cin >> p[i].id;

        cout << "Enter Severity (smaller = more critical): ";
        cin >> p[i].severity;
    }

    // Selection Sort
    for(int i = 0; i < n - 1; i++) {

        int min = i;

        for(int j = i + 1; j < n; j++) {

            if(p[j].severity < p[min].severity) {
                min = j;
            }
        }

        swap(p[i], p[min]);
    }

    // Display sorted patients
    cout << "\nPatient Treatment Priority\n";

    for(int i = 0; i < n; i++) {
        cout << "Patient " << p[i].id
             << " Severity " << p[i].severity << endl;
    }
}
  
// ---------- MAIN ----------
int main() {

    selectionSortPatients();

    return 0;
}