"""
Given an array arr of length N, determine the minimum number of operations required 
to convert it into a permutation array, i.e., one that contains only values from 1 
to N in any order.

Each operation consists of incrementing or decrementing any value in the array by one.
Example 1:

Input: nums = [2,3,4,5]
Output: 4
Explanation: Subtract 1 from each element or subtract 4 from 5, both are valid 
solutions.

1 < nums.length < 10^5
-10^5 < nums[i] < 10^5
Reference: 
- https://www.geeksforgeeks.org/minimum-steps-to-convert-an-array-into-permutation-of-numbers-from-1-to-n/
"""


# Python3 program to find minimum number of steps to
# convert a given sequence into a permutation
 
# Function to find minimum number of steps to
# convert a given sequence into a permutation
def get_permutation(arr):
 
    # Sort the given array
    arr = sorted(arr)
 
    # To store the required minimum
    # number of operations
    result = 0
 
    # Find the operations on each step
    for i in range(len(arr)):
        result += abs(arr[i] - (i + 1))
 
    # Return the answer
    return result
 
# Driver code
if __name__ == '__main__':
    arr=[0, 2, 3, 4, 1, 6, 8, 9]
    
    # Function call
    print(get_permutation(arr, n))