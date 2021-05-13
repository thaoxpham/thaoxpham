
#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<iomanip>
using namespace std;

void tourP (string[], float[]);
void displayTour(string[]);
void getChoice(int[], string[], int[], int&);
void displayBill(string[], string[], int[], float[], int );
const int SIZE = 2;
const int TOUR = 10;

int main()
{
    string tours[SIZE], nameGuest[TOUR];
    float prices[SIZE];
    int tourN[TOUR],
        numP[TOUR],
        counter1 = 0;

    tourP(tours, prices);
    displayTour(tours);
    getChoice(tourN, nameGuest, numP, counter1);
    displayBill(nameGuest, tours, numP, prices, counter1);

    return 0;
}

void tourP(string tour[], float price[])
{
    cout << "MT. HOOD SKI TOURS\n\n";
    for (int i = 0; i < SIZE; i++)
    {
            cout << "Enter the name of the tour: ";
            getline(cin, tour[i]);
            cout << "Enter the price for " << tour[i] << ": ";
            cin >> price[i];
            cin.ignore(100000, '\n');
    }
    system("CLS");
    return;
}

void displayTour(string tour[])
{
    cout << "MT. HOOD SKI TOURS\n\n";
    for (int i = 0; i < SIZE; i++)
    {
        cout << i + 1 << " - " << tour[i] << endl;
    }
    cout << "0 - finished entering orders\n\n";
}

void getChoice(int tourNum[], string name[], int numPel[], int& counter)
{
    int j;
    counter = 0;

    for (int j = 0; j < TOUR; j++)
    {
        do
        {
          cout << "Enter the number of the tour you would like: ";
        cin >> tourNum[j];

        if (tourNum[j] > SIZE)
        {
            cout << "Enter the number of the tour you would like: ";
            cin >> tourNum[j];
        }

        else if (tourNum[j] > 0 && tourNum[j] <= SIZE)
        {
            cout << "What is your name? ";
            cin >> name[j];
            cout << "How many people will come? (1-10) ";
            cin >> numPel[j];
            counter++;
        }
        } while (tourNum[j] != 0);
        break;
    }
    system("CLS");
}

void displayBill(string name[], string tour[], int numPel[], float price[], int counter)
{
    for (int i = 0; i < counter; i++)
    {
        cout << "MT. HOOD SKI TOURS\n\n";
        cout << setw(6)<< "Customer:" << name[i];
        cout << setw(6)<< "\nYour tour:" << tour[i];
        cout << setw(6)<< "\n# Guests:" << numPel[i];
        cout << setw(6)<< "\nPrice each:" << price[i];
        cout << setw(6)<< "\n\nTOTAL:" << price[i] * numPel[i];
        cout << "\nPress Enter to see the next bill...\n\n";
        system("PAUSE");
        system("CLS");
    }

}

