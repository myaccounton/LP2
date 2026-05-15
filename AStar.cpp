#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

// Structure for puzzle state
struct Node {
    vector<vector<int>> mat;
    int x, y;      // Blank tile position
    int cost;      // Heuristic cost
    int level;     // Depth level
};

// Goal State
vector<vector<int>> goal = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 0}
};

// Calculate heuristic (Misplaced Tiles)
int calculateCost(vector<vector<int>> mat) {
    int count = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(mat[i][j] && mat[i][j] != goal[i][j])
                count++;
        }
    }
    return count;
}

// Print matrix
void printMatrix(vector<vector<int>> mat) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Comparator for priority queue
struct compare {
    bool operator()(Node a, Node b) {
        return (a.cost + a.level) > (b.cost + b.level);
    }
};

int main() {

    // Initial State
    vector<vector<int>> initial = {
        {1, 2, 3},
        {4, 0, 6},
        {7, 5, 8}
    };

    priority_queue<Node, vector<Node>, compare> pq;

    Node start;
    start.mat = initial;
    start.x = 1;
    start.y = 1;
    start.level = 0;
    start.cost = calculateCost(initial);

    pq.push(start);

    int row[] = {1, -1, 0, 0};
    int col[] = {0, 0, 1, -1};

    while(!pq.empty()) {

        Node current = pq.top();
        pq.pop();

        printMatrix(current.mat);

        // Goal reached
        if(current.cost == 0) {
            cout << "Goal State Reached!";
            return 0;
        }

        // Generate child nodes
        for(int i = 0; i < 4; i++) {

            int newX = current.x + row[i];
            int newY = current.y + col[i];

            if(newX >= 0 && newX < 3 && newY >= 0 && newY < 3) {

                Node child = current;

                swap(child.mat[current.x][current.y],
                     child.mat[newX][newY]);

                child.x = newX;
                child.y = newY;
                child.level = current.level + 1;
                child.cost = calculateCost(child.mat);

                pq.push(child);
            }
        }
    }

    return 0;
}

