// Arena Simulator.cpp
#include <iostream>
#include <random>
#include <vector>
#include "Player.h"
#include "Rounds.h"
using namespace std;

int main()
{
    string PlayerName;
    char atkChoice = ' ';
    vector <string> enemyName{ "Sett", "Gwen", "Lux", "Samira" };

    // Welcome Player 
    cout << "Welcome to League of Legends Arena Simulator!" << "\n" <<
        "Your health will start at 100 Life Points. " << "\n";
     
    // Obtain Player Name   
    cout << "Please enter your name: " << "\n";
    cin >> PlayerName;
    Player *User = new Player(PlayerName, 40, 5, 0, 0);

    cout << "\n" << "Alright " + PlayerName + ", Are you ready to start?" << "\n";
    cin.ignore();

    // Create Object - Sett
    Rounds *Sett = new Rounds("Sett", 50, 5, 15);
    Sett->setEnemyName("Sett");

    cout << "Your first opponent will be..." << "\n" << enemyName[0] << "!" << "\n" << 
         "\n" << "Get ready, I hope you have some extreme luck!" << "\n";
    cout << "Press Enter to continue..." << "\n";
    cin.ignore();
   
    // Loop until Player's Health is 0 or Enemy is Defeated
        do
        {
            User->atkChoice();

            Sett->takePlayerDmg();
            
            Sett->atkPlayer();

            User->takeDamage();

            // Show Status Update of Player Health
            User->playerAlive();



        } while (Sett->enemyAlive() != false);

        delete Sett;

        cout << "Congratulations you defeated your first opponent! Are you ready to go to the next round? " << endl;
        cin.ignore();

        /*Rounds *Gwen = new Rounds("Gwen", 35, 30);

        delete Gwen;*/
}
