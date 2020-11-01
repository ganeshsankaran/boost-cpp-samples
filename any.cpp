/*
- Java has Object
- C++ has discriminated unions (limited)
- boost::any
*/

#include <iostream>
#include <string>
#include <vector>
#include <boost/any.hpp>

using namespace std;
using namespace boost;

int main() {
    any foo;
    any bar{2};
    vector<any> baz{1, "two", 3, "four"};

    if(!bar.empty()) cout << bar.type().name() << endl;

    int baz_0 = any_cast<int>(baz[0]);
    
    try {
        int baz_1 = any_cast<int>(baz[1]);
    }
    catch(const bad_any_cast& e) {
        cout << "Bad cast" << endl;
    }

    for(any a : baz) {
        int* int_ptr = any_cast<int>(&a);
        if(int_ptr) cout << *int_ptr << endl;

        const char** str_ptr = any_cast<const char*>(&a);
        if(str_ptr) cout << *str_ptr << endl;
    }
    
    return 0;
}