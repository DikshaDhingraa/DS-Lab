#include <iostream>
#include <vector>
using namespace std;
 
const int N = 4;   // matrix dimension used for demonstration
typedef vector<vector<int>> Matrix;
 
/* ---------- (a) Diagonal Matrix ----------
   Only the n diagonal elements are non-zero.
   Stored in a 1D array of size n. */
vector<int> storeDiagonal(const Matrix &mat) {
    vector<int> diag(N);
    for (int i = 0; i < N; i++)
        diag[i] = mat[i][i];
    return diag;
}
int getDiagonal(const vector<int> &diag, int i, int j) {
    return (i == j) ? diag[i] : 0;
}
 
/* ---------- (b) Tri-diagonal Matrix ----------
   Only the main diagonal and the two diagonals next to it
   are non-zero. Stored in a 1D array of size 3n-2. */
vector<int> storeTriDiagonal(const Matrix &mat) {
    vector<int> tri;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (j == i - 1 || j == i || j == i + 1)
                tri.push_back(mat[i][j]);
    return tri;
}
int getTriDiagonal(const vector<int> &tri, int i, int j) {
    if (j < i - 1 || j > i + 1) return 0;
    // row 0 only has 2 stored entries, every later row has 3
    int start = (i == 0) ? 0 : (2 + 3 * (i - 1));
    int offset = (i == 0) ? j : (j - i + 1);
    return tri[start + offset];
}
 
/* ---------- (c) Lower Triangular Matrix ----------
   Only elements where j <= i are non-zero.
   Stored row-wise in a 1D array of size n(n+1)/2. */
vector<int> storeLowerTriangular(const Matrix &mat) {
    vector<int> low;
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++)
            low.push_back(mat[i][j]);
    return low;
}
int getLowerTriangular(const vector<int> &low, int i, int j) {
    if (j > i) return 0;
    int index = i * (i + 1) / 2 + j;
    return low[index];
}
 
/* ---------- (d) Upper Triangular Matrix ----------
   Only elements where j >= i are non-zero.
   Stored row-wise in a 1D array of size n(n+1)/2. */
vector<int> storeUpperTriangular(const Matrix &mat) {
    vector<int> up;
    for (int i = 0; i < N; i++)
        for (int j = i; j < N; j++)
            up.push_back(mat[i][j]);
    return up;
}
int getUpperTriangular(const vector<int> &up, int i, int j) {
    if (j < i) return 0;
    int index = i * N - (i * (i - 1)) / 2 + (j - i);
    return up[index];
}
 
/* ---------- (e) Symmetric Matrix ----------
   mat[i][j] == mat[j][i], so only the lower triangle
   (including the diagonal) needs to be stored. */
vector<int> storeSymmetric(const Matrix &mat) {
    vector<int> sym;
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++)
            sym.push_back(mat[i][j]);
    return sym;
}
int getSymmetric(const vector<int> &sym, int i, int j) {
    if (j > i) swap(i, j);   // ensure i >= j
    int index = i * (i + 1) / 2 + j;
    return sym[index];
}
 
int main() {
    Matrix mat = {
        {1, 2, 0, 0},
        {2, 3, 4, 0},
        {0, 4, 5, 6},
        {0, 0, 6, 7}
    };
 
    vector<int> diag = storeDiagonal(mat);
    cout << "Diagonal element (2,2): " << getDiagonal(diag, 2, 2) << endl;
 
    vector<int> tri = storeTriDiagonal(mat);
    cout << "Tri-diagonal element (1,2): " << getTriDiagonal(tri, 1, 2) << endl;
 
    vector<int> low = storeLowerTriangular(mat);
    cout << "Lower triangular element (3,1): " << getLowerTriangular(low, 3, 1) << endl;
 
    vector<int> up = storeUpperTriangular(mat);
    cout << "Upper triangular element (1,3): " << getUpperTriangular(up, 1, 3) << endl;
 
    vector<int> sym = storeSymmetric(mat);
    cout << "Symmetric element (0,1) via (1,0): " << getSymmetric(sym, 1, 0) << endl;
 
    return 0;
}
