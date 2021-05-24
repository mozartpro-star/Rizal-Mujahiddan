#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <map>
using namespace std;

class bank
{
private:
    map<string, int> aku;

public:
    void masukkan(string pid)
    {
        if (aku.count(pid) == 0)
        {
            aku.insert(pair<string, int>(pid, 1));
        }
        else
        {
            aku[pid]++;
        }
    }
    void printkan()
    {
        map<string, int>::iterator it = aku.begin();
        while (it != aku.end())
        {
            string tulis = it->first;
            int count = it->second;
            cout << tulis << " " << count << "\n";
        }
    }
};

int main()
{
    int i, masuk, dimasuk, j;
    string tulis;
    cin >> masuk;
    for (i = 0; i < masuk; i++)
    {
        cin >> dimasuk;
        bank pem;
        for (j = 0; j < dimasuk; j++)
        {
            getline(cin, tulis);
            pem.masukkan(tulis);
        }
        pem.printkan();
    }
}