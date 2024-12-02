class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int i = -1, wordIdx = 0;
        do {
            ++i, ++wordIdx;
            if(sentence.substr(i, searchWord.size()) == searchWord) return wordIdx;
        }while((i = sentence.find(' ', i)) != string::npos);
        return -1;
    }
};