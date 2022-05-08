#include "Assassin.hpp"
#include "Game.hpp"
  
//assassin can coup with 3 points. That player's status becomes dead
void Assassin::coup(Player &p) {
    if(this->coin_count >= 10){ //regular coup
        Player::coup(p);
    }
    else if(this->game->turn() != this->name){
        throw invalid_argument("Player is out of turn");
    }
    else if(this->coin_count < 3){
        throw invalid_argument("Not enough coins to coup");
    }
    else if(p.get_game()->get_status(p.get_name()) == "Dead"){
        throw invalid_argument("Player to coup is already dead");
    }
    else{
        p.get_game()->set_status(p.get_name(), "Assassinated"); //Assassinate character
        this->coin_count -= 3;
        this->last_move = "Coup";
        this->game->update_turn();
        this->history = &p;
    }
}

string Assassin::role(){
    return "Assassin";
}
    


