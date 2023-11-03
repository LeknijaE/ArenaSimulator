// TFTSimulator.cpp
#include <iostream>
#include <random>
#include <vector>
#include "Player.h"
#include "Rounds.h"
using namespace std;

int main()
{
    int min{ 1 };
    int max{ 25 };
    string PlayerName;
    char atkChoice = ' ';
    int playerHealth, enemyHealth;
    vector <string> enemyName{ "Sett", "Gwen", "Lux", "Samira" };
    Player p1;
    Rounds r1;

    // Welcome Player 
    cout << "Welcome to League of Legends Arena Simulator!" << "\n" <<
        "Your health will start at 100 Life Points. " << "\n";
     
    // Obtain Player Name   
    cout << "Please enter your name: " << "\n";
    cin >> PlayerName;
    
    cout << "\n" << "Alright " + PlayerName + ", Are you ready to start?" << "\n" << "Press Enter to continue..." << "\n";
    cin.ignore();

    // Create Object - Sett
    Rounds *Sett = new Rounds("Sett", 50, 15);
    Sett->setEnemyName("Sett");

    cout << "Your first opponent will be..." << "\n" << enemyName[0] << "!" << "\n" << 
         "\n" << "Get ready, I hope you have some extreme luck!" << "\n";
    cin.ignore();
    
    
    do
    {
        p1.atkChoice(atkChoice);

        if (atkChoice == 'q' || 'Q')
        {
            cout << PlayerName + " hit " << Sett->getEnemyName() << " for " << p1.getAtk() << " Hit Points!" << "\n";
            Sett->takePlayerDmg();
            cout << "=============================" << endl;
            cout << Sett->getEnemyName() + " attacks " << PlayerName + " for " << Sett->getEnemyDmg() << " leaving " << PlayerName << " with " << p1.getHealth() << " Health points." << endl;
            cout << Sett->getEnemyName() << " current health points is at : " << Sett->getEnemyHP() << "." << "\n";

        }
        else if (atkChoice == 'w' || 'W')
        {
            cout << PlayerName + " Healed up and their health is now " << p1.getHealth() << endl;
            Sett->takePlayerDmg();
            cout << "=========================" << "\n";
            cout << Sett->getEnemyName() + " attacks " << PlayerName + " for " << Sett->getEnemyDmg() << " leaving " << PlayerName << " with " << p1.getHealth() << " Health points." << endl;
            cout << Sett->getEnemyName() << " current health points is at : " << Sett->getEnemyHP() << "." << "\n";
            
        }
        else if (atkChoice == 'e' || 'E')
        {
            cout << PlayerName + " has amplified their next attack!" << endl;
            cout << PlayerName + " damage is now " << p1.getAtk() + ". " << "\n";
            Sett->takePlayerDmg();
            cout << "=========================" << "\n";
            cout << Sett->getEnemyName() + " attacks " << PlayerName + " for " << Sett->getEnemyDmg() << " leaving " << PlayerName << " with " << p1.getHealth() << " Health points." << endl;
            cout << Sett->getEnemyName() << " current health points is at : " << Sett->getEnemyHP() << "." << "\n";
            
        }
        else if (atkChoice == 'r' || 'R')
        {
            cout << PlayerName + " has unleashed their ultimate attack, damaging " << Sett->getEnemyName() << " for " << p1.getAtk() << ". " << "\n";
            Sett->takePlayerDmg();
            cout << "=========================" << "\n";
            cout << Sett->getEnemyName() + " attacks " << PlayerName + " for " << Sett->getEnemyDmg() << " leaving " << PlayerName << " with " << p1.getHealth() << " Health points." << endl;
            cout << Sett->getEnemyName() << " current health points is at : " << Sett->getEnemyHP() << "." << "\n";
            
        }

        /*cout << Sett->getEnemyName() + " attacks " << PlayerName + " for " << Sett->getEnemyDmg() << " leaving " << PlayerName << " with " << p1.getHealth() << " points." << endl;*/
        p1.takeDamage();
        cin.ignore();


    } while (Sett->enemyAlive() != false);
    
    

    delete Sett;

    cout << "Congratz you defeated your first opponent! Are you ready to go to the next round? " << endl;
    cin.ignore();

    Rounds* Gwen = new Rounds("Gwen", 35, 30);

    delete Gwen;
  

    

    //cout << "================================" << "\n";
    //    cout << PlayerName + " ================= " << enemyName[0] << "\n";
    //    cout << "================================" << "\n";

    //   

    //   // do {

    //          cout << PlayerName + " applied " << to_string(atkPoints) + " Damage to " << enemyName[0] << "\n";
    //          cout << enemyName[0] + " applied " << to_string(r1.GetEDamage()) + " Damage to " << PlayerName << "\n";

    //          r1.GetDamageTaken();
    //          r1.GetEHp(enemyHealth);
    //          p1.takeDamage();
    //          p1.GetHp(playerHealth);
    //          

    //          cout << "--------------------------------" << "\n";
    //          cout << PlayerName + " has " << to_string(playerHealth) + " Remaining life." << "\n";
    //          cout << enemyName[0] << " has " << to_string(enemyHealth) + " Remaining life." << "\n";
    //          cout << "--------------------------------" << "\n";

        //} while (playerHealth <= 0 || enemyHealth <= 0);
   
        

        

}
