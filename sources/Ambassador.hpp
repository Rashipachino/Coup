#include <iostream>
#include "Player.hpp"
using namespace coup;
using namespace std;
class Ambassador : public Player
{
    public:
        Ambassador(Game& game, string name) : Player(game, name) {
        }
        void transfer(Player &p1, Player &p2);
        void block(Player &p1);
        string role() override;
};
