class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstRow = false, firstCol = false;

        int rows = matrix.size();
        int cols = matrix[0].size();

        // Step 1: Mark zeros in first row/col
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    if (i == 0) firstRow = true;
                    if (j == 0) firstCol = true;
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        // Step 2: Use markers to set zeroes
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Step 3: Handle first row
        if (firstRow) {
            for (int j = 0; j < cols; j++) {
                matrix[0][j] = 0;
            }
        }

        // Step 4: Handle first column
        if (firstCol) {
            for (int i = 0; i < rows; i++) {  // ✅ fixed i++
                matrix[i][0] = 0;
            }
        }
    }
};
