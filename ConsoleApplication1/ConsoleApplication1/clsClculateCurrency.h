#pragma once

#include "clsCurrency.h"
#include "clsShowScreen.h"
#include "clsInputValidate.h"

using namespace std;

class clsClculateCurrency :protected clsShowScreen
{

private:

	static void _printpell(clsCurrency &Currency,string FromOrTo="Card")
	{
	

		cout<< FromOrTo << endl;
		cout << "\n\n====================================\n" << endl;
		cout << "Country :"  << Currency.Country()<<endl;
		cout << "Code    :"  << Currency.CurrencyCode() << endl;
		cout << "Name    :"  << Currency.CurrencyName() << endl;
		cout << "Rate($) :"  << to_string(Currency.Rate()) << endl;
		cout << "====================================\n\n" << endl;
	}

public:


	static void showClaculateCurrency()
	{

		_DrawScreenHeader("\t Currency Screen");
		char answer='n';

		do {

			
		string CurrencyCode1 = " ";
		cout << "\nPlease enter the Currency1 Code ?";
		CurrencyCode1 = clsInputValidate::ReadString();


		string CurrencyCode2 = " ";
		cout << "\nPlease enter the Currency2 Code ?";
		CurrencyCode2 = clsInputValidate::ReadString();


		float Amount;
		cout << "\nPlease enter the Amount ?";
		Amount = clsInputValidate::ReadFloatNumber();



		if (CurrencyCode2 == "usd" || CurrencyCode2 == "USD")
		{
			clsCurrency Currency1 = clsCurrency::FindByCode(CurrencyCode1);
			_printpell(Currency1, "Convert from");
			cout << Amount << " " << Currency1.CurrencyCode() << " = " << clsCurrency::CalculateCurrency(CurrencyCode1, Amount);
		}
		else
		{		
			clsCurrency Currency2 = clsCurrency::FindByCode(CurrencyCode2);
			float originalresult = clsCurrency::CalculateCurrency(CurrencyCode1, Amount) * (Currency2.Rate());
			_printpell(Currency2, "To:");
			cout << Amount << " " << Currency2.CurrencyCode() << " = " << originalresult;

		}

		cout << "\n\nDo you wnat to make a new operation [y,n] ? ";
		cin >> answer;

		} while (answer == 'y' || answer == 'Y');
	}






};

