/*
- observer pattern
- publish & subscribe
- signals and slots
- boost::signal<T>
*/

// TODO: customization and advanced topics

#include <iostream>
#include <string>
#include <boost/signals2.hpp>

using namespace std;
using namespace boost;
using namespace boost::signals2;

struct Player {
    Player(string name) : name(name), goals(0) {}
    string name;
    int goals;

    signal<void(string, int)> scored;
    void score() {
        goals++;
        scored(name, goals);
    }
};

int main() {

    Player p("Harry");
    
    auto cnxn = p.scored.connect([](string name, int goals) {
        cout << name << " scored " << goals << " goals." << endl;
    });

    p.score(); // 1
    {
        shared_connection_block block(cnxn);
        p.score(); // 2
        p.score(); // 3
    }
    p.score(); // 4
    cnxn.disconnect();
    p.score(); // 5

    p.scored.disconnect_all_slots();
    return 0;
}