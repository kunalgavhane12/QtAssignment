#include <iostream>
#include <string.h>

using namespace std;
void reverse(char *p, char *q)
{
    while(p<q)
    {
        char temp = *p;
        *p = *q;
        *q = temp;
        p++;
        q--;
    }

}

void wordReverse(char *str)
{
    char *word = str;
    char *temp = str;

    while(*temp)
    {
        temp++;
        if(*temp == '\0')
        {
            reverse(word, temp-1);
        }
        else if(*temp == ' ')
        {
            reverse(word, temp - 1);
            word = temp + 1;
        }
    }
    reverse(str,temp-1);
}

int main()
{
    char str[80];
    cout<<"Enter string : ";
    cin.getline(str,80);
    wordReverse(str);
    cout << str;
}