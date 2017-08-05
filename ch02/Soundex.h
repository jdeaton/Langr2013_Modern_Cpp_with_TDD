#ifndef Soundex_h
#define Soundex_h

#include <string>

using namespace std;

class Soundex {
public:
    string encode(const string& word) const {
        return zeroPad(head(word) + encodedDigits(word));
    }

private:
    string head(const string& word) const {
        // Currently gets/returns first character in word.
        return word.substr(0, 1);
    }

    string encodedDigits(const string &word) const {
        if (word.length() > 1) return "1";
        return "";
    }

    string zeroPad(const string& word) const {
        auto zerosNeeded = 4 - word.length();
        return word + string(zerosNeeded, '0');
    }
};

#endif // Soundex_h