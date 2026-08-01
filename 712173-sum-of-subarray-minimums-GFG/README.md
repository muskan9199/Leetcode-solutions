# [Sum of subarray minimums](https://www.geeksforgeeks.org/problems/sum-of-subarray-minimum/1)
## Medium
Given an array arr[] of positive integers, find the total sum of the minimum elements of every possible subarrays.
Note: It is guaranteed that the total sum will fit within a 32-bit&nbsp;unsigned integer.
Examples:
Input: arr[] = [10, 20]Output: 40Explanation: Subarrays are [10], [20], [10, 20]. Minimums are 10, 20, 10.Sum of all these is 40.
Input: arr[] = [1, 2, 3, 4]Output: 20Explanation: Subarrays are [1], [2], [3], [4], [1, 2], [1, 2, 3], [1, 2, 3, 4], [2, 3], [2, 3, 4], [3, 4]. Minimums are 1, 2, 3, 4, 1, 1, 1, 2, 2, 3.
Sum of all these is 20.
Constraints:1 ≤ arr.size() ≤ 3*1041 ≤ arr[i]&nbsp;≤ 103