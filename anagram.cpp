#include "anagram.h"
#include <string> 
#include <cstring> 
#include <algorithm>
#include <vector> 
const std::vector<std::string>& areAnagram = {};
bool Anagram::WordPairIsAnagram(const std::string& word1, const std::string& word2)
{
    int word1Length = word1.length();
    int word2Length = word2.length();
    if (word1Length != word2Length)
    {
        return false;
    }
    else {
        sort(word1.begin(), word1.end());
        sort(word2.begin(), word2.end());
        for (int i = 0; i < word1Length; i++)
            if (word1[i] != word2[i])
                return false;
        return true;
    }
       
}

std::vector<std::string> Anagram::SelectAnagrams(
    const std::string& word,
    const std::vector<std::string>& candidates) 
{
   
    for (int i = 0; i < candidates.size(); i++)
    {
        
        int word1Length = word.length();
        int word2Length = candidates[i].length();
        if (word1Length != word2Length)
            break;
        else
            sort(word.begin(), word.end());
            sort(candidates[i].begin(), candidates[i].end());
            const std::string& s=candidates[i];
            for (int i = 0; i < word1Length; i++)
                if (word[i] != s[i])
                    break;
            const std::vector<std::string>& areAnagram = { s };


    }
   
    return areAnagram;
}
