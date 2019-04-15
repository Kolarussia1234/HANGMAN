//Nikolai Ovtsinnikov lõputöö(HANGMAN game) 2019
#include <iostream>
#include <cstdio>
#include <cstring>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

/*Olenevalt IDEst võivad include'id muutuda.
Näiteks VS 2015 pole vaja cstdio,cstring,stdlib.h,
kuid nt Codeblocksis läheb peaaegu kõiki neid vaja*/

using namespace std;

/*Globaalsed muutujad*/
const char chSecretWord[] = "uksikisikuenergiasoltumatus";
char chResult[30];
int iLength;

//Mitu korda võib vale olla
#define COUNT_ATTEMP 5

//Funktsioon mängu väljastamiseks
void drawScreen() {
	system("cls");
	cout << "\n\t\t*** HANGMAN game ***\n";
	cout << "\n\t\t******************\n";
	cout << "\n";

	cout << "\t\t   ";
	for (int i = 0; i < iLength; i++)
	{
		cout << chResult[i] << " ";
	}
	cout << "\n";
	cout << "\n\t\t******************\n";
}

/*MAIN*/
int main()
{
	//Vajalikud muutujad
	int iCountAttemp = 0; //Proovimiste arv
	bool bFound; //Kas sisestatud täht on õige või mitte
	char chInput; //Sisetatud täht
	int iCountCorrect = 0; //Õige vastuse indeks
	bool bPrevFound = false; //Kas samasugune täht on juba avatud

	iLength = strlen(chSecretWord);

	for (int i = 0; i < iLength; i++)
	{
		chResult[i] = '_';
	}
	drawScreen();

	/*MAIN LOOP*/
		while (iCountAttemp < COUNT_ATTEMP)
		{
			bFound = false;
			printf("\n\t\t Enter a letter: ");
			chInput = tolower(_getche());
			cout << endl;

			//Peamine võrdluse tsükkel
			for (int i = 0; i < iLength; i++) {
				if (chSecretWord[i] == chInput) { // Kas sisend vastab mingile tähele sõnas
					if (chSecretWord[i] == tolower(chResult[i])) { // Kas sisestatud täht on juba lahti või mitte
						cout << "\n\t\t" << chResult[i] << " Can't input same letter again!" << endl;
						bPrevFound = true;
						break;  // Kui on - lõpetab selle tsükli ja alustab MAIN LOOP uuesti
					}
					else {
						bFound = true; // Kõik on korras - sisestatud täht on õige
						chResult[i] = chInput;
						chResult[i] = toupper(chResult[i]);
						iCountCorrect++;
					}
				}
			}
			if (bPrevFound) {
				bPrevFound = false;
				continue;
			}

			//Joonistab mängu ekraanile
			drawScreen();

			/*Kui sisestatud täht on õige*/
			if (bFound) {
				printf("\n\t\t\'%c\' -> You are correct!", toupper(chInput));
				if (iLength - iCountCorrect > 1) {
					printf("\n\t\t%d letters to go!", iLength - iCountCorrect);  //Mitu tähte jäi
				}
				else if (iLength - iCountCorrect == 1) {
					printf("\n\t\t%d letter to go!", iLength - iCountCorrect);
				}
			}
			else {
				/*Kui sisestatud täht on vale*/

				iCountAttemp++;
				int iGuessLeft = COUNT_ATTEMP - iCountAttemp;

				printf("\n\t\t\'%c\' -> It's a wrong guess!", toupper(chInput));

				if (iGuessLeft > 1 && iGuessLeft < 5) {
					printf("\n\t\tYou have %d more guesses left", iGuessLeft); //Mitu kordust jäi
				}
				else if (iGuessLeft == 1) {
					printf("\n\t\tYou have %d more guess left", iGuessLeft);
				}
				else if (iGuessLeft == 0) {
					printf("\n\t\tYou have no guesses left");
				}
			}

			/*Võrdlus - kas võit või mitte*/
			if (iCountCorrect == iLength) {
				cout << "\n\t\t  YOU WON!\n\n";
				Sleep(3000); //Ootab 3 sekundit
				break;
			}
			if (iCountAttemp == COUNT_ATTEMP) {
				cout << "\n\t\t  YOU LOST!\n";
				cout << "\t\tYou have guesses all " << COUNT_ATTEMP << " times\n\n";

				cout << "\t\tDo you want to try again or exit? Y/N" << endl;
				char chExtInput;
				cout << "\t\t"; chExtInput = _getche();

				//Kas mängija tahab uuesti proovida või tahab mängu lõpetada
				if (chExtInput == 'Y' || chExtInput == 'y') {
					main();
				}
				else {
					cout << "\n\n\t\t  Good bye! \n\n";
					Sleep(3000); //Ootab 3 sekundit
					break;
				}
			}	
		}

	return 0;
}

