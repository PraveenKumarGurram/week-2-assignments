#include <iostream>
#include <unordered_map>
using namespace std;

// Node structure for the linked list
struct Node {
    int row, col, value;
    Node* next;
    
    // Constructor for creating a new node
    Node(int r, int c, int val) : row(r), col(c), value(val), next(nullptr) {}
};

// Class to implement the Sparse Matrix using Linked List with Hash Map
class SparseMatrix {
private:
    Node* head; // Head of the linked list
    
public:
    // Constructor to initialize the sparse matrix
    SparseMatrix() {
        head = nullptr;
    }
    
    // Function to insert a value into the sparse matrix
    void insert(int row, int col, int value) {
        // Only insert non-zero values
        if (value != 0) {
            Node* newNode = new Node(row, col, value);
            
            if (head == nullptr) {
                // If the list is empty, the new node is the head
                head = newNode;
            } else {
                // Traverse the list and add the new node at the end
                Node* temp = head;
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }
    }
    
    // Function to display the linked list representation of the sparse matrix
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << "Row: " << temp->row << ", Column: " << temp->col << ", Value: " << temp->value
                 << ", Next Node Address: " << temp->next << endl;
            temp = temp->next;
        }
    }
};

int main() {
    SparseMatrix sparseMatrix;
    int rows, cols, value;

    // Get matrix dimensions from the user
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;
    
    // Loop through all elements and insert non-zero values into the sparse matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter value for [" << i << "][" << j << "]: ";
            cin >> value;
            sparseMatrix.insert(i, j, value);
        }
    }
    
    // Display the sparse matrix in linked list form
    cout << "Linked List Representation of Sparse Matrix:\n";
    sparseMatrix.display();
    
    return 0;
}