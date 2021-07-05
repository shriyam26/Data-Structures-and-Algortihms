class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(denominator == 0) return " ";
        if(numerator == 0) return "0";
        string res;
        unordered_map<long, int> mp;
        int sign = 1;
        long quo = abs(long(numerator)/long(denominator));
        if((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0)){
            sign = -1;
            res = res + "-";
        }
        res = res + to_string(quo);
        long rem = abs(long(numerator)%long(denominator));
        if(rem == 0) return res;
        res = res + ".";
        while(rem){
            mp[rem] = res.length();
            rem = rem *10;
            res = res + to_string(abs(long(rem) / long(denominator)));
            rem = abs(long(rem) % long(denominator));
            if(mp.find(rem) != mp.end()){
                res.insert(mp[rem], "(");
                res = res + ")";
                break;
            }
        }
        return res;
    }
};