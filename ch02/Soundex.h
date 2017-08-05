#ifndef Soundex_h
#define Soundex_h

#include <string>

using namespace std;

class Soundex {
public:
    string encode(const string& word) const {
        return zeroPad(word);
    }

private:
    string zeroPad(const string& word) const {
        return word + "000";
    }
};

#endif // Soundex_h
