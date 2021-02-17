//edited on: 11 月 22 日 2020
//edited by LEE
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    string intToRoman(int num)
    {
        string myans;
        queue<string> ans;
        int a[] = {1,
                   4,
                   5,
                   9,
                   10,
                   40,
                   50,
                   90,
                   100,
                   400,
                   500,
                   900,
                   1000};
        string b[] = {
            "I",
            "IV",
            "V",
            "IX",
            "X",
            "XL",
            "L",
            "XC",
            "C",
            "CD",
            "D",
            "CM",
            "M"};
        for (int i = 12; i >= 0; --i)
        {
            while (num - a[i] >= 0)
            {
                num -= a[i];
                ans.push(b[i]);
            }
        }
        while (!ans.empty())
        {
            myans.append(ans.front());
            ans.pop();
        }
        return myans;
    }
};

int main()
{
    Solution m;
    int k;
    cin >> k;
    cout << m.intToRoman(k);
}