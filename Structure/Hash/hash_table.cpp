#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int CAPACITY = 1000;
string keys[CAPACITY];
string values[CAPACITY];
int n_size = 0;

int position(string key){
    int hash = 0;
    for (char c : key) {
        hash += c;
    }
    return hash % CAPACITY;
}

void insert(string key, string value) {
    int pos = position(key);
    int original_pos = pos;

    while (keys[pos] != "" && keys[pos] != key) {
        pos = (pos + 1) % CAPACITY;
        if (pos == original_pos) {
            cout << "Hash table da day, khong the them" << endl;
            return;
        }
    }
    keys[pos] = key;
    values[pos] = value;
    n_size++;
}

string find(string key) {
    int pos = position(key);
    int original_pos = pos;

    while (keys[pos] != key && keys[pos] != "") {
        pos = (pos + 1) % CAPACITY;
        if (pos == original_pos) {
            return "";
        }
    }
    return values[pos];
}

int main() {
    fill(keys, keys + CAPACITY, "");
    fill(values, values + CAPACITY, "");

    ifstream file("/Users/vuthevy1209/Documents/C++/input.rtf");
    string line, english, vietnamese;
    while (getline(file, line)) {
        int pos = line.find(",");
        english = line.substr(0, pos);
        vietnamese = line.substr(pos + 1);
        insert(english, vietnamese);
    }
    file.close();

    string word;
    cout << "Nhap tu Tieng anh: ";
    cin >> word;
    string meaning = find(word);
    if (meaning == "") {
        cout << "Tu dien trong, khong dich duoc, xin loi ban :(( !" << endl;
    } else {
        cout << "Nghia Tieng Viet la: " << meaning << endl;
    }

    return 0;
}
