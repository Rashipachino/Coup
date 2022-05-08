#include "Game.hpp"

namespace coup{
    string coup::Game::turn(){
        return player_list[curr_turn];
    }
    void coup::Game::update_turn(){
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
    void coup::Game::set_players(string name){
        player_list.push_back(name);
        //cout << player_list[0] << endl;
    }
    void coup::Game::set_status(string p, string stat){
        player_status[p] = stat;
    }
    string coup::Game::get_status(string p){
        return player_status[p];
    }
    string coup::Game::winner()//if game is still active, throw error
    {
        int count = 0;
        string winner;
        for(auto i : player_status){
            if(i.second == "Alive"){
                count++;
                winner = i.first;
            }
        }
        if(count == 1){
            return winner;
        }
        else{
            throw invalid_argument("Game is still in progress");
        }
    }
}
