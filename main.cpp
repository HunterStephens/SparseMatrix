#include <iostream>
#include "SparseMatrix.h"

int main() {
    SparseMatrix<double> H;
    H.append(2,4,12.0);
    H.append(3,2, -37.2);
    return 0;
}
