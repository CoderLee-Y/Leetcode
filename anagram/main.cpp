//edited on: 11 月 22 日 2020
//edited by LEE
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int charmap[2][30];
        memset(charmap, 0, sizeof(charmap));
        for (int i = 0; i < s.length(); ++i)
            charmap[0][s[i] - 'a']++;
        for (int i = 0; i < t.length(); i++)
        {
            charmap[1][t[i] - 'a']++;
        }
        for (int i = 0; i < 26; ++i)
            if (charmap[0][i] != charmap[1][i])
                return false;
        return true;
    }
};

int main()
{
    return 0;
}