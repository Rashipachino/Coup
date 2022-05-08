#include <iostream>
#include "Player.hpp"

using namespace coup;
using namespace std;
class Duke : public Player
{
    public:
        Duke(Game &game, string name) : Player(game, name) {
            
        }
        void tax();
        void block(Player &p);
        string role() override;
};
