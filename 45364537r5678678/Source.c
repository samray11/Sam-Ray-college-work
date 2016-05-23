#include <string.h>
#include <stdio.h>
#include <conio.h>
long long cardnumber;
int NumberofDigits;
int cardnumberarray[16];
int firstdigit;
int CardTypeID;
int menu;



int EnterNumber()
{
	printf("Enter a 15 or 16 digit card number\n");// Prints the text within the ""
	scanf_s("%lld", &cardnumber);//scans users input
	return 0;
}

void help()
{
	printf(" 1: starts program 2: help, 3: quits the application\n");
	scanf_s("%d", &menu);
	switch (menu)
	{
	case 1:
		break;
	case 2:
		printf("instructions:\n");
		help();
		break;
	case 3:
		exit(exit);
		break;
	}

}

int checkNoOfDigits()
{
	if (cardnumber > 99999999999999 && cardnumber < 1000000000000000) //checks cardnumber is 15 digits
		return 15;

	if (cardnumber > 999999999999999 && cardnumber < 10000000000000000) //checks cardnumber is 16 digits
		return 16;
	else
	{
		printf("You have enter a invalid number\n"); // prints the text in the ""
		main();
		return 0;
	}
}

int convertToArray()
{
	int y;
	int i = 0;//number variable
	while (cardnumber / 10 > 0)//begins loop for converting the number to an array
	{
		cardnumberarray[i] = cardnumber % 10;
		cardnumber = cardnumber / 10;
		i++;// each time there is a loop 1 will be added until it reaches 10 and the loop ends 

	}
	cardnumberarray[i] = cardnumber;
	y = NumberofDigits - 1;
	firstdigit = cardnumberarray[y];

	return 0;

}

int cardType()
{

	switch (firstdigit)
	{
	case 1:
		printf("Airlines card\n");
		break;

	case 2:
		printf("Airlines and future industry assignments identifier\n");
		break;

	case 3:
		printf("Travel, entertainment and financial identifier\n");
		break;

	case 4:
		printf("financial idenifier\n");
		break;

	case 5:
		printf("financial identifier\n");
		break;

	case 6:
		printf(" Merchandising and financial identifier\n");
		break;

	case 7:
		printf("Petroleum and other future industry assignments identifier\n");
		break;

	case 8:
		printf("Healthcare, telecommunications and future industry assignments identifier\n");
		break;

	case 9:
		printf("National assignment identifier \n");
		break;

	default:
		printf("no type");
		break;


	}
	return 0;
}
/*
American Express: 34xxxx, 37xxxx
Discover: 6011xx, 644xxx, 65xxxx
MasterCard: 50xxxx - 55xxxx (in that range inclusive)
Visa: 4xxxxx
*/
int cardTypeID()
{
	// ***AMERICAN EXPRESS***
	if (NumberofDigits == 15)
	{
		if ((cardnumberarray[14] == 3 && cardnumberarray[13] == 4) || (cardnumberarray[14] == 3 && cardnumberarray[13] == 7)) // Looking for the numbers 34 or 37 for a 15 digit number
			CardTypeID = 1;
	}
	else {
		if ((cardnumberarray[15] == 3 && cardnumberarray[14] == 4) || (cardnumberarray[15] == 3 && cardnumberarray[14] == 7)) // looking for the numbers 34 or 37 for a 16 digit number
			CardTypeID = 1;
	}
	// ***DISCOVER***
	if (NumberofDigits == 15)
	{
		if ((cardnumberarray[14] == 6 && cardnumberarray[13] == 0 && cardnumberarray[12] == 1 && cardnumberarray[11] == 1) || (cardnumberarray[14] == 6 && cardnumberarray[13] == 4 && cardnumberarray[12] == 4) || (cardnumberarray[14] == 6 && cardnumberarray[13] == 5))
			CardTypeID = 2; //Looking for the number 6011 for a 15 digit number
	}
	else {
		if ((cardnumberarray[15] == 6 && cardnumberarray[14] == 0 && cardnumberarray[13] == 1 && cardnumberarray[12] == 1) || (cardnumberarray[15] == 6 && cardnumberarray[14] == 4 && cardnumberarray[13] == 4) || (cardnumberarray[15] == 6 && cardnumberarray[14] == 5))
			CardTypeID = 2; //Looking for the number 6011 for a 16 digit number
	}
	// ***VISA***
	if (NumberofDigits == 15)
	{
		if (cardnumberarray[14] == 4) //looking for the number 4
			CardTypeID = 3;
	}
	else {
		if (cardnumberarray[15] == 4)//looking for the number 4
			CardTypeID = 3;
	}
	// ***MASTER CARD***
	if (NumberofDigits == 15)
	{
		if ((cardnumberarray[14] == 5 && cardnumberarray[13] == 0) || (cardnumberarray[14] == 5 && cardnumberarray[13] == 1) || (cardnumberarray[14] == 5 && cardnumberarray[13] == 2) || (cardnumberarray[14] == 5 && cardnumberarray[13] == 3) || (cardnumberarray[14] == 5 && cardnumberarray[13] == 4) || (cardnumberarray[14] == 5 && cardnumberarray[13] == 5))
			CardTypeID = 4; // searching for numbers in the range of 50-55
	}
	else {
		if ((cardnumberarray[15] == 5 && cardnumberarray[14] == 0) || (cardnumberarray[15] == 5 && cardnumberarray[14] == 1) || (cardnumberarray[15] == 5 && cardnumberarray[14] == 2) || (cardnumberarray[15] == 5 && cardnumberarray[14] == 3) || (cardnumberarray[15] == 5 && cardnumberarray[14] == 4) || (cardnumberarray[15] == 5 && cardnumberarray[14] == 5))
			CardTypeID = 4; // searching for numbers in the range of 50-55
	}
	return 0;
}

