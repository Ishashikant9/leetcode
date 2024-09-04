#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        char letters[26] = {};
        for(auto c : words[0]) {
            letters[c - 'a']++;
        }

        char aux[26] = {};
        for(int i = 1; i < words.size(); i++) {
            for(auto c : words[i]) {
                if(letters[c - 'a'] == 0)
                    continue;
                
                aux[c - 'a']++;
            }

            for(int i = 0; i < 26; i++) {
                letters[i] = min(aux[i], letters[i]);
                aux[i] = 0;
            }
        }

        vector<string> output;
        for(int i = 0; i < 26; i++) {
            while(letters[i]) {
                string str;
                str += i + 'a';
                output.push_back(str);
                letters[i]--;
            }
        }

        return output;
    }
};

int main() {
    Solution sol;
    vector<string> words = {"bella", "label", "roller"};
    vector<string> result = sol.commonChars(words);
    for (auto &str : result) {
        cout << str << " ";
    }
    cout << endl;
    return 0;
}
