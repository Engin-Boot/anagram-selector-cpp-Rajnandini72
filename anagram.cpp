#include "anagram.h"
#include <string>  
#include <cctype>
#include <vector> 
#include <bits/stdc++.h>
#include<algorithm>

bool Anagram::WordPairIsAnagram(const std::string& word1, const std::string& word2)
{
    std::string word1Sorted=word1;
    std::string word2Sorted=word2;
    word1Sorted.erase(std::remove_if(word1Sorted.begin(), word1Sorted.end(), ::isspace), word1Sorted.end());
    word2Sorted.erase(std::remove_if(word2Sorted.begin(), word2Sorted.end(), ::isspace), word2Sorted.end());
    int word1Length = word1Sorted.size();
    int word2Length = word2Sorted.size();
    transform(word1Sorted.begin(), word1Sorted.end(), word1Sorted.begin(), ::tolower);
    transform(word2Sorted.begin(), word2Sorted.end(), word2Sorted.begin(), ::tolower);
    if (word1Sorted.compare(word2Sorted) == 0)
        return false;
    else if (word1Length == word2Length)
    {
        if (word1Length == 1)
            return false;
        std::sort(word1Sorted.begin(), word1Sorted.end());
        std::sort(word2Sorted.begin(), word2Sorted.end());
       
        if (word1Sorted.compare(word2Sorted) == 0)
            return true;
        return false;
        
    }
    return false;
}

std::vector<std::string> Anagram::SelectAnagrams(
    const std::string& word,
    const std::vector<std::string>& candidates)
{
    //Fill the correct implementation here
    std::vector<std::string> areAnagrams = {};
    for (unsigned int i = 0; i < candidates.size(); i++)
    {
        if(WordPairIsAnagram(word,candidates[i]))
            areAnagrams.push_back(candidates[i]);
        
    }
    return areAnagrams;
}


