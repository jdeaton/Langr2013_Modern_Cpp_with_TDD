#ifndef Soundex_h
#define Soundex_h

#include <string>
#include <unordered_map>

using namespace std;

static const size_t MAX_CODE_LENGTH{4};

class Soundex {
public:
    string encode(const string& word) const {
        return zeroPad(upperFront(head(word)) + tail(encodedDigits(word)));
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
        auto it = encodings.find(lower(letter));
        return it == encodings.end() ? _NOT_A_DIGIT : it->second;
    }

private:
    const string _NOT_A_DIGIT{"*"};

    string head(const string& word) const {
        return word.substr(0, 1);
    }

    string tail(const string& word) const {
        return word.substr(1);
    }

    string upperFront(const string& phrase) const {
        return string(1, toupper(static_cast<unsigned char>(phrase.front())));
    }

    char lower(char c) const {
        return static_cast<unsigned char>(tolower(static_cast<unsigned char>(c)));
    }

    string encodedDigits(const string &word) const {
        string encoding;

        encoding += encodedDigit(word.front());

        for (auto letter: tail(word)) {
            if (isComplete(encoding)) { break; }

            auto digit = encodedDigit(letter);
            if (digit != _NOT_A_DIGIT && digit != lastDigit(encoding)) {
                encoding += digit;
            }
         }
        return encoding;
    }

    string lastDigit(const string &encoding) const {
        if (encoding.empty()) { return _NOT_A_DIGIT; }
        return string(1, encoding.back());
    }

    bool isComplete(const string& encoding) const {
        return encoding.length() == MAX_CODE_LENGTH;
    }

    string zeroPad(const string& word) const {
        auto zerosNeeded = MAX_CODE_LENGTH - word.length();
        return word + string(zerosNeeded, '0');
    }
};

#endif // Soundex_h