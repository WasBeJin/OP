#include <iostream>
#include <vector>
#include <string>

class NQueens {
public:
    std::vector<std::vector<std::string> > solveNQueens(int n) {
        std::vector<std::vector<std::string> > result;
        std::vector<std::string> board(n, std::string(n, '.')); // Initialize empty chessboard

        solveNQueensRecursive(result, board, 0, n);

        return result;
    }

private:
    void solveNQueensRecursive(std::vector<std::vector<std::string> >& result,
                               std::vector<std::string>& board,
                               int row, int n) {
        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (isValid(board, row, col, n)) {
                board[row][col] = 'Q';
                solveNQueensRecursive(result, board, row + 1, n);
                board[row][col] = '.'; // Backtrack
            }
        }
    }

    bool isValid(const std::vector<std::string>& board, int row, int col, int n) {
        // Check if there is a queen in the same column
        for (int i = 0; i < row; ++i) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        // Check if there is a queen in the upper-left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        // Check if there is a queen in the upper-right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }
};

int main() {
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    NQueens solution;
    std::vector<std::vector<std::string> > result = solution.solveNQueens(n);

    // Output the solutions
    for (const auto& board : result) {
        for (const std::string& row : board) {
            std::cout << row << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}