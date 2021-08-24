#include "array"

using namespace std;

// representation of sparse matrix as
// Compressed Sparse Row or CSR
struct sparse_matrix {
    int n; // size of matrix
    int nnz; // number of non-zero values
    /**
     * Array of ints. Indices correspond to rows in the matrix.
     * Values correspond to the first non-zero element in the row of the matrix.
     * Values also point to the indices in the cols array and in the vals array.
     */
    int *rows; // length n
    /**
     * Array of ints. values correspond to indices in the matrix row that point to
     * non-zero elements.
     */
    int *cols; // length n
    /**
     * Stores non-zero values.
     */
    double *vals;
};

void sparseMatrixVectorMultiplication(sparse_matrix *A, const double *x, double *y) {
    for (int i = 0; i < A->n; ++i) {
        y[i] = 0;
        for (int k = A->rows[i]; k < A->rows[i + 1]; ++k) {
            int j = A->cols[k];
            y[i] += A->vals[k] * x[j];
        }
    }
}