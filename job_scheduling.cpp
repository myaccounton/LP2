#include <iostream>
#include <algorithm>
using namespace std;

struct Job {
    char id;
    int deadline;
    int profit;
};

// Sort jobs by profit
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {

    int n;

    cout << "Enter number of jobs: ";
    cin >> n;

    Job jobs[n];

    for(int i = 0; i < n; i++) {
        cout << "Enter Job ID, Deadline and Profit: ";
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }

    sort(jobs, jobs + n, compare);

    int slot[10] = {0};

    cout << "Selected Jobs: ";

    for(int i = 0; i < n; i++) {

        for(int j = jobs[i].deadline - 1; j >= 0; j--) {

            if(slot[j] == 0) {
                slot[j] = 1;
                cout << jobs[i].id << " ";
                break;
            }
        }
    }

    return 0;
}