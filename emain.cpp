#include <iostream>
#include <filesystem>
#include <string>
#include <vector>
#include <bitset>
#include <string>
#include "addtool.h"

using namespace std;
namespace fs = std::filesystem;    

void organs(const char* dir, long long code);

int main() {

    const char* set_dir = "dir_name";

    bitset<64> set_code (
        "0010100010100010100010100010100010100010100010100010100010101010");
    

    long long lcode = set_code.to_ullong();

    organs(set_dir, lcode);

    return 0;
}

void organs(const char* dir, long long code) {

    for (const fs::directory_entry& x :
        fs::recursive_directory_iterator(dir)) {

        if (x.is_directory()) {
            continue;
        }

        vector<long long> plav;
        vector<long long> encv;

        const char* filename;

        cout << endl;
        cout << "file => llongdata" << endl;
        cout << endl;

        string str;
        str = x.path().string();
        filename = str.c_str();

        filein(filename, plav);
        
        cout << endl;
        cout << endl;

        encv.resize(size(plav));


        for (int i = 0; i < (int)size(plav); i++) {
            encv[i] = plav[i] ^ code;
            cout << encv[i] << "\r";
        }

        cout << endl;
        cout << "encryped" << endl;
        cout << endl;

        cout << endl;
        cout << "llongdata => file" << endl;
        cout << endl;

        filewrite(filename, encv);
        
        cout << endl;
        cout << "end" << endl;
        cout << endl;
    }
}
