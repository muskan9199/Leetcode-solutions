# [Prefix to Postfix Conversion](https://www.geeksforgeeks.org/problems/prefix-to-postfix-conversion/1)
## Medium
You are given a string s that represents the prefix form of a valid mathematical expression. Convert it to its postfix form.
Examples:
Input: s = "+AB"Output: "AB+"Explanation: In postfix form, operands come first followed by operator.Prefix to Infix: +AB becomes A + BInfix to Postfix: A + B becomes AB+
Input: s = "*+ABC"Output: AB+C*Explanation: Prefix to Infix: *+ABC becomes (A + B)*CInfix to Postfix: (A + B)*C becomes AB+C* 
Input: s = "*-A/BC-/AKL"
Output: "ABC/-AK/L-*"
Explanation:Prefix to infix: *-A/BC-/AKL becomes (A - (B / C)) * ((A / K) - L)
Convert left part to Postfix: (A - (B / C)) becomes ABC/-
Convert right part to Postfix: ((A / K) - L) becomes AK/L-
Combine both with * to get ABC/-AK/L-*

Constraints:3 ≤ s.size() ≤ 100