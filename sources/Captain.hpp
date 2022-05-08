#include <iostream>
#include "Player.hpp"
using namespace coup;
using namespace std;
class Captain : public Player
{
    public:
        Captain(Game &game, string name) : Player(game, name) {
        }
        void block(Player &p); //can block like ambassador
        void steal(Player &p);
        string role() override;
};
