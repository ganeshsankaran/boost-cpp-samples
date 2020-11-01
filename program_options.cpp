/*
- args can be optional or required
- args can be of the form -f or --foo
- args must be self-documenting
- args can be external
*/

// TODO: positional options

#include <iostream>
#include <string>
#include <boost/program_options.hpp>

using namespace std;
using namespace boost;

int main(int argc, char** argv) {
    program_options::options_description options("Text processor");
    options.add_options() 
        ("help,h", "Options")
        ("inputs,i", program_options::value<vector<string>>()->multitoken(), "Input file(s)") // multiple values
        ("output,o", program_options::value<string>()->default_value("out.txt"), "Output file"); // default value

    program_options::variables_map vm;
    program_options::store(program_options::parse_command_line(argc, argv, options), vm);
    program_options::notify(vm);

    if(vm.count("help")) cout << options << endl;

    vector<string> inputs = vm["inputs"].as<vector<string>>();
    string output = vm["output"].as<string>();

    for(string input : inputs) {
        cout << input << " ";
    }
    cout << "-> " << output << endl;

    return 0;
}