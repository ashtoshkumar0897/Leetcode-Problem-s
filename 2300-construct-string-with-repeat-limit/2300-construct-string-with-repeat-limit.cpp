class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<char> blacks{};
        unordered_map<char,int> diction;
        
        string answer{};
        int count = 0;
        int i = 0;
        for(char st:s){
            if(diction.find(st) == diction.end()){
                diction[st] = 1;
                blacks.push_back(st);
            }
            else{
                ++diction[st];
            }

        }
        sort(blacks.begin(),blacks.end(),greater<char>());
        const int sizer = blacks.size();
        while(i<sizer){
            if(diction[blacks[i]]==0){
                ++i;
                count = 0;
                continue;
            }
            if(count<repeatLimit){
            --diction[blacks[i]];
            answer+=blacks[i];
            ++count;
            }
            else{
                int j=i+1;
                while(true){
                    if(j>=sizer){
                        return answer;
                    }
                    if(diction[blacks[j]] != 0){
                        
                        answer+=blacks[j];
                        --diction[blacks[j]];
                        break;
                    }
                    ++j;
                }
                count = 0;
            }

        }
        return answer;
    }
};