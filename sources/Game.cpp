#include "Game.hpp"
const int six = 6;

namespace coup{
    string coup::Game::turn(){
        return player_list[curr_turn];
    }
    void coup::Game::update_turn(){
        if(this->flag == 0){
            this->flag = 1;
        }
        curr_turn = (curr_turn + 1) % player_list.size();

        while(player_status[player_list[curr_turn]] != "Alive"){
            curr_turn = (curr_turn + 1) % player_list.size();
        }
    }
    vector<string> coup::Game::players(){
        vector<string> ps;
        for(unsigned long i = 0; i < player_list.size(); i++){
            if(this->player_status[this->player_list[i]] == "Alive"){
                ps.push_back(player_list[i]);
            }
        }
        return ps;
    }
    void coup::Game::set_players(string const &name){
        player_list.push_back(name);
        if(player_list.size() > six){
            throw invalid_argument("Too many players");
        }
    }
    void coup::Game::set_status(string const &p, string stat){
        player_status[p] = std::move(stat);
    }
    string coup::Game::get_status(string const &p){
        return player_status[p];
    }
    string coup::Game::winner()//if game is still active, throw error
    {
        int count = 0;
        string winner;
        if(player_list.size() == 1){
            throw invalid_argument("Game has not yet begun");
        }
        for(auto const &i : player_status){
            if(i.second == "Alive"){
                count++;
                winner = i.first;
            }
        }
        if(count != 1){
            throw invalid_argument("Game is still in progress");
        }
        return winner;
    }

    int coup::Game::get_flag() const{
        return flag;
    }
}
