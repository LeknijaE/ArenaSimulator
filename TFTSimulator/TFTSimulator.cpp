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
            atkChoice = User->atkChoice();

            if (atkChoice == 'q' || atkChoice == 'q')
            {
                cout << PlayerName + " hit " << Sett->getEnemyName() << " for " << User->getAtk() << " Hit Points!" << "\n";
                Sett->takePlayerDmg();
                User->gainEnergy();
                cout << "Current Energy : " << to_string(User->getEnergy()) << "\n";

                cout << "=============================" << endl;

                cout << Sett->getEnemyName() + " attacks " << PlayerName + " for " << Sett->getEnemyDmg() << " leaving " << PlayerName << " with " << User->getHealth() << " Health points." << endl;
                cout << Sett->getEnemyName() << " current health points is at : " << Sett->getEnemyHP() << "." << "\n";


            }
            else if (atkChoice == 'w' || atkChoice == 'w')
            {
                cout << PlayerName + " Healed up and their health is now " << User->getHealth() << endl;

                cout << "=========================" << "\n";

                cout << Sett->getEnemyName() + " attacks " << PlayerName + " for " << Sett->getEnemyDmg() << " leaving " << PlayerName << " with " << User->getHealth() << " Health points." << endl;
                cout << Sett->getEnemyName() << " current health points is at : " << Sett->getEnemyHP() << "." << "\n";


            }
            else if (atkChoice == 'e' || atkChoice == 'e')
            {
                User->buffDamage();
                cout << PlayerName + " has amplified their next attack!" << endl;
                cout << PlayerName + " damage is now " << to_string(User->getAtk()) + ". " << "\n";

                cout << "=========================" << "\n";

                cout << Sett->getEnemyName() + " attacks " << PlayerName + " for " << Sett->getEnemyDmg() << " leaving " << PlayerName << " with " << User->getHealth() << " Health points." << endl;
                cout << Sett->getEnemyName() << " current health points is at : " << Sett->getEnemyHP() << "." << "\n";


            }
            else if (atkChoice == 'r' || atkChoice == 'r')
            {

                    cout << PlayerName + " has unleashed their ultimate attack, damaging " << Sett->getEnemyName() << " for " << User->getAtk() << ". " << "\n";
                    User->getAtk();
                    Sett->takePlayerDmg();

                    cout << "=========================" << "\n";

                    cout << Sett->getEnemyName() + " attacks " << PlayerName + " for " << Sett->getEnemyDmg() << " leaving " << PlayerName << " with " << User->getHealth() << " Health points." << endl;
                    cout << Sett->getEnemyName() << " current health points is at : " << Sett->getEnemyHP() << "." << "\n";
              
            }
            
            User->takeDamage();
            cin.ignore();


        } while (Sett->enemyAlive() != false);

        delete Sett;

        cout << "Congratulations you defeated your first opponent! Are you ready to go to the next round? " << endl;
        cin.ignore();

        /*Rounds *Gwen = new Rounds("Gwen", 35, 30);

        delete Gwen;*/
}
