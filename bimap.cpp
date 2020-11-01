#include <iostream>
#include <boost/bimap.hpp>

using namespace std;
using namespace boost;

enum class RainbowColor {
    Red,
    Orange,
    Yellow,
    Green,
    Blue,
    Indigo,
    Violet
};

int main() {
    bimap<RainbowColor, string> rainbow_colors;
    rainbow_colors.insert(bimap<RainbowColor, string>::value_type(RainbowColor::Red, "red"));
    RainbowColor color = rainbow_colors.right.at("red");
    string s = rainbow_colors.left.at(RainbowColor::Red);

    return 0;
}