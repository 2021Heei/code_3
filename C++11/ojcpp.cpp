#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
    void Sub(string& s) {
        string tmp;
        for (auto& e : s) {
            if (e != ' ') {
                tmp += e;
            }
            else if (e == ' ' && !tmp.empty()) {
                tmp += e;
            }
        }
        s = tmp;
    }
    bool isNumber(string s) {
        int cntPlusMinus = 0;
        int cntDot = 0;
        int cntEe = 0;
        char prev = '\0';
        Sub(s);
        for (int i = 0; i < s.size(); ++i) {
            if (!isdigit(s[i])
                && s[i] != '+'
                && s[i] != '-'
                && s[i] != 'e'
                && s[i] != 'E'
                && s[i] != '.'
                || s[i] == ' ') {
                return false;
            }
            else {
                if (s[i] == '+' || s[i] == '-') {
                    //有，则第一个位置
                    if (s[i] != s[0]) {
                        return false;
                    }
                    //有，则只能有一个
                    ++cntPlusMinus;
                    if (cntPlusMinus > 1) {
                        return false;
                    }
                }
                else if (s[i] == 'e' || s[i] == 'E') {
                    ++cntEe;
                    if (cntEe > 1) {
                        return false;
                    }
                }
                else if (s[i] == '.') {
                    ++cntDot;
                    if (cntDot > 1) {
                        return false;
                    }
                }
                prev = s[i];
            }
        }
        return true;
    }
};