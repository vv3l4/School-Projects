#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
    srand(time(0));
    char userResponse;
    int userMoney = 10;

    cout << "Do You Wish to Play? ('Y' or 'y')" << endl;
    cin >> userResponse;

    while (userMoney > 0) {
        if (userResponse == 'Y' || userResponse == 'y') {
            string collectedNumbers;

            for (int i = 0; i < 3; i++) {
                int randomNumber = rand() % 4;

                if (randomNumber == 0) {
                    collectedNumbers = collectedNumbers + "7";
                } else if (randomNumber == 1) {
                    collectedNumbers = collectedNumbers + "$";
                } else if (randomNumber == 2) {
                    collectedNumbers = collectedNumbers + "#";
                } else if (randomNumber == 3) {
                    collectedNumbers = collectedNumbers + "X";
                }
            }

            cout << collectedNumbers << endl;

            if (collectedNumbers == "777") {
                cout << "+100" << endl;
                userMoney = userMoney + 100;
                cout << "Current Money: " << userMoney << endl;
            } else if (collectedNumbers == "$$$") {
                cout << "+50" << endl;
                userMoney = userMoney + 50;
                cout << "Current Money: " << userMoney << endl;
            } else if (collectedNumbers == "###") {
                cout << "+25" << endl;
                userMoney = userMoney + 25;
                cout << "Current Money: " << userMoney << endl;
            } else if (collectedNumbers == "XXX") {
                cout << "+10" << endl;
                userMoney = userMoney + 10;
                cout << "Current Money: " << userMoney << endl;
            } else {
                userMoney = userMoney - 1;
                cout << "Current Money: " << userMoney << endl;
            }

            cout << "Do You Wish to Play Again?" << endl;
            cin >> userResponse;

        } else if (userResponse == 'N' || userResponse == 'n'){
            cout << "Good Bye!" << endl;
            cout << "Total Money: " << userMoney << endl;
            break;
        } else {
            cout << "Error: Must type either 'Y' or 'N'." << endl;
            break;
        }
    }
    return 0;
}
