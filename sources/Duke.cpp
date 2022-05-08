#include "Duke.hpp"
#include "Game.hpp"

void Duke::tax(){ //add in turn
if(this->game->turn() != this->name){
        throw invalid_argument("Player is out of turn");
    }
else if(coins() == 10){
    throw invalid_argument("Player must coup");
}
else{
    set_coins(coins() + 3);
    this->game->update_turn();
}

}
void Duke::block(Player &p){//blocks foreign aid 
    if(p.get_game()->get_status(p.get_name()) == "Dead"){
        throw invalid_argument("Player is dead. Cannot block");
    }
    else if(p.get_last_move() != "Foreign_aid"){
        throw invalid_argument("Too late Duke");
    }
    else{
        p.set_coins(p.coins()-2);
        p.set_last_move("Foreign_aid_blocked");
    }
}
string Duke::role(){
    return "Duke";
}
