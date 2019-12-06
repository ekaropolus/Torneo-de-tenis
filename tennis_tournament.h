#include <string>
#include <iostream>
using namespace std;
#include <vector>
#include <bits/stdc++.h>

class Match{
	
	private:
		int player_1;
		int player_2;
		char winner;
		char match_day;
		

		
		
    public:
    	Match(int p1, int p2){ player_1 = p1; player_2 = p2;}
		int get_player_1 (){return player_1;}
		int get_player_2(){return player_2;}
		char get_winner(){return winner;}
		

};

class Tournament{

	private:
		int num_players;
		int num_of_matches;
		std::vector<Match> matches;
		std::vector<vector<Match> > calendar;
		int this_day;
		int this_game;
		
	protected:
		//conquer step
		void cyclic_permute(int **a, int size){
			
			int initial_element = *a[0];
			
			for(int i = 0; i < size - 1; i++){(*a)[i] = (*a)[i + 1];}
			(*a)[size - 1] = initial_element;
		}
		
		void split_array(int **a, int **b, int **c, int size){
			
			for(int i = 0; i < size ; i++){
				if (i < size / 2){ (*b)[i] = (*a)[i];}
				else{ (*c)[i - (size/2)] = (*a)[i];}
			}
		}
		
		void copy_array(int **a, int **b, int size){
			for (int i = 0; i < size; i++){ (*b)[i] = (*a)[i];}
		}	
		
	public:
		Tournament (int n_p){
			int games_per_day;
				
			num_players = n_p;
			num_of_matches = num_players*(num_players - 1)/2;
			
			bool is_odd;
			
			if (num_players % 2 == 0){ is_odd = false;}else { is_odd = true;}
			
			
			
			switch (is_odd){
				case true:
					games_per_day = (num_players - 1 ) / 2;
					break;
				case false:
					games_per_day = num_players / 2;
					break;
			}
			
			
			
			int *players = new int[num_players];
			
			for (int i = 0; i<num_players;i++){ players[i] = i + 1;}
			
			
			cout << "El torneo se jugará entre "<< num_players << " jugadores." << endl;
			cout << "tendrá " <<  games_per_day << " juegos por dia." << endl;
			cout << "para sumar un total de " << num_of_matches << " juegos en el torneo." << endl;
			
			this_day = 1;
			this_game = 1;
			set_calendar(&players,num_players,games_per_day);
			
			
			
			
				
		
				
			
		}
		
		int get_num_players(){return num_players;}
		
		
		
		void set_calendar(int **players, int num_players, int games_per_day){
			
			bool is_odd;
			int size;
						
			if (num_players % 2 == 0){ is_odd = false;}else { is_odd = true;}
			
			if (num_players == 1){ return;}
			
			switch (is_odd){
				case true:
					size = num_players + 1;		
					break;
				case false:
					size = num_players;
					break;
			}
			
		
			
			int *players_c = new int[size];
			
			switch (is_odd){
				case true:
					copy_array(players,&players_c,size -1);
					players_c[size - 1]  = 0;
					break;
				case false:
					copy_array(players,&players_c,size);
					break;
			}
			
			
							
			int *players_a = new int[size/2];
			int *players_b = new int[size/2];
			
			
			
			
			
			split_array(&players_c, &players_a, &players_b, size);
						
			
			for (int j = 0; j < size/2; j++){
			
				if (j != 0){ cyclic_permute(&players_b, size/2);}
				for (int i = 0; i <size/2;i++){
					if(players_a[j] == 0 || players_b[i] == 0){ continue;}
					
					cout<<"Juego " << this_game << " del dia " << this_day << ": " << players_a[i]<< " - " << players_b[i] << endl;
					if (this_game >= games_per_day){this_game = 1; this_day++;}else{this_game++;}
						
				}
				
				if (j == 0){ 
					int dummy_day = this_day;
					set_calendar(&players_a,size/2, games_per_day);
					set_calendar(&players_b,size/2, games_per_day);
					}
			}
			
		
		
			
		
		
		}	
		
		
		
		

};
