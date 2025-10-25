class Solution {
public:
    int totalMoney(int n) {
        int K = n/7;
        int F = 28;
        int L = 28 + (K-1) *7;
        int arithmetiSum = K* (F+L)/2;

        int monday = 1+K;
        int finalWeek =0;
        for(int day =0;day < n%7;day++){
            finalWeek += monday + day;
        }
        return arithmetiSum + finalWeek;
    }
};