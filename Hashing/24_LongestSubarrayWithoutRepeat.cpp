class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int> mp;
        int ans = 0;
        int temp = 0;
        for(int i=0;i<s.size();i++){
            if(mp.count(s[i])==0){
             temp++;
             mp[s[i]] = i;
            }else{
                int startPos = i-temp;
                if(startPos>mp[s[i]]){
                    temp++;
                    mp[s[i]] = i;
                   
                }else{
                    
                   ans= max(ans,temp);
                   temp -= (mp[s[i]]-startPos+1);
                   temp++;
                    mp[s[i]] = i;
                }
            }
                
        }
        ans = max(ans,temp);
        return ans;
            
    }
};
