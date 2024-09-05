#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <map>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int decToBin(int a) {
    return a * 3;
}

class Foo {

};

int main() {
    std::vector<std::unique_ptr<Foo>> v(std::from_range, std::views::iota(0, n) | std::views::transform([](auto) { return std::make_unique<Foo>(); }));
}