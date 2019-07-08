/*
Single Character Pyramid 
*/

#include <iostream>
#include <cstring>
using namespace std;

void printHelper(string str, int to)
{
    static int count = 0;
    if(count <= to)
    {
        cout << str[count];
        count++;
        printHelper(str, to);
    }
    count = 0;
}

void print(string str)
{
    static int count = 0; 
    static int len = str.length();
    if(count < len)
    {
        printHelper(str, count);
        cout << endl;
        count++;
        print(str);
    }
    
    
}

int main()
{
    string str;
    cou << "Enter a string: " << endl;
    cin >> str;
    print(str);
    return 0;
}
