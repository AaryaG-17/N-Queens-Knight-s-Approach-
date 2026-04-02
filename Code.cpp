#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

// Represents a square on the 8x8 board
struct Square {
    int r, c;
    // Sorting operator so we can store them in a set for uniqueness
    bool operator<(const Square& other) const {
        if (r != other.r) return r < other.r;
        return c < other.c;
    }
    bool operator==(const Square& other) const {
        return r == other.r && c == other.c;
    }
};

// Global storage for unique 8-queen combinations
set<set<Square>> all_combinations;

// Knight moves (dx, dy)
int dr[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dc[] = {-1, 1, -2, 2, -2, 2, -1, 1};

// Check if placing a queen at (nr, nc) is valid according to standard Queen rules
bool is_safe(int nr, int nc, const vector<Square>& current_queens) {
    for (const auto& q : current_queens) {
        // Same row or column
        if (q.r == nr || q.c == nc) return false;
        // Same diagonal (Non-wrapping as per Rule 6)
        if (abs(q.r - nr) == abs(q.c - nc)) return false;
    }
    return true;
}

// Recursive backtracking function
void find_queens(vector<Square>& path) {
    // Base Case: All 8 queens placed
    if (path.size() == 8) {
        set<Square> combo(path.begin(), path.end());
        all_combinations.insert(combo);
        return;
    }

    // Get the position of the last queen placed to calculate next knight moves
    Square last = path.back();

    for (int i = 0; i < 8; i++) {
        // Toroidal wrap-around calculation for Knight moves
        int nr = (last.r + dr[i]) % 8;
        if (nr < 0) nr += 8;
        int nc = (last.c + dc[i]) % 8;
        if (nc < 0) nc += 8;

        // Rule: Only move to a valid (non-attacked) square
        if (is_safe(nr, nc, path)) {
            path.push_back({nr, nc});
            find_queens(path);
            path.pop_back(); // Backtrack
        }
    }
}

int main() {
    cout << "Searching for combinations..." << endl;

    // Iterate through every square on the board as a starting point for the 1st Queen
    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
            vector<Square> path;
            path.push_back({r, c});
            find_queens(path);
        }
    }

    // Output all unique combinations found
    cout << "Total Unique Combinations Found: " << all_combinations.size() << endl;
    cout << "------------------------------------------" << endl;

    int count = 1;
    for (const auto& combo : all_combinations) {
        cout << "Combination " << count++ << ": ";
        for (const auto& s : combo) {
            cout << "(" << s.r << "," << s.c << ") ";
        }
        cout << endl;
    }

    return 0;
}
