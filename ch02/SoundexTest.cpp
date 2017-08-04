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

TEST(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
    Soundex soundex;
    auto encoded = soundex.encode("A");
    ASSERT_THAT(encoded, Eq("A000"));
}

TEST(SoundexEncoding, PadsWithZerosToEnsureThreeDigits) {
    Soundex soundex;

    auto encoded = soundex.encode("I");

    ASSERT_THAT(encoded, Eq("I000"));
}