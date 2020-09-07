#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "anagram.h"


TEST_CASE("recognizes shuffled alphabets as anagrams")
{
    REQUIRE(Anagram::WordPairIsAnagram("restful", "fluster") == true);
    REQUIRE(Anagram::WordPairIsAnagram("forty five", "over fifty") == true);
}

TEST_CASE("reports identical words as non-anagrams")
{
    REQUIRE(Anagram::WordPairIsAnagram("anagrams", "anAGrams") == false);
    REQUIRE(Anagram::WordPairIsAnagram("forty five", "forty five") == false);
}


TEST_CASE("reports completely different word of same/different length with base word as non-anagrams")
{
    REQUIRE(Anagram::WordPairIsAnagram("anAGram", "nanDini") == false);
    REQUIRE(Anagram::WordPairIsAnagram("anagram", "rAj nandini") == false);
}

TEST_CASE("reports for shortest non-anagrams containing only one character")
{
    REQUIRE(Anagram::WordPairIsAnagram("a", "A") == false);
}


TEST_CASE("reports for shortest anagrams containing only two characters")
{
    REQUIRE(Anagram::WordPairIsAnagram("No", "On") == true);
}


TEST_CASE("reports non-anagrams") 
{
    REQUIRE(Anagram::WordPairIsAnagram("something", "else") == false);
}

TEST_CASE("recognizes anagrams when there are case- and space- differences") {
    REQUIRE(Anagram::WordPairIsAnagram("New York Times", "monkeys write")
        == true);
}

TEST_CASE("selects anagrams of a word from given vector") {
    auto selection = Anagram::SelectAnagrams("master",
        { "stream", "something", "maters" });
    REQUIRE(selection == std::vector<std::string>{"stream", "maters"});
}

TEST_CASE("reports if no angram word found from given vector") {
    auto selection = Anagram::SelectAnagrams("master",
        { "vampire DiaRies","Dragontales", "stuard Little", "abc" ,"D"});
    REQUIRE(selection == std::vector<std::string>{});
}
