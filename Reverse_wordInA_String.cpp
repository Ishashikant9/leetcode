#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    void reverseWords(int i, int j, string &s){
        while(i < j){
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }

    string reverseWords(string s) {
        int i = 0; 
        int j = 0;
        while(s[j+1] != '\0'){
            if(s[j+1] == ' ' && s[j+2] != '\0'){
                reverseWords(i, j, s);
                i = j = j+2;
                continue;
            }
            j++; 
        }
        reverseWords(i, j, s);
        return s;
    }
};

int main() {
    Solution sol;
    string s = "hello world";
    cout << sol.reverseWords(s) << endl;
    return 0;
}


