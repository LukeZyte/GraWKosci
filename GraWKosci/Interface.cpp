#include "Interface.h"

int minNicknameCharLong = 1;
int maxNicknameCharLong = 20;
int minNumOfParticipants = 2;
int maxNumOfParticipants = 4;

bool areOnlySpaces(string& word) {
    for (auto& letter : word) {
        if (letter != ' ')
            return false;
    }
    return true;
}

void mainTitle() {
    color(PRIMARY_COLOR);
    cout << "\n\t G R A   W   K O � C I\n";
    color(TEXT_COLOR);
	cout << "\t=======================\n\n";
}

void menuList(int selected) {
    color(TEXT_COLOR);
    mainTitle();
    cout << " Poruszaj si� po menu korzystaj�c z strza�ek g�ra / d� i klawisza Enter\n\n";
    if (selected == 1)
        color(PRIMARY_COLOR);
    else color(NS_TEXT_COLOR);
    cout << " 1. Rozpocznij gr� dla 2 graczy\n";

    if (selected == 2)
        color(PRIMARY_COLOR);
    else color(NS_TEXT_COLOR);
    cout << " 2. Rozpocznij gr� dla 3 graczy\n";

    if (selected == 3)
        color(PRIMARY_COLOR);
    else color(NS_TEXT_COLOR);
    cout << " 2. Rozpocznij gr� dla 4 graczy\n";

    if (selected == 4)
        color(PRIMARY_COLOR);
    else color(NS_TEXT_COLOR);
    cout << " 3. Wyjd� z gry\n\n";
    color(PRIMARY_COLOR);

    if (selected == 1) {
        cout << " Nowa rozgrywka w ko�ci dla 2 graczy \n";
    }
    else if (selected == 2) {
        cout << " Nowa rozgrywka w ko�ci dla 3 graczy \n";

    }
    else if (selected == 3) {
        cout << " Nowa rozgrywka w ko�ci dla 4 graczy \n";

    }
    else if (selected == 4) {
        cout << " Prosz�, zosta� jeszcze na jedn� gr� ;)\n";
    }
}

void newGame(int numOfParticipants) {
    int numOfRounds = 1;
    vector<Participant> participants;
    vector<string> takenNicknames;

    // Number of players and their nicknames
    system("cls");
    color(TEXT_COLOR);

    string nickname;
    for (int i = 0; i < numOfParticipants; i++) {
        cout << "\n Nazwa " << i + 1 << " gracza (od " << minNicknameCharLong << " do " << maxNicknameCharLong << " znak�w): ";
        color(PRIMARY_COLOR);
        getline(cin, nickname);
        color(TEXT_COLOR);
        if (nickname.length() < minNicknameCharLong || nickname.length() > maxNicknameCharLong || areOnlySpaces(nickname)) {
            cout << "\n Wprowadzono nieprawid�ow� nazw�!\n\n";
            i--;
        }
        else if (std::count(takenNicknames.begin(), takenNicknames.end(), nickname)) { // nickname already exists in the vector
            cout << "\n Nazwa ju� zaj�ta! Wprowad� inn�.\n\n";
            i--;
        }
        else {
            Participant participant(nickname);
            participants.push_back(participant);
            takenNicknames.push_back(nickname);
        }
    }

    system("cls");
    color(PRIMARY_COLOR);
    cout << "\n   Zasady gry:\n";
    color(TEXT_COLOR);
    cout << " Ka�dy z graczy rzuca 5 ko��mi, by uzyska� okre�lone uk�ady oczek, za kt�re zdobywa si� punkty.\n"
        << " Pierwszy rzut odbywa si� zawsze wszystkimi kostkami. Przy nast�pnych dw�ch nieobowi�zkowych rzutach gracz  \n"
        << " mo�e wybra� ze wszystkich kostki zatrzymane, a niezatrzymanymi wykonuje rzut.\n"
        << " Celem rzut�w w kolejce jest uzyskanie odpowiedniej kombinacji (ich uk�ad mo�na wy�wietli� podczas gry\n"
        << " wciskaj�c klawisz 'h'). Po wykonaniu rzut�w uzyskany uk�ad oczek zostaje zapisany do odpowiedniej kategorii.\n"
        << " Raz wybrana kategoria nie mo�e zosta� u�yta ponownie.\n"
        << " Koniec gry nast�puje z chwil� u�ycia ostatniej kategorii w tabelce. Wygrywa gracz z najwi�ksz� liczb� punkt�w.\n\n";
    color(PRIMARY_COLOR);
    cout << " Kliknij Enter aby rozpocz�� gr�!";
    color(TEXT_COLOR);

    while (true) {
        if (_getch() == KEY_ENTER) {
            system("cls");
            break;
        }
    }

    Game game(participants);
    game.initGame();

    // after game ends
    Interface::mainMenu();
}

void Interface::mainMenu() {
    system("cls");

    int selected = 1;       // Which option is selected.
    int numChoices = 4;     // The number of available choices.
    bool selecting = true;  // True if we are still waiting for the user to press enter.
    bool updated = true;    // True if the selected value has just been updated.

    menuList(selected);

    char key; 
    do {
        switch ((key = _getch())) { //Check inputed key character.
        case KEY_UP:
            if (selected > 1) { 
                --selected;
                updated = true;
            }
            break;
        case KEY_DOWN:
            if (selected < numChoices) { 
                ++selected;
                updated = true;
            }
            break;
        case KEY_ENTER:
            selecting = false;
            break;
        default: break;
        }

        if (updated) { 
            system("cls");
            menuList(selected);
            updated = false;
        }
    } while (selecting);

    // Result
    if (selected == 1)
        newGame(2);
    else if (selected == 2)
        newGame(3);
    else if (selected == 3)
        newGame(4);
    else if (selected == 4)
        exit(0);
}

