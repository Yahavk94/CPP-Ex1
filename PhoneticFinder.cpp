#include <stdexcept>
#include <string>
#include <bits/stdc++.h>
#include "PhoneticFinder.hpp"

bool match = false;

struct MyException : public exception {
    const char* what() const throw() {
        return "did not find the word in the text";
    }
};

namespace phonetic {
    string find(const string text, const string word) {
        vector<string> tokens;
        stringstream check1(text);
        string intermediate;
        while (getline(check1, intermediate, ' ')) // Tokenizing a string
            tokens.push_back(intermediate);

        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i].length() == word.length()) check(tokens[i], word);
            if (match) {
                match = false;
                return tokens[i];
            }
        }

        throw MyException();
    }
};

void check(const string word1, const string word2) {
    if (word1 == " " | word2 == " ") return; // The empty string is an invalid statement

    for (int i = 0; i < word1.length(); i++) {
        if (!first(word1[i], word2[i])) return;
    }

    match = true; // Match found
}

bool first(const char word1, const char word2) {
    if (word1 == word2 | word1 == word2 + 32 | word1 == word2 - 32) return true;
    if (second(word1, word2)) return true;
    return false;
}

bool second(char word1, char word2) {
    if (word1 <= 90) word1 += 32;
    if (word2 <= 90) word2 += 32;
    if ((word1 == 'v' | word1 == 'w') & (word2 == 'v' | word2 == 'w')) return true;
    else if ((word1 == 'g' | word1 == 'j') & (word2 == 'g' | word2 == 'j')) return true;
    else if ((word1 == 's' | word1 == 'z') & (word2 == 's' | word2 == 'z')) return true;
    else if ((word1 == 'd' | word1 == 't') & (word2 == 'd' | word2 == 't')) return true;
    else if ((word1 == 'o' | word1 == 'u') & (word2 == 'o' | word2 == 'u')) return true;
    else if ((word1 == 'i' | word1 == 'y') & (word2 == 'i' | word2 == 'y')) return true;
    else if ((word1 == 'b' | word1 == 'f' | word1 == 'p') & (word2 == 'b' | word2 == 'f' | word2 == 'p')) return true;
    else if ((word1 == 'c' | word1 == 'k' | word1 == 'q') & (word2 == 'c' | word2 == 'k' | word2 == 'q')) return true;
    return false;
}
