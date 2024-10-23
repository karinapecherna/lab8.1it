#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <cstring> 
using namespace std;


int Count(char* str_s) {
    if (strlen(str_s) < 3) {
        return 0; 
    }
    int k = 0;
    for (int i = 0; str_s[i + 2] != 0; i++) {
        if ((str_s[i] == 'O' && str_s[i + 1] == 'G' && str_s[i + 2] == 'O') ||
            (str_s[i] == 'A' && str_s[i + 1] == 'G' && str_s[i + 2] == 'A')) {
            k++; 
        }
    }
    return k;
}


char* Change(char* str_s) {
    size_t len = strlen(str_s);
    if (len < 3) {
        return str_s;
    }
    
    char* tmp = new char[len * 2 + 1]; 
    char* t = tmp; 
    tmp[0] = '\0'; 
    size_t i = 0;

   
    while (i < len && str_s[i + 2] != 0) {
        if ((str_s[i] == 'O' && str_s[i + 1] == 'G' && str_s[i + 2] == 'O') ||
            (str_s[i] == 'A' && str_s[i + 1] == 'G' && str_s[i + 2] == 'A')) {
            strcat(t, "**"); 
            t += 2; 
            i += 3; 
        }
        else {
            *t++ = str_s[i++];
            *t = '\0'; 
        }
    }

    
    while (i < len) {
        *t++ = str_s[i++];
    }
    *t = '\0'; 

    strcpy(str_s, tmp);
    return tmp; 
}

int main() {
    char str_s[101];
    cout << "Enter string:" << endl;
    cin.getline(str_s, 100);

    
    cout << "String contained " << Count(str_s) << " groups of 'OGO' or 'AGA'" << endl;

   
    char* dest = new char[151];
    dest = Change(str_s);

    
    cout << "Modified string (param) : " << str_s << endl;
    cout << "Modified string (result): " << dest << endl;

    
    delete[] dest;
    return 0;
}
