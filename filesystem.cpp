#include <iostream>
#include <boost/filesystem.hpp>

using namespace std;
using namespace boost;
using namespace boost::filesystem;

void get_file_info(path& p) {
    if(!exists(p)) cout << p << " does not exist." << endl;
    else {
        if(is_regular_file(p)) {
            cout << "Name: " << p.filename() << endl;
            cout << "Size: " << file_size(p) << endl;
            
            auto s = status(p);
            cout << "Type: " << s.type() << endl;
            cout << "Permissions: " << s.permissions() << endl;
        }
    }
}

void traverse(path& p) {
    directory_iterator end;
    for(directory_iterator it(p); it != end; it++) {
        path q = it->path();
        if(is_regular_file(q)) cout << q.filename() << endl;
        else if(is_directory(q)) traverse(q);
    }
}

int main(int argc, char** argv) {
    path executable(argv[0]);
    get_file_info(executable);

    path home("/home/ganesh/Desktop");
    traverse(home);
    
    return 0;
}