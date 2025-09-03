#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    //string input = "zkrpabcadaghepuhenoq";
    string input = "alali";

    string longestSubStr, currentSubStr;
    unordered_map<char, int> map;

    for(int i=0; i<input.length(); i++) {
        char currentChar = input[i];
        bool currentCharFoundInMap = map.find(currentChar) != map.end();

        if(currentCharFoundInMap) {

            if(currentSubStr.length() > longestSubStr.length())
                longestSubStr = currentSubStr;
            
            int currentCharIndex = map.at(currentChar);
            currentSubStr = input.substr(currentCharIndex+1, i-currentCharIndex);

            map.clear();
            map[currentChar] = i;

        } else {
            map[currentChar] = i;
            currentSubStr.append(1, input[i]);
        }
    }

    longestSubStr = currentSubStr.length() > longestSubStr.length ()
                    ? currentSubStr : longestSubStr;


    cout << longestSubStr << endl;
    return 0;
}