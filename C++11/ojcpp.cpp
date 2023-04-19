#include <iostream>
#include <string>
using namespace std;


    void Sub(string& s) {
        string tmp = "";

        for (auto& e : s) {
            if (e != ' ') {
                tmp += e;
            }
            else if (e == ' ' && !tmp.empty()) {
                tmp += e;
            }
        }
        for (int i = tmp.size() - 1; i >= 0; --i) {
            if (tmp[i] == ' ') {
                tmp.pop_back();
            }
            else {
                break;
            }
        }
        s = tmp;
    }
    bool isNumber(string s) {
        int cntPlusMinus = 0;
        int cntDot = 0;
        int cntEe = 0;
        Sub(s);
        if (s.empty()) return false;
        cout << s << endl;
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
                    //有，则第一个位置，第二个如果有则在e/E之后
                    if (i != 0 && ((s[i - 1] != 'e' && s[i - 1] != 'E') || (i + 1 == s.size() || !isdigit(s[i + 1])))) {
                        return false;
                    }
                    //其后必为整数，否则false
                    if (i + 1 == s.size() || !isdigit(s[i + 1]) && s[i + 1] != '.') {
                        return false;
                    }
                    //-.
                    if (i + 1 == s.size() - 1 && s[i + 1] == '.')
                    {
                        return false;
                    }
                    //有，则只能有一个,在e存在时只能有两
                    ++cntPlusMinus;
                    if (cntPlusMinus > 1 && cntEe == 0) {
                        return false;
                    }
                }
                else if (s[i] == 'e' || s[i] == 'E') {
                    //其前及其后必为整数，否则false
                    if (i - 1 < 0 || !isdigit(s[i - 1])
                        && i + 1 == s.size() || (!isdigit(s[i + 1]) && s[i + 1] != '+' && s[i + 1] != '-')) {
                        return false;
                    }
                    //.e1
                    if (s[i - 1] == '.' && i - 1 == 0) {
                        return false;
                    }
                    ++cntEe;
                    //有，则只能有一个
                    if (cntEe > 1) {
                        return false;
                    }
                }
                else if (s[i] == '.') {
                    //"6e6.5"
                    if (cntDot == 0 && cntEe == 1) {
                        return false;
                    }
                    //其前如果存在必为整数，其后如果存在必为整数，否则false             
                    if (i == 0 && i == s.size() - 1) {
                        return false;
                    }
                    if (i != 0 && !isdigit(s[i - 1]) && s[i - 1] != '-' && s[i - 1] != '+') {
                        return false;
                    }
                    if (i != s.size() - 1
                        && !isdigit(s[i + 1])
                        && s[i + 1] != 'e' && s[i + 1] != 'E') {
                        return false;
                    }
                    ++cntDot;
                    //有，则只能有一个
                    if (cntDot > 1) {
                        return false;
                    }
                }
            }
        }
        return true;
    }


//int main() {
//    string s("46.e3");
//    bool ret = isNumber(s);
//    cout << ret << endl;
//    return 0;
//}


#include <stdio.h>
#define N 100
        

        
int main() {
    printf("%d\n", N);
    //printf("%d\n", N);
    //printf("%d\n", N);
    //printf("%d\n", N);
    //printf("%d\n", N);
    //printf("%d\n", N);
    //printf("%d\n", N);
    //printf("%d\n", N);
    //printf("%d\n", N);
    printf("%d\n", N);
    printf("%d\n", N);
    
#ifdef __FLAG__
    printf("__FLAG__\n");
#else
    printf("__DEFAULT__\n");
#endif

    return 0;
        
}

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
//二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表
class Solution {
public:
    void get(Node* cur, Node*& prev) {
        if (cur == nullptr) return;
        get(cur->left, prev);

        cout << cur->val << ":";
        if (prev) cout << prev->val << endl;
        else cout << nullptr << endl;
        if (prev == nullptr) {
            cur->left = prev;
        }
        else {
            cur->left = prev;
            prev->right = cur;
        }
        prev = cur;

        get(cur->right, prev);
    }
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr) return nullptr;
        Node* head = root;
        while (head->left != nullptr) {
            head = head->left;
        }
        Node* tail = root;
        while (tail->right != nullptr) {
            tail = tail->right;
        }
        Node* prev = nullptr;
        get(root, prev);
        head->left = tail;
        tail->right = head;
        return head;
    }
};

//数组中数字出现的次数
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> m;
        for (auto& e : nums) {
            m[e]++;
        }
        int ret = nums[0];
        for (auto& e : m) {
            if (e.second == 1) {
                ret = e.first;
            }
        }
        return ret;
    }
};
//数组中数字出现的次数
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        //

        //not equair bit
        int sum = 0;
        for (auto& e : nums) {
            sum ^= e;
        }
        int i = 1;
        while ((sum & i) == 0) {
            i <<= 1;
        }
        //set groop
        vector<int> ret(2, 0);
        ret[0] = 0;
        ret[1] = 0;
        for (auto& e : nums) {
            if ((e & i) == 0) {
                ret[0] ^= e;
            }
            else {
                ret[1] ^= e;
            }
        }
        //search and two groop
        return ret;
    }
};