int PrintCardType()
{
	if (CardTypeID == 1)
		printf("American Express\n"); // prints out the text in the ""

	if (CardTypeID == 2)
		printf("Discover\n"); // prints out the text in the ""

	if (CardTypeID == 3)
		printf("Visa\n"); // prints out the text in the ""

	if (CardTypeID == 4)
		printf("MasterCard\n"); // prints out the text in the ""

	return 0;
}

int luhnstest()
{
	int i = 0;// declares variable

	int sum = 0;//declares variable 

	for (i = 1; i < NumberofDigits; i++)//loops until i greater than the number of digits 
	{
		if (i % 2 != 0)//if i is divisible by 2 it will go to the next digit in the array
		{
			cardnumberarray[i] = cardnumberarray[i] * 2;// multiplies by 2

			if (cardnumberarray[i] > 9)//checks that it is greater than 10
			{
				cardnumberarray[i] = (cardnumberarray[i] % 10) + (cardnumberarray[i] / 10);
			}
		}
	}
	for (i = 0; i < NumberofDigits; i++)//loop starts and will end when i is smaller than the number of digits 
	{
		sum += cardnumberarray[i];//adds the numbers together
	}
	if (sum % 10 == 0)//checks that the sum is divisible by 10
	{
		printf("valid number\n");//prints the text if it is divisible by 10

		PrintCardType();
	}
	else
	{
		printf("invalid number\n");//if not then print the following statement
	}


	return 0;

}

int main()
{
	help();
	EnterNumber();
	NumberofDigits = checkNoOfDigits();//assigns the checknumberofdigits to the numberdigits variable and also calls the check number of digits function
	if (NumberofDigits == 15 || NumberofDigits == 16){//checks that the number entered is 15 or 16 digits
		printf("valid number of digits\n");//prints the text in the "" the number is either 15 or 16 digits
	}
	else {
		printf("invalid number of digits\n");// prints the text in the ""
	}


	convertToArray();
	cardTypeID();
	luhnstest();
	cardType();

	_getch();
	return 0;

}