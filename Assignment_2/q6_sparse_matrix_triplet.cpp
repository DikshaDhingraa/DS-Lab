#include <iostream>
#include <vector>
using namespace std;
 
// A sparse matrix in triplet form: each non-zero entry is one
// Triplet {row, col, value}. rows/cols are stored alongside.
struct Triplet {
    int row, col, value;
};
struct SparseMatrix {
    int rows, cols;
    vector<Triplet> entries;
};
 
void printSparse(const SparseMatrix &m) {
    cout << "Row\tCol\tValue" << endl;
    for (const Triplet &t : m.entries)
        cout << t.row << "\t" << t.col << "\t" << t.value << endl;
}
 
/* (a) Transpose of a sparse matrix */
SparseMatrix transposeSparse(const SparseMatrix &m) {
    SparseMatrix result{m.cols, m.rows, {}};
    // Scanning column by column keeps the transpose triplets
    // sorted by row (i.e. by the original column index)
    for (int col = 0; col < m.cols; col++)
        for (const Triplet &t : m.entries)
            if (t.col == col)
                result.entries.push_back({t.col, t.row, t.value});   // swap row/col
    return result;
}
 
/* (b) Addition of two sparse matrices of the same dimensions */
bool addSparse(const SparseMatrix &a, const SparseMatrix &b, SparseMatrix &result) {
    if (a.rows != b.rows || a.cols != b.cols) {
        cout << "Matrices cannot be added (dimension mismatch)." << endl;
        return false;
    }
    result.rows = a.rows;
    result.cols = a.cols;
    result.entries.clear();
 
    size_t i = 0, j = 0;
    while (i < a.entries.size() && j < b.entries.size()) {
        const Triplet &x = a.entries[i], &y = b.entries[j];
        if (x.row < y.row || (x.row == y.row && x.col < y.col)) {
            result.entries.push_back(x); i++;
        } else if (x.row > y.row || (x.row == y.row && x.col > y.col)) {
            result.entries.push_back(y); j++;
        } else {   // same position -> add the values
            int sum = x.value + y.value;
            if (sum != 0) result.entries.push_back({x.row, x.col, sum});
            i++; j++;
        }
    }
    while (i < a.entries.size()) result.entries.push_back(a.entries[i++]);
    while (j < b.entries.size()) result.entries.push_back(b.entries[j++]);
    return true;
}
 
/* (c) Multiplication of two sparse matrices */
bool multiplySparse(const SparseMatrix &a, const SparseMatrix &b, SparseMatrix &result) {
    if (a.cols != b.rows) {
        cout << "Matrices cannot be multiplied (dimension mismatch)." << endl;
        return false;
    }
    result.rows = a.rows;
    result.cols = b.cols;
    result.entries.clear();
 
    for (int r = 0; r < a.rows; r++) {
        for (int c = 0; c < b.cols; c++) {
            int sum = 0;
            for (const Triplet &x : a.entries) {
                if (x.row == r) {
                    for (const Triplet &y : b.entries) {
                        if (y.row == x.col && y.col == c)
                            sum += x.value * y.value;
                    }
                }
            }
            if (sum != 0) result.entries.push_back({r, c, sum});
        }
    }
    return true;
}
 
int main() {
    // A (3x3):        0 0 3
    //                 0 5 0
    //                 7 0 0
    SparseMatrix A{3, 3, {{0, 2, 3}, {1, 1, 5}, {2, 0, 7}}};
 
    SparseMatrix T = transposeSparse(A);
    cout << "Transpose of A:" << endl;
    printSparse(T);
 
    // B (3x3):        0 0 4
    //                 0 0 0
    //                 1 0 2
    SparseMatrix B{3, 3, {{0, 2, 4}, {2, 0, 1}, {2, 2, 2}}};
 
    SparseMatrix C;
    if (addSparse(A, B, C)) {
        cout << endl << "A + B:" << endl;
        printSparse(C);
    }
 
    SparseMatrix D;
    if (multiplySparse(A, B, D)) {
        cout << endl << "A * B:" << endl;
        printSparse(D);
    }
 
    return 0;
}
