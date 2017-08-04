#include <gmock/gmock.h>

using std::string;
using testing::Eq;

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

class SoundexEncoding: public testing::Test {
public:
    Soundex soundex;
};

TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
    auto encoded = soundex.encode("A");
    ASSERT_THAT(encoded, Eq("A000"));
}

TEST_F(SoundexEncoding, PadsWithZerosToEnsureThreeDigits) {
    auto encoded = soundex.encode("I");
    ASSERT_THAT(encoded, Eq("I000"));
}