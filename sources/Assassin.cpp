#include "Assassin.hpp"
#include "Game.hpp"
const int ten = 10;
const int seven = 7;
const int three = 3;
  
//assassin can coup with 3 points. That player's status becomes dead
void Assassin::coup(Player &p) {
    if(this->game->players().size() == 1){
        throw invalid_argument("too few players");
    }
    if(this->game->turn() != this->name){
        throw invalid_argument("Player is out of turn");
    }
    if(this->coin_count < three){
        throw invalid_argument("Not enough coins to coup");
    }
    if(p.get_game()->get_status(p.get_name()) == "Dead"){
        throw invalid_argument("Player to coup is already dead");
    }
    if(this->coin_count < seven){
        p.get_game()->set_status(p.get_name(), "Assassinated"); //Assassinate character
        this->coin_count -= 3;
        this->last_move = "Assassinate";
        this->game->update_turn();
        this->history = &p;
    }
    if(this->coin_count >= seven){ //regular coup
    Player::coup(p);
    }
}

string Assassin::role(){
    return "Assassin";
}
    


