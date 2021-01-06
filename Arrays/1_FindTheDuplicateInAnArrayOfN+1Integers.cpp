//Floyd's Tortoise and Hare Algo
//https://leetcode.com/problems/find-the-duplicate-number/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int tortoise = nums[0];
        int hare = nums[0];
        do{
            hare = nums[nums[hare]];
            tortoise = nums[tortoise];
        }while(tortoise !=hare);
        tortoise = nums[0];
        while(tortoise!=hare){
            hare = nums[hare];
            tortoise = nums[tortoise];
        }
        return hare;
    }
};
