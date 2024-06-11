#pragma once
#include "clsCurrency.h"
#include "clsShowScreen.h"
#include "clsInputValidate.h"

class clsUpdateCurrency :protected clsShowScreen
{

private :



	static void _PrintCurrencyCard(clsCurrency& Currency)
	{
		// Print Print Country Card will be here

		cout << "" << "\nCurrency Card\n";
		cout << "" << "===========================================\n";
		cout << "" << "Country :" << Currency.Country();
		cout << "\n" << "Currency:" << Currency.CurrencyCode();
		cout << "\n" << "Code    :" << Currency.CurrencyName();
		cout << "\n" << "Rate    :" << Currency.Rate();
		cout << "\n" << "===========================================\n";
	}




public:


	static void ShowUpdateCurrencyScreen()
	{

		string Currency;
		cout << "\nPlease enter the Currency you want to Update ?";
		Currency = clsInputValidate::ReadString();


		while (!clsCurrency::IsCurrencyExist(Currency))
		{
			cout << "\nThe Currency you is not Found ?";
			Currency = clsInputValidate::ReadString();
		}


		clsCurrency CurrencyCode = clsCurrency::FindByCode(Currency);

		_PrintCurrencyCard(CurrencyCode);


		float NewRate;
		cout << "\nEnter The New Rate ?";
		NewRate = clsInputValidate::ReadFloatNumber();



		CurrencyCode.UpdateRate(NewRate);
		cout << "\nUpdated Successfully ?-:)\n";
		_PrintCurrencyCard(CurrencyCode);



	}


















};

