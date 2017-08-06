#ifndef Soundex_h
#define Soundex_h

#include <string>
#include <unordered_map>

using namespace std;

static const size_t MAX_CODE_LENGTH{4};

class Soundex {
public:
    string encode(const string& word) const {
        return zeroPad(head(word) + encodedDigits(tail(word)));
    }

private:
    string head(const string& word) const {
        // Currently gets/returns first character in word.
        return word.substr(0, 1);
    }

    string tail(const string& word) const {
        return word.substr(1);
    }

    string encodedDigits(const string &word) const {
        string encoding;
        for (auto letter: word) { encoding += encodedDigit(letter); }
        return encoding;
    }

    string encodedDigit(char letter) const {
        const unordered_map<char, string> encodings {
                {'b', "1"}, {'f', "1"}, {'p', "1"}, {'v', "1"},
                {'c', "2"}, {'g', "2"}, {'j', "2"}, {'k', "2"}, {'q', "2"},
                            {'s', "2"}, {'x', "2"}, {'z', "2"},
                {'d', "3"}, {'t', "3"},
                {'l', "4"},
                {'m', "5"}, {'n', "5"},
                {'r', "6"}
        };
        auto it = encodings.find(letter);
        return it == encodings.end() ? "" : it->second;
    }

    string zeroPad(const string& word) const {
        auto zerosNeeded = MAX_CODE_LENGTH - word.length();
        return word + string(zerosNeeded, '0');
    }
};

#endif // Soundex_h