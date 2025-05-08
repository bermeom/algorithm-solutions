# Python Program for Maximum Subarray Sum using Kadane's Algorithm
# Similar to https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
"""
Given an integer array nums, find the subarray with the largest squared sum, and return its sum.

Example 1:

Input: nums = [1,-1,-2,1,3]
Output: 16
Explanation: The subarray [1,3] has the largest sum 4.

Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.


"""
# Function to find the maximum subarray sum
def max_squared_subarray_sum(arr):
    
    res = arr[0]**2
    max_pos = 0
    max_neg = 0
    max_usgn = 0
    max_ending = 0

    for i in range(0, len(arr)):
        
        # Find the maximum sum ending at index i by either extending 
        # the maximum sum subarray ending at index i - 1 or by
        # starting a new subarray from index i
        max_pos += arr[i]
        
        max_neg += arr[i]
        
        max_usgn = max_pos if max_pos > -max_neg else max_neg
        
        max_ending = (max_ending + arr[i]) if abs(max_ending+arr[i]) > abs(max_usgn) else max_usgn
        
        if arr[i] < 0:
            max_pos = 0
        else:
            max_neg = 0
            
        # Update res if maximum subarray sum ending at index i > res
        print("--> ",i,arr[i],max_ending)
        res = max(res, max_ending**2)
    
    return res

arr = [1,-1,-2,1,3,-1,-1,-1,-1,-1,1,1,1,1,2]
print(max_squared_subarray_sum(arr))