#include <iostream>
#include <string>
#include <boost/tokenizer.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/trim_all.hpp>

using namespace std;
using namespace boost;

int main() {
    string sentence = "Hello, world!";
    char_separator<char> separator("o", " ");
    tokenizer<char_separator<char>> t(sentence, separator);

    for(string word : t) {
        cout << word << endl;
    }

    string foo_str = "3.14";
    double foo_double = lexical_cast<double>(foo_str);
    cout << foo_double * 2 << endl;

    try {
        lexical_cast<int>("foo");
    }
    catch(const bad_lexical_cast& e) {
        cout << e.what() << endl;
    }

    string newlines = "Hello, world!\n\n\n";
    trim_all(newlines);
    to_upper(newlines);
    cout << newlines << endl;

    return 0;
}