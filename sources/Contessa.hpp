#include <iostream>
#include "Player.hpp"
using namespace coup;
using namespace std;
class Contessa : public Player
{
    public:
        Contessa(Game &game, string name) : Player(game, name) {
            
        }
        void block(Player &p); //can block assassanation
        string role() override;
};
