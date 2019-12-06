#include <iostream>
using namespace std;
#include "tennis_tournament.h"
#include <math.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	//Obtenemos el número de jugadores
	int num_players;
	cout << "Give me the number of players: " << endl;
	cin >> num_players;
	
	//Hacemos la calendarización del torneo
	Tournament copa_mx (num_players);
	
	
	return 0;
}
