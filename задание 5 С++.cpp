#include <iostream>
#include <vector>
#include <stack>

int maximalRectangleArea(const std::vector<std::vector<char> >& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
        return 0;
    }

    int rows = matrix.size();
    int cols = matrix[0].size();
    std::vector<int> heights(cols, 0);
    int maxArea = 0;

    for (int i = 0; i < rows; ++i) {
        // Update heights based on the current row
        for (int j = 0; j < cols; ++j) {
            heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
        }

        // Calculate the maximum rectangle area for the current row
        std::stack<int> s;
        for (int j = 0; j <= cols; ++j) {
            while (!s.empty() && (j == cols || heights[j] < heights[s.top()])) {
                int height = heights[s.top()];
                s.pop();
                int width = s.empty() ? j : j - s.top() - 1;
                maxArea = std::max(maxArea, height * width);
            }
            s.push(j);
        }
    }

    return maxArea;
}

int main() {
    int rows, cols;
    std::cout << "Enter the number of rows: ";
    std::cin >> rows;
    std::cout << "Enter the number of columns: ";
    std::cin >> cols;

    std::vector<std::vector<char> > matrix(rows, std::vector<char>(cols));
    std::cout << "Enter the matrix (0 or 1):" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    int result = maximalRectangleArea(matrix);
    std::cout << "The maximum rectangle area containing only 1's is: " << result << std::endl;

    return 0;
}