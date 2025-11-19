#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Book {
  string title;
  int len;
  bool available;
};

bool compare(const Book &a, const Book &b) {
  if (a.available == b.available) {
    if (a.len == b.len) {
      return a.title < b.title;
    } else {
      return a.len < b.len;
    }
  } else {
    return a.available > b.available;
  }
}

int main() {
  int n;
  cin >> n;
  cin.ignore();
  vector<Book> books(n);
  for (int i = 0; i < n; i++) {
    getline(cin, books[i].title);
    cin >> books[i].len >> books[i].available;
    cin.ignore();
  }
  
  sort(books.begin(), books.end(), compare);

  for (int i = 0; i < n; i++) {
    cout << books[i].available << ' ' << books[i].title << ' ' << books[i].len << '\n';
  }
}