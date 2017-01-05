/*
Name: Store Manager Game
Author: Robert Stivanson
Created: 2010
Repo: https://github.com/RobertStivanson/Store-Manager-Game

This is the original code for the Store Manager Game. This code was written in 2010 when I 
was a sophmore in High School.

The following code is poorly organized and written. I have preserved this code and its lack
to show you of comments all, and myself, how much I have grown as a developer. There is a 
revised version of this on my GitHub.

*/


#include <iostream>

using namespace std;


class game
{
public:
      int money;
      int stock_a;
      int stock_m;
      int stock_b;
      int stock_o;
      int stock_pc;
      int stock_pc_dip;
      int stock_canned;
      int emp[2];
      int beg_n;
      int day;
      int option;
      int item[10];
      int m_g;
      
      
      void begin()
      {
           day = 1;
           emp[0] = 1;
           money = 100;
           stock_a = 10;
           stock_m = 10;
           stock_b = 10;
           stock_o = 10;
           stock_pc = 10;
           stock_pc_dip = 10;
           stock_canned = 10;
           
           cout<<"Welcome. Your name is bob.. incase you didn't know...";
           cout<<"and you are the manager of Bob's general market.";
           cout<<"You're job is to order products for in your store, and to \nmake sure the products you ordered are delivered safely, and that they are \ncorrectly counted and stocked, then put on the self to be sold.\n\n\n Are you ready to begin your not so epic journey as the store manager of Bob's \ngeneral market??\n\n      1. Yes      2. No\n";
           cin>> beg_n;
           if ( beg_n == 1 ) {
                gam();
           }
           if ( beg_n == 2 ) {
                return;
           }
           else if ( beg_n != 1 || beg_n != 2 ) {
                return;
           }
      }
            
      void gam()
      {
           if ( money >= 10000000 ) {
                win();
           }     
                
           cout<<"\n\n\nDay "<< day <<":\n";
           cout<<"Your current money is: $"<< money <<"\n      Your current number of employees is: "<< emp[0];
           cout<<" What would you like to do first?\n\n1. Purchase items      2. Start day      3. Check warehouse      \n4. Hire employees\n";
           cin>> option;
           if ( option == 1 ) {
                p_menu();
           }
           if ( option == 2 ) {
                cout<<"20 seconds till the day ends.\n";
                for ( int counter = 0; counter <= 2000000000; counter ++ ) {
                    if ( counter == 500000000 ) {
                       cout<<"15 seconds left.\n";
                    }
                    else if ( counter == 1000000000 ) {
                       cout<<"10 seconds left.\n";
                    }
                    else if ( counter == 1500000000 ) {
                       cout<<"5 seconds left.\n";
                    }
                    else if ( counter == 2000000000 ) {
                       item[10] = ((stock_a + stock_m + stock_o + stock_b + stock_pc + stock_pc_dip + stock_canned / 7) * 4);
                       m_g = (item[10] * emp[0]);
                       cout<<"Day "<< day <<" successfully completed!!!";
                       cout<<"\nYou gained "<< m_g <<" dollars.";
                       day = day + 1;
                       money =  money + m_g;
                       gam();
                    }
                }
           }
           if ( option == 3 ) {
                cout<<"\n\nYour Warehouse:\n\n";
                cout<<"Apples --------------------- Quantity: "<< stock_a << endl;
                cout<<"Milk ----------------------- Quantity: "<< stock_m << endl;
                cout<<"Oranges -------------------- Quantity: "<< stock_o << endl;
                cout<<"Bananas -------------------- Quantity: "<< stock_b << endl;
                cout<<"Potatoe Chips -------------- Quantity: "<< stock_pc << endl;
                cout<<"Potatoe Chip Dip ----------- Quantity: "<< stock_pc_dip << endl;
                cout<<"Canned Goods --------------- Quantity: "<< stock_canned << endl;
                gam();
           }
           if ( option == 4 ) {
                hire();           
           }
           if ( option != 1 || option != 2 || option != 3 || option != 4 || option != 5 ) {
                gam();
           }
           cin.ignore();
      }
      
      void hire()
      {
                cout<<"\nHire employees to increase your daily income.\n";
                cout<<"Your current money is: $"<< money << endl;
                cout<<"You currently have "<< emp[0] <<" employees hired.\n";
                cout<<"Hire another employee for "<< emp[0] * 250;
                cout<<"\nHire?   1. Yes       2. No\n";
                cin>> item[7];
                if ( item[7] == 1 ) {
                   if ( money >= emp[0] * 250 ) {
                      emp[0] = emp[0] + 1;
                      money = money - ( emp[0] * 250);
                      hire();
                   }
                   else if ( money < item[0] * 250 ) {
                      cout<<"\nYou do not have enough money for this transaction\n\n";
                      gam();
                   }
                }
                else if ( item[7] != 1 ) {
                     gam();   
                }
      }
      
