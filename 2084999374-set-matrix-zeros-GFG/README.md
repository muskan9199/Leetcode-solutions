# [Set Matrix Zeros](https://www.geeksforgeeks.org/problems/set-matrix-zeroes/1)
## Medium
Given a 2D matrix mat[][] of size n x m. Modify the matrix such that if mat[i][j] is 0, all the elements in the i-th row and j-th column are set to 0.
Examples:
Input: mat[][] = [[1, -1, 1], [-1, 0, 1], [1, -1, 1]]&nbsp; &nbsp;&nbsp;
Output: [[1, 0, 1], [0, 0, 0], [1, 0, 1]]   
Explanation: mat[1][1] = 0, so all elements in row 1 and column 1 are updated to zeroes.
Input: mat[][] = [[0, 1, 2, 0], [1, 2, 6, 2], [1, 3, 1, 8]]&nbsp; &nbsp;  Output: [[0, 0, 0, 0], [0, 2, 6, 0], [0, 3, 1, 0]]&nbsp;&nbsp;Explanation: mat[0][0] and mat[0][3] are 0s, so all elements in row 0, column 0 and column 3 are updated to zeroes.
Constraints:1 ≤ n, m ≤ 500- 231 ≤ mat[i][j] ≤ 231 - 1