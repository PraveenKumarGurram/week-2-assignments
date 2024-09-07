#include <iostream>
#include <vector>
using namespace std;

// Structure to represent a non-zero element in the sparse matrix
struct Element {
    int row;    // Row index of the non-zero element
    int col;    // Column index of the non-zero element
    int value;  // Value of the non-zero element
};

// Class for Sparse Matrix
class SparseMatrix {
private:
    int rows;                   // Total number of rows in the matrix
    int cols;                   // Total number of columns in the matrix
    vector<Element> elements;   // Vector to store non-zero elements (row, col, value)

public:
    // Constructor to initialize rows and columns
    SparseMatrix(int r, int c) : rows(r), cols(c) {}

    // Function to add a non-zero element to the sparse matrix
    void addElement(int r, int c, int value) {
        if (value != 0) {
            Element e;
            e.row = r;
            e.col = c;
            e.value = value;
            elements.push_back(e);  // Add the element to the list
        }
    }

    // Function to input the elements of the matrix
    void inputMatrix() {
        int value;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << "Enter the element at position (" << i << "," << j << "): ";
                cin >> value;
                addElement(i, j, value);  // Add only non-zero elements
            }
        }
    }

    // Function to display the sparse matrix in row-column-value format
    void displaySparseMatrix() {
        cout << "\nSparse Matrix Representation (Row, Column, Value):\n";
        cout << "| Row | Column | Value |\n";
        cout << "------------------------\n";
        for (size_t i = 0; i < elements.size(); i++) {
            cout << "| " << elements[i].row << "   | " 
                 << elements[i].col << "      | " 
                 << elements[i].value << "     |\n";
        }
        cout << "------------------------\n";
    }

    // Function to display the matrix in its normal 2D form
    void displayMatrix() {
        cout << "\nMatrix in 2D Form:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int found = 0;
                for (size_t k = 0; k < elements.size(); k++) {
                    if (elements[k].row == i && elements[k].col == j) {
                        cout << elements[k].value << " ";  // Print non-zero element
                        found = 1;
                        break;
                    }
                }
                if (!found)
                    cout << "0 ";  // Print zero if no non-zero element is found
            }
            cout << endl;
        }
    }
};

int main() {
    int rows, cols;

    // Input the size of the matrix (number of rows and columns)
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    // Create a sparse matrix object
    SparseMatrix matrix(rows, cols);

    // Input the matrix values from the user
    matrix.inputMatrix();

    // Display the sparse matrix in (Row, Column, Value) format
    matrix.displaySparseMatrix();


    return 0;
}
