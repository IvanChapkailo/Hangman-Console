#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

int main()
{
	char playAgain = 'n';
	do
	{
		const int MAX_WRONG = 8;//допустима кількість помилок
		vector<string> words;
		words.push_back("AUSTRALIA");
		words.push_back("FOOTBALL");
		words.push_back("BOXING");
		words.push_back("CAR");
		words.push_back("UKRAINE");

		srand(static_cast<unsigned int>(time(NULL)));
		random_shuffle(words.begin(), words.end());
		const string THE_WORD = words[0];//слово для відгадування
		int wrong = 0;//кількість помилок
		string guessed(THE_WORD.size(), '-');//частина слова, відкрита на даний момент
		string used = "";//вже використані букви
		cout << "\tWelcome to Hangman\n" << endl;

		//main cycle
		while ((wrong < MAX_WRONG) && (guessed != THE_WORD))
		{
			cout << "You have " << (MAX_WRONG - wrong) << " incorrect guesses left." << endl;
			if (!used.empty())
				cout << "You have used the following letters:" << used << endl;
			cout << "The word is:\n" << guessed << endl;

			char guess;
			cout << "Enter you guess:" << endl;
			cin >> guess;
			guess = toupper(guess);//перевід у верхній регістр
			while (used.find(guess) != string::npos)//якщо вже вводили таку букву
			{
				cout << "You have already guessed " << guess << endl;
				cout << "Enter you guess:" << endl;
				cin >> guess;
				guess = toupper(guess);//перевід у верхній регістр
			}
			used += guess;
			if (THE_WORD.find(guess) != string::npos)//якщо буква вгадана
			{
				cout << "That's right! " << guess << " is in the word." << endl;
				//оновити змінну guessed, включивши вгадану букву
				for (int i = 0; i < THE_WORD.length(); i++)
				{
					if (THE_WORD[i] == guess)
						guessed[i] = guess;
				}
			}
			else
			{
				cout << "Sorry, " << guess << " isn't in the word." << endl;
				++wrong;
			}
		}
		//game over
		if (wrong == MAX_WRONG)
			cout << "__________________________________\nYou've been hanged! Game over!" << endl;
		else
			cout << "__________________________________\nYou guessed it! The word was " << THE_WORD << endl;
		//play again
		cout << "Play again? (y/n) - ";
		cin >> playAgain;
		if (playAgain == 'y')
		{
			system("cls");
			//cout << "\e[1;1H\e[2J";
		}
		else
			break;
	} while (playAgain == 'y');
	if (playAgain == 'n')
		return 0;
}