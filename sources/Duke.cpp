#include "Duke.hpp"
#include "Game.hpp"
const int ten = 10;
const int one = 1;

void Duke::tax(){ //add in turn
    if(this->game->players().size() == one){
        throw invalid_argument("too few players");
    }
    if(this->game->turn() != this->name){
            throw invalid_argument("Player is out of turn");
        }
    if(coins() >= ten){
        throw invalid_argument("Player must coup");
    }
    set_coins(coins() + 3);
    this->game->update_turn();
}
void Duke::block(Player &p){//blocks foreign aid 
    if(this->game->players().size() == one){
        throw invalid_argument("too few players");
    }
    if(p.get_game()->get_status(p.get_name()) == "Dead"){
        throw invalid_argument("Player is dead. Cannot block");
    }
    if(p.get_last_move() != "Foreign_aid"){
        throw invalid_argument("Too late Duke");
    }
    p.set_coins(p.coins()-2);
    p.set_last_move("Foreign_aid_blocked");
}
string Duke::role(){
    return "Duke";
}
