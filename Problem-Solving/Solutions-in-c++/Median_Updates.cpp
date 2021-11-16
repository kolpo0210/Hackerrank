#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <iomanip>
#include <set>

using namespace std;
multiset<int> max1, min1;

void printAnswer()
{
    if (max1.size() > min1.size() + 1)
    {
        min1.insert(*max1.rbegin());
        max1.erase(max1.find(*max1.rbegin()));
    }
    else if (min1.size() > max1.size() + 1)
    {
        max1.insert(*min1.begin());
        min1.erase(min1.begin());
    }

    if (max1.empty() && min1.empty())
    {
        cout << "Wrong!" << endl;
        return;
    }
    if (max1.size() == min1.size())
    {
        int a = *max1.rbegin();
        int b = *min1.begin();
        double medn;
        medn = (a * 1.0 + b * 1.0) / 2.0;
        string str = to_string(medn);
        size_t found = str.find(".");
        if (str[found + 1] == '0')
        {
            str.erase(str.begin() + found, str.end());
        }
        else
        {
            str.erase(str.begin() + found + 2, str.end());
        }
        cout << str << endl;
        return;
    }
    else if (max1.size() > min1.size())
    {
        cout << *max1.rbegin() << endl;
        return;
    }
    else if (min1.size() > max1.size())
    {
        cout << *min1.begin() << endl;
        return;
    }
    return;
}

void median(vector<char> s, vector<int> x, int n)
{
    for (int i = 0; i < n; i++)
    {

        if (s[i] == 'a')
        {
            if (max1.empty() || *max1.rbegin() > x[i])
            {
                max1.insert(x[i]);
            }
            else
            {
                min1.insert(x[i]);
            }
            if (max1.size() > min1.size() + 1)
            {
                min1.insert(*max1.rbegin());
                max1.erase(max1.find(*max1.rbegin()));
            }
            else if (min1.size() > max1.size() + 1)
            {
                max1.insert(*min1.begin());
                min1.erase(min1.begin());
            }
            printAnswer();
        }
        else
        {
            multiset<int>::iterator itr1 = max1.find(x[i]), itr2 = min1.find(x[i]);

            if (itr1 == max1.end() && itr2 == min1.end())
            {
                cout << "Wrong!" << endl;
            }
            else
            {
                if (itr1 != max1.end())
                {
                    max1.erase(itr1);
                }
                else
                {
                    min1.erase(itr2);
                }
                printAnswer();
            }
        }
    }
}

int main(void)
{
    int n;
    cin >> n;
    vector<char> s;
    vector<int> x;
    char temp;
    int tempint;
    for (int i = 0; i < n; i++)
    {
        cin >> temp >> tempint;
        s.push_back(temp);
        x.push_back(tempint);
    }
    median(s, x, n);
    return 0;
}
