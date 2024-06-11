#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsShowScreen.h"

using namespace std;

class clsDepositeScreen :protected clsShowScreen
{

private :

    
    static  void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }
   

public:


    static void ShowDepositScreen()
    {
        _DrawScreenHeader("\t Deposite Screen ");

        string AccountNumber = "";

        cout << "\nPlease Enter client Account Number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient ClientToDeposite = clsBankClient::Find(AccountNumber);
        _PrintClient(ClientToDeposite);


        double Amount = 0;
        cout << "\nPlease enter deposit amount? ";
         Amount =clsInputValidate::ReadDblNumber();

        cout << "\nAre you sure you want to perform this transaction? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            ClientToDeposite.Deposit(Amount);
            cout << "\nAmount Deposited Successfully.\n";
            cout << "\nNew Balance Is: " << ClientToDeposite.AccountBalance;

        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }

        

        


        

      


    }


};

