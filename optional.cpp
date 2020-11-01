/*
Storing and returning optional values:
- null pointer
- default value
- flag (optional or not optional)
- boost::optional<T>
*/

#include <iostream>
#include <string>
#include <boost/optional.hpp>
#include <boost/optional/optional_io.hpp>

using namespace std;
using namespace boost;

struct Name {
    string first, last;
    optional<string> middle;
};

ostream& operator<<(ostream& os, const Name& name) {
    os << name.first << " ";
    if(name.middle) os << name.middle.get() << " ";
    os << name.last;
    return os;
}

int main() {
    Name name;
    name.first = "John"; name.last = "Kennedy";

    cout << name << endl;
    name.middle = "Fitzgerald";
    cout << name << endl;

    return 0;
}