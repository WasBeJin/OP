#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int inputInteger() {
    int x;
    cin >> x;
    while (cin.fail() || x <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid positive integer: ";
        cin >> x;
    }
    return x;
}

float input() {
    float x;
    cin >> x;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid number: ";
        cin >> x;
    }
    return x;
}

void performOperation(char op, float a, float b) {
    switch (op) {
        case '+':
            cout << a << " + " << b << " = " << (a + b) << endl;
            break;
        case '-':
            cout << a << " - " << b << " = " << (a - b) << endl;
            break;
        case '*':
            cout << a << " * " << b << " = " << (a * b) << endl;
            break;
        case '/':
            if (b != 0) {
                cout << a << " / " << b << " = " << (a / b) << endl;
            } else {
                cout << "Error: Division by zero!" << endl;
            }
            break;
        case '^':
            cout << a << " ^ " << b << " = " << pow(a, b) << endl;
            break;
        default:
            cout << "Invalid operator." << endl;
    }
}

void performMatrixOperation() {
    cout << "Enter the size of the matrix (rows columns): ";
    int rows, cols;

    // Validate input for rows and columns
    cout << "Enter the number of rows: ";
    rows = inputInteger();

    cout << "Enter the number of columns: ";
    cols = inputInteger();

    vector<vector<float> > matrix1(rows, vector<float>(cols));
    vector<vector<float> > matrix2(rows, vector<float>(cols));

    cout << "Enter values for Matrix 1:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Enter value at position (" << i + 1 << ", " << j + 1 << "): ";
            matrix1[i][j] = input();
        }
    }

    cout << "Enter values for Matrix 2:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Enter value at position (" << i + 1 << ", " << j + 1 << "): ";
            matrix2[i][j] = input();
        }
    }

    char operation;
    cout << "Choose matrix operation (+ or -): ";
    cin >> operation;

    vector<vector<float> > result(rows, vector<float>(cols, 0));

    switch (operation) {
        case '+':
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    result[i][j] = matrix1[i][j] + matrix2[i][j];
                }
            }
            break;
        case '-':
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    result[i][j] = matrix1[i][j] - matrix2[i][j];
                }
            }
            break;
        default:
            cout << "Invalid matrix operation." << endl;
            return;
    }

    cout << "Resulting Matrix:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    char operation;
    cout << "Simple Calculator" << endl;

    while (true) {
        cout << "\nChoose operation ('+', '-', '*', '/', '^', 'm' for matrix, 'q' to quit): ";
        cin >> operation;

        if (operation == 'q') {
            cout << "Exiting the calculator." << endl;
            break;
        }

        if (operation == 'm') {
            performMatrixOperation();
        } else {
            cout << "Enter two numbers: ";
            float num1 = input();
            float num2 = input();

            performOperation(operation, num1, num2);
        }
    }

    return 0;
}
