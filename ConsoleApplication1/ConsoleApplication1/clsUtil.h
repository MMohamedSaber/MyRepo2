#pragma once

#include<iostream>
#include "clsDate.h";
using namespace std;


class clsUtil
{

private:



public:

	// enCrypt and Decrypt text
	static string enCryptText(string Text, short encryptionKey=2)
	{

		for (int i = 0; i <= Text.length(); i++)
		{

			Text[i] = char((int)Text[i] + encryptionKey);// The Type integer here to plus on encryptionKey


		}
		return Text;

	}
	static string DecryptinText(string Text, short encryptionKey=2)
	{

		for (int i = 0; i <= Text.length(); i++)
		{

			Text[i] = char((int)Text[i] - encryptionKey);// The Type integer here to plus on encryptionKey


		}
		return Text;
	}


	//Random Number
	static int RandomNumber(int From, int To) {
		//Function to generate a random numberint randNum = 
		int randNum = rand() % (To - From + 1) + From;

		return randNum;
	}
	static void Srand()
	{
		srand((unsigned)time(NULL));
	}

    // get Random Caracter 
	static enum enRandomCharcter {
		Capital = 0,
		Samall = 1,
		Mix = 2,
		Digit = 3
	};
	static char GetRandomCharcter(enRandomCharcter Chosecharcter)
	{
		switch (Chosecharcter)
		{

		case enRandomCharcter::Capital:
			return char(RandomNumber(65, 90));
			break;

		case enRandomCharcter::Samall:
			return char(RandomNumber(97, 122));
			break;

		case enRandomCharcter::Mix :
			return char(RandomNumber(1, 100));
			break;

		case enRandomCharcter::Digit:
			return char(RandomNumber(47, 57));
			break;

		}

	}

	// Swap Numbers
	static void sawap(int& A, int& B)
	{
		int temp;

		temp = A;
		A = B;
		B = temp;

	}

	// Fill Array with Number
	static void FillArraywithNumber(int arr[100], int arrLength)
	{
		int counter = 0;
		for (int i = 0; i < arrLength; i++) {

			arr[i] = counter;
			counter++;
		}
	}

	//print Arry
	static void PrintArray(int Arr[100], int ArrLength)
	{
		for (int i = 0; i < ArrLength; i++)
		{


			cout << Arr[i] << " ";

		}
	}

	//shuffl array
   static void  ShufflsArray(int Arr[100], int ArrLength)
	{
		for (int i = 0; i < ArrLength; i++)
		{

			sawap(Arr[RandomNumber(1, ArrLength)], Arr[RandomNumber(1, ArrLength)]);
		}

	}

   //fill Array with random Number
   static void FillArrayWithRandomNumbers(int arr[100], int arrLength)
   {
	  
	   for (int i = 0; i < arrLength; i++)

		   arr[i] = RandomNumber(1, 100);

   }

   //Print sum of two numbers in same position between two arrays
   static  void PrintSumOfNumberTwoArray(int Arr[100], int Arr2[100], int ArrLength)
   {
	   for (int i = 0; i < ArrLength; i++)
	   {

		   cout << Arr[i] + Arr2[i] << " ";
	   }

   }

   //sum All Numbers inside array
  static  int SumNumberInArray(int arr[], int arrLength) {
	   int Sum = 0;

	   for (int i = 0; i < arrLength; i++)
	   {

		   Sum += arr[i];

	   }

	   return Sum;
   }

  // array average
  static int ArrAverage(int arr[100], int ArrLength)
  {
	    return (float)SumNumberInArray(arr, ArrLength) / ArrLength;
  }

 //Genarate Word
  static string GenarateWord(enRandomCharcter enRandomType, short length)
  {

	  string word;

	  for (int i = 0; i <= length; i++)
	  {

		  word = word + GetRandomCharcter(enRandomType);
	  }
	  return word;
  }

  //Genarate Keys of words
  static  string GenaratKeys()

  {
	  
	  string key = "";

	  key = GenarateWord(enRandomCharcter::Capital, 4) + "-";
	  key = key + GenarateWord(enRandomCharcter::Capital, 4) + "-";
	  key = key + GenarateWord(enRandomCharcter::Capital, 4) + "-";
	  key = key + GenarateWord(enRandomCharcter::Capital, 4);

	  return key;
  }

  //Fill Key In Array
  static void FillKeyInArray(string Arr[100], int KeyLength)

  {
	  for (int i = 0; i <= KeyLength; i++)
	  {

		  Arr[i] = GenaratKeys();
	  }
  }

  // Tabs
  static string  Tabs(short NumberOfTabs)
  {
	  string t = "";

	  for (int i = 1; i < NumberOfTabs; i++)
	  {
		  t = t + "\t";
		  cout << t;
	  }
	  return t;

  }

  static string NumbertoText(int Number)
  {
	  if (Number == 0)
	  {
		  return "";
	  }

	  if (Number >= 1 && Number <= 19)
	  {
		  string arr[] = { "","one","tow","three","four","five","six","seven","eight","Nighn","Ten",
			  "Eleven","Twelve","Thirteen","fourteen","fivteen","Sixteen","Seventeen","Eighteen","Nighnteen" };

		  return arr[Number] + " ";
	  }
	  if (Number >= 20 && Number <= 99)
	  {
		  string arr[] = { "","","Twenty" ,"Thirty" ,"Fourty" ,"Fifty" ,"Sixty" ,"Seventy" ,"Eighty" ,"Nighnty" };

		  return arr[Number / 10] + " " + NumbertoText(Number % 10);

	  }
	  if (Number >= 100 && Number <= 199)
	  {
		  return "One Hundered " + NumbertoText(Number % 100);
	  }
	  if (Number >= 200 && Number <= 999)
	  {
		  return NumbertoText(Number / 100) + "Hundreds" + NumbertoText(Number % 100);

	  }
	  if (Number >= 1000 && Number <= 1999)
	  {
		  return "One Thousand " + NumbertoText(Number % 1000);

	  }if (Number >= 2000 && Number <= 999999)
	  {
		  return  NumbertoText(Number / 1000) + " Thousands " + NumbertoText(Number % 1000);

	  }

	  if (Number >= 1000000 && Number <= 1999999)
	  {
		  return   "One Milion " + NumbertoText(Number % 1000000);

	  }if (Number >= 2000000 && Number <= 999999999)
	  {
		  return   NumbertoText(Number / 1000000) + " Milion " + NumbertoText(Number % 1000000);

	  }
	  if (Number >= 1000000000 && Number <= 1999999999)
	  {
		  return    "One Bilion " + NumbertoText(Number % 1000000000);

	  }
	  else
	  {
		  return NumbertoText(Number % 1000000000) + " One Bilion ";
	  }
  }

  //static string DecryptinText(string Text, short encryptionKey = 2)
  //{
	 // 

	 // for (int i = 0; i <= Text.length(); i++)
	 // {

		//  Text[i] = char((int)Text[i] - encryptionKey);// The Type integer here to plus on encryptionKey


	 // }
	 // return Text;
  //}

  //static string enCryptText(string Text, short encryptionKey = 2)
  //{

	 // for (int i = 0; i <= Text.length(); i++)
	 // {

		//  Text[i] = char((int)Text[i] + encryptionKey);// The Type integer here to plus on encryptionKey


	 // }
	 // return Text;

  //}
};

