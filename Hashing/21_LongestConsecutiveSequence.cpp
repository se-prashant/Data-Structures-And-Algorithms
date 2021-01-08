class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mp;
        for(int i:nums){
            mp.insert(i);
        }
        int max_ = 0;
        for(int i:nums){
            if(mp.find(i-1)==mp.end()){
                int curNo =i+1;
                int count = 1;
                while(mp.find(curNo)!=mp.end()){
                    curNo+=1;
                    count++;
                }
                max_ = max(max_,count);
            }
                
        }
        return max_;
    }
};
