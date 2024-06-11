#pragma once
#include <iostream>
#include "clsShowScreen.h"
#include "iomanip"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransActionsMenue.h"
#include "clsManageUsersScreen.h"
#include "LogInRigester.h"
#include "Global.h"
#include "clsCurrencyScreen.h"


using namespace std;
class clsMainMenuOptions :protected clsShowScreen
{
private:

 static short _ReadMainMenueOption()
    {
       

        cout<<setw(37) << "\t\t\t\tChose Number in Range[1 : 10 ]";
        short  Number = clsInputValidate::ReadShortNumberBetween(1, 10);
        return Number;

    }

 static  enum enMainMenueOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7,eLoginsRigester=8, eCurrency = 9, eExit = 10
    };

 static void  _ShowAllClientsScreen()
   {

     clsClientListScreen::ShowClientsList();

   }

 static void  _ShowAddNewClientsScreen()
 {

   //  cout << "Show Add New Client will be Here:-)....";

     clsAddNewClientScreen::ShowAddNewClientScreen();


 }

 static void  _ShowDeleteClientScreen()
 {

     clsDeleteClientScreen::ShowDeleteClientScreen();
    // cout << "Show Delete  Client will be Here:-)....";
     

 }

 static void  _ShowUpdateClientScreen()
 {

    // cout << "Show Update Client will be Here:-)....";

     clsUpdateClientScreen::ShowUpdateClientScreen();

 }
 
 static void  _ShowFindClientScreen()
 {

   //  cout << "Show Find Client  will be Here:-)....";
     clsFindClientScreen::ShowFindClientScreen();

 }
 
 static void  _ShowTransactionsMenue()
 {

     //cout << "Show Transaction Menue  will be Here:-)....";

     clsTransactionsScreen::ShowTransactionsMenue();

 }
 
 static void  _ShowManageUsersMenue()
 {

  //   cout << "Show Manage Users  will be Here:-)....";

     clsManageUsersScreen::ShowManageUsersMenue();

 }
 
 static void  _ShowLoginsRegister()
 {

     LogInRigester::ShowLoginsRegisterScreen();
 }
 
 static void  _ShowCurrencyScreen()
 {

     clsCurrencyScreen::ShowCurrencyScreen();



 }

 static void _Logout()
 {
     CurrentUser = clsUser::Find("", "");
 }

 static void _GoBackToMainMenue()
 {
     cout << "\n\nPress any key to go back to Main Menue...";
     system("pause>0");
     ShowMainMenue();
 }

 static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
   {
       switch (MainMenueOption)
       {
       case enMainMenueOptions::eListClients:
       {
            system("cls");
           _ShowAllClientsScreen();
           _GoBackToMainMenue();
           break;
       }
       case enMainMenueOptions::eAddNewClient:
            system("cls");
           _ShowAddNewClientsScreen();
           _GoBackToMainMenue();
           break;

       case enMainMenueOptions::eDeleteClient:
           system("cls");
           _ShowDeleteClientScreen();
           _GoBackToMainMenue();
           break;

       case enMainMenueOptions::eUpdateClient:
           system("cls");
           _ShowUpdateClientScreen();
           _GoBackToMainMenue();
           break;

       case enMainMenueOptions::eFindClient:
           system("cls");
           _ShowFindClientScreen();
           _GoBackToMainMenue();
           break;

       case enMainMenueOptions::eShowTransactionsMenue:
           system("cls");
           _ShowTransactionsMenue();
           _GoBackToMainMenue();

           break;

       case enMainMenueOptions::eManageUsers:
           system("cls");
           _ShowManageUsersMenue();
           _GoBackToMainMenue();

           break;

       case enMainMenueOptions::eLoginsRigester:
            system("cls");
           _ShowLoginsRegister();
           _GoBackToMainMenue();

           break; 
       
       case enMainMenueOptions::eCurrency:
            system("cls");
           _ShowCurrencyScreen();
           _GoBackToMainMenue();

           break;

       case enMainMenueOptions::eExit:
           system("cls");
           _Logout();
          
           break;
       }

   }


public:

   static void ShowMainMenue()
    {
        system("cls");
        
        system("cls");
        _DrawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Logins Register.\n";
        cout << setw(37) << left << "" << "\t[9] Currency.\n";
        cout << setw(37) << left << "" << "\t[10] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
   }



};

