#include "solution.h"

bool Solution::isAlternating(const string& s) {
    for(size_t i = 0; i < s.length() - 1; i++){
        if(s.at(i) == s.at(i+1)) {
            return false;
        }
    }
    return true;
}

int Solution::minFlips(string s) {

    if(isAlternating(s)) {
        return 0;
    }

    int countOfZeroOdd = 0;
    int countOfOneOdd = 0;
    int countOfZeroEven = 0;
    int countOfOneEven = 0;

    for(size_t i = 0; i < s.length(); i++) {
        if(s.at(i) == '0') {
            if(i % 2 == 0) {
                countOfZeroEven++;
            } else {
                countOfZeroOdd++;
            }
        } else {
            if(i % 2 == 0) {
                countOfOneEven++;
            } else {
                countOfOneOdd++;
            }
        }
    }

    if(s.length() % 2 == 0) {
        return std::min(countOfZeroEven + countOfOneOdd, countOfOneEven + countOfZeroOdd);
    }

    int minRet = INT32_MAX;
    for(size_t i = 0; i < s.length(); i++) {
        int minNew = 0;
        if(countOfZeroEven + countOfOneOdd < countOfOneEven + countOfZeroOdd) {
            minNew = countOfZeroEven + countOfOneOdd;
        } else {
            minNew = countOfOneEven + countOfZeroOdd;
        }

        minRet = std::min(minRet, minNew);

        if(i % 2 != 0) {
            if(s.at(i) == '0') {
                countOfZeroOdd--;
                countOfZeroEven++;
            } else {
                countOfOneOdd--;
                countOfOneEven++;
            }
        } else {
            if(s.at(i) == '0') {
                countOfZeroEven--;
                countOfZeroOdd++;
            } else {
                countOfOneEven--;
                countOfOneOdd++; 
            }
        }
    }
    return minRet;
}
