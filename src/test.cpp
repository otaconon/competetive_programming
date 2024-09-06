#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <map>
#include <string>
#include <bits/stdc++.h>

using namespace std;

void foo1(const std::string& s) {
    std::string out = s;
    for (auto& c : out) {
        ++c;
    }
    std::cout << out << std::endl;
}

void foo1(std::string&& s) {
    string out = std::move(s);
    for (auto& c : out) {
        ++c;
    }
    std::cout << out << std::endl;
}

class Foo {
public:
    Foo(string&& s) : s(s) {

    }

private:
    string s;
};

int main() {

    std::string a = "Bla bla bla";
    Foo foo("asdjasjds");
    std::cout << a << endl;
    return 0;
}