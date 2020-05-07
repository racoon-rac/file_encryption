#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <vector>
#include <bitset>

using namespace std;
int ii;
int* pii = &ii;

void filein( const char* r1_filename, vector<long long>& r1_plav) {

    ifstream ifs;

    int filesize = 0;
    ifs.open(r1_filename, ios::binary);

    ifs.seekg(0, ios::end);
    filesize = (int)ifs.tellg();
    ifs.seekg(0, ios::beg);

    *pii = filesize % 8;

    long long d;
    while ((int)ifs.tellg() < filesize - ii) {
        ifs.read((char*)&d, 8);
        r1_plav.push_back(d);
        cout << ifs.tellg() << "/" << filesize << "\r";
    }
    while ((int)ifs.tellg() < filesize) {
        ifs.read((char*)&d, 1);
        r1_plav.push_back(d);
        cout << ifs.tellg() << "/" << filesize << "\r";
    }
    ifs.close();
}

void filewrite(const char* r5_filename, vector<long long>& r5_encv) {
    ofstream ofs;
    ofs.open(r5_filename, ios::binary);
    int i = 0;
    for (i = 0; i < (int)size(r5_encv) - ii; i++) {
        ofs.write((char*)&r5_encv[i], 8);
        cout << i + 1 << "/" << size(r5_encv) << "\r";
    }
    for ( ; i < (int)size(r5_encv); i++) {
        ofs.write((char*)&r5_encv[i], 1);
        cout << i + 1 << "/" << size(r5_encv) << "\r";
    }
    ofs.close();
}
