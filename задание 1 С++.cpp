#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int max_sum = INT_MIN;
        maxPathSumHelper(root, max_sum);
        return max_sum;
    }

private:
    int maxPathSumHelper(TreeNode* node, int& max_sum) {
        if (!node) {
            return 0;
        }

        // Recursively compute the maximum path sums in the left and right subtrees
        int left_max = max(0, maxPathSumHelper(node->left, max_sum));
        int right_max = max(0, maxPathSumHelper(node->right, max_sum));

        // Update the global maximum path sum
        max_sum = max(max_sum, left_max + right_max + node->val);

        // Return the maximum path sum starting from the current node
        return max(left_max, right_max) + node->val;
    }
};

// Function to build a binary tree based on user input
TreeNode* buildTree() {
    string value;
    cout << "Enter the value for the root (or type 'null' for a null node): ";
    cin >> value;

    if (value == "null") {
        return nullptr; // Null node
    }

    TreeNode* root = new TreeNode(stoi(value));
    cout << "Enter the left subtree for " << value << ":" << endl;
    root->left = buildTree();

    cout << "Enter the right subtree for " << value << ":" << endl;
    root->right = buildTree();

    return root;
}

// Function to free memory allocated for the tree nodes
void deleteTree(TreeNode* root) {
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

int main() {
    Solution solution;

    // Build the tree based on user input
    TreeNode* root = buildTree();

    int result = solution.maxPathSum(root);
    cout << "Maximum Path Sum: " << result << endl;

    // Free allocated memory for the tree nodes
    deleteTree(root);

    return 0;
}