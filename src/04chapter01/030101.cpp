#include <iostream>
#include <string.h>
// #include <cstring>
// 输入一个字符串，把其中的单词输出出来，单词用一个空格隔开的
// "abc def ghi "
using namespace std;

int main() {
    char str[100];
    gets(str);
    int n = strlen(str);
    for (int i = 0; i < n; i ++){
        int j = i;
        while (j < n && str[j] != ' ') j ++;
        for (int k = i; k < j; k ++)
            printf("%c", str[k]);
        puts("");
        i += j - i + 1;
        i = j;
    }
    return 0;
}