"""
    46. Permutations
    Author: Miguel Angel Bermeo Ayerbe
"""
import copy

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        def perm(nums: List[int], index: int, ans: List[List[int]]) -> None: 
            if index == len(nums):
                ans.append(copy.deepcopy(nums))
            else:
                for i in range(index,len(nums)):
                    nums[i], nums[index] = nums[index], nums[i]
                    perm(nums, index+1, ans)
                    nums[i], nums[index] = nums[index], nums[i]
        ans: List[List[int]] = []
        perm(nums,0,ans)
        return ans