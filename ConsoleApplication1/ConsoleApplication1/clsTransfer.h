//#pragma once
//#include <iostream>
//#include "clsUser.h"
//#include "clsShowScreen.h"
//#include "clsInputValadate.h"
//class clsTransfer :protected clsShowScreen
//{
//
//private:
//
//	static void _PrintClientCard(clsBankClient Client)
//	{
//		cout << "\n\nClient Card";
//		cout << "\n_______________________\n\n";
//		cout << "Full Name : " << Client.FullName() << endl;
//		cout << "Acc.Number: " << Client.AccountNumber() << endl;
//		cout << "Balance   : " << Client.AccountBalance << endl;
//		cout << "_______________________\n";
//
//	}
//
//public:
//	static bool ShowTransferScreen()
//	{
//		_DrawScreenHeader("\t Transfer Screen ");
//
//		string AccountNumberFrom;
//		cout << "\nPlease Enter Account Number to Transfer From : ";
//		AccountNumberFrom = clsInputValidate::ReadString();
//
//		while (!clsBankClient::IsClientExist(AccountNumberFrom))
//		{
//			cout << "\nAccount number is not found, choose another one: ";
//			AccountNumberFrom = clsInputValidate::ReadString();
//		}
//		
//		clsBankClient Client = clsBankClient::Find(AccountNumberFrom);
//		_PrintClientCard(Client); 
//		
////		------------------------------------------------ 
//
//
//		string AccountNumberTo;
//		cout << "\nPlease Enter Account Number to Transfer to : ";
//		AccountNumberTo = clsInputValidate::ReadString();
//
//		while (!clsBankClient::IsClientExist(AccountNumberTo))
//		{
//			cout << "\nAccount number is not found, choose another one: ";
//			AccountNumberTo = clsInputValidate::ReadString();
//		}
//
//		clsBankClient Client2 = clsBankClient::Find(AccountNumberTo);
//		_PrintClientCard(Client2);
//
//
//		float Amount=0;
//		cout << "\nEnter The amount you want to transfer : ";
//		Amount = clsInputValidate::ReadFloatNumber();
//		char Answer ;
//
//		cout << "\nAre You are sure that you want to transfer ("<<Amount<<")[y,n]";
//		cin >> Answer;
//		if (Answer == 'y'||Answer=='Y')
//		{
//			 
//			Client.Withdraw(Amount);
//			Client2.Deposit(Amount);
//			cout << "\nSuccesfully operation\n";
//			_PrintClientCard(Client);
//			_PrintClientCard(Client2);
//		}
//
//		
//		else{
//			cout << "\nSomthing went wrong\n";
//		}
//
//
//	}
//};

#pragma once
#include <iostream>
#include "clsShowScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "Global.h"

class clsTransfer :protected clsShowScreen
{

private:
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________\n";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

    static string _ReadAccountNumber()
    {
        string AccountNumber;
        cout << "\nPlease Enter Account Number to Transfer From: ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }
        return AccountNumber;
    }

    static float _ReadAmount(clsBankClient SourceClient)
    {
        float Amount;

        cout << "\nEnter Transfer Amount? ";

        Amount = clsInputValidate::ReadFloatNumber();

        while (Amount > SourceClient.AccountBalance)
        {
            cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
            Amount = clsInputValidate::ReadDblNumber();
        }
        return Amount;
    }

  
    
public:

    static void ShowTransferScreen()
    {

        _DrawScreenHeader("\tTransfer Screen");

        clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber());

        _PrintClient(SourceClient);

        

        clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber());

        _PrintClient(DestinationClient);

        float Amount = _ReadAmount(SourceClient);


        cout << "\nAre you sure you want to perform this operation? y/n? ";
        char Answer = 'n';
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            if (SourceClient.Transfer(Amount, DestinationClient,CurrentUser.UserName))
            {
                cout << "\nTransfer done successfully\n";
            }
            else
            {
                cout << "\nTransfer Faild \n";
            }
        }

        _PrintClient(SourceClient);
        _PrintClient(DestinationClient);

      
    }

};