      void p_menu()
      {
           
           cout<<"\nPlease select which items you would like to buy.";
           cout<<"\n\nItems;\n";
           cout<<"\nApple                  Cost: 4 each    Currently owned: "<< stock_a << endl;
           cout<<"How many would you like to buy? ";
           cin>> item[0];
           if ( money >= item[0] * 4 ) {
              stock_a = stock_a + item[0];
              money = money - (item[0] * 4);
           }
           if ( money < item[0] * 4 ) {
              cout<<"You do not have enough money for this transaction.\n";
           }
           cout<<"Milk                   Cost: 10 each  Currently owned: "<< stock_m << endl;
           cout<<"How many would you like to buy? ";
           cin>> item[1];
           if ( money >= item[1] * 10 ) {
               stock_m = stock_m + item[1];
               money = money - (item[1] * 10);
           }
           if ( money < item[1] * 10 ) {
               cout<<"You do not have enough money for this transaction.\n";
           }
           cout<<"Banana                 Cost: 3 each   Currently owned: "<< stock_b << endl;
           cout<<"How many would you like to buy? ";
           cin>> item[2];
           if ( money >= item[2] * 3 ) {
               stock_b = stock_b + item[2];
               money = money - (item[2] * 3);
           }
           if ( money < item[2] * 3 ) {
               cout<<"You do not have enough money for this transaction.\n";
           }
           cout<<"Orange                 Cost: 5 each   Currently owned: "<< stock_o << endl;
           cout<<"How many would you like to buy? ";
           cin>> item[3];
           if ( money >= item[3] * 5 ) {
               stock_o = stock_o + item[3];
               money = money - (item[3] * 5);
           }
           if ( money < item[3] * 5 ) {
               cout<<"You do not have enough money for this transaction.\n";
           }
           cout<<"Potatoe chips          Cost: 7 each   Currently owned: "<< stock_pc << endl;
           cout<<"How many would you like to buy? ";
           cin>> item[4];
           if ( money >= item[4] * 7 ) {
               stock_pc = stock_pc + item[4];
               money = money - (item[4] * 7);
           }
           if ( money < item[4] * 7 ) {
               cout<<"You do not have enough money for this transaction.\n";
           }
           cout<<"Potatoe chip dip       Cost: 5 each   Currently owned: "<< stock_pc_dip << endl;
           cout<<"How many would you like to buy? ";
           cin>> item[5];
           if ( money >= item[5] * 5 ) {
               stock_pc_dip = stock_pc_dip + item[5];
               money = money - (item[5] * 5);
           }
           if ( money < item[5] * 5 ) {
               cout<<"You do not have enough money for this transaction.\n";
           }
           cout<<"Canned goods           Cost: 8 each   Currently owned: "<< stock_canned << endl;
           cout<<"How many would you like to buy? ";
           cin>> item[6];
           if ( money >= item[6] * 8 ) {
               stock_canned = stock_canned + item[6];
               money = money - (item[6] * 8);
               item[0] = 0;
               item[1] = 0;
               item[2] = 0;
               item[3] = 0;
               item[4] = 0;
               item[5] = 0;
               item[6] = 0;
               gam();
           }
           if ( money < item[6] * 8 ) {
               cout<<"You do not have enough money for this transaction.\n";
               item[0] = 0;
               item[1] = 0;
               item[2] = 0;
               item[3] = 0;
               item[4] = 0;
               item[5] = 0;
               item[6] = 0;
               gam();
           }
           cin.ignore();
      }
      
      int win()
      {
           cout<<" YOU WIN!!!!!";
           cout<<" SORRY BUT THEE ARE NO SPECIAL PRIZES\n\n\n\n";
           cout<<" Press any key to exit.";
           cin.get();
           return 0;
      }
      
};

int main()
{
      int menu;
      game a;
      

      cout<<"\n   WELCOME TO THE STORE MANAGER GAME!!!! :D\n\n";
      cout<<"   Main Menu\n\n";
      cout<<"   1. New game";
      cout<<"   2. Instructions";
      cout<<"   3. Quit\n";
      cin >> menu;
      if ( menu == 1 ) {
           cout<<"\n\n\n";
           a.begin();
      }
      else if ( menu == 2 ) {
           cout<<"The ojective of this game is to raise 10,000,000 dollars as fast as you can!\n\n";
           cout<<"Press any key to retun to the main menu.";
           cin.get();
           main();
      }
      else if ( menu == 3 ) {
           return 0;
      }
      else if ( menu != 1 || menu != 2 || menu != 3 ) {
           main();
      }

      
      cin.get();
      return 0;
}
