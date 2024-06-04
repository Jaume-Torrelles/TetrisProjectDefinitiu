#include "Menu.h"

const char* menuItems[MENU_SIZE] = { "Play", "Test", "Leaderboard", "Exit" }; // Define the menu items array

void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void printCenteredText(const char* text, int line, int consoleWidth) {
	int textLength = strlen(text);
	int textX = (consoleWidth - textLength) / 2;
	gotoxy(textX, line);
	std::cout << text;
}

void drawMenu(int selected, int consoleWidth, int consoleHeight) {
	system("cls");

	// Calculate the center position for menu
	int centerX = consoleWidth / 2;
	int menuHeight = MENU_SIZE * 2; // Height of each menu item is 2 lines
	int centerY = (consoleHeight - menuHeight) / 2; // Adjusted for centering

	for (int i = 0; i < MENU_SIZE; ++i) {
		gotoxy(centerX - strlen(menuItems[i]) / 2, centerY + i * 2);
		if (i == selected) {
			// Change color for selected item to crimson red
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			std::cout << "-> " << menuItems[i] << std::endl;
		}
		else {
			// Default color for other items
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			std::cout << "   " << menuItems[i] << std::endl;
		}
	}
}

void loadingAnimation(int consoleWidth, int consoleHeight, int time) {
	const char* loadingText[] = {
		"   ▄▄▄▄███▄▄▄▄      ▄████████    ▄██████▄     ▄████████          ███        ▄████████     ███        ▄████████  ▄█     ▄████████ ",
		" ▄██▀▀▀███▀▀▀██▄   ███    ███   ███    ███   ███    ███      ▀█████████▄   ███    ███ ▀█████████▄   ███    ███ ███    ███    ███ ",
		" ███   ███   ███   ███    █▀    ███    █▀    ███    ███         ▀███▀▀██   ███    █▀     ▀███▀▀██   ███    ███ ███▌   ███    █▀  ",
		" ███   ███   ███  ▄███▄▄▄      ▄███          ███    ███          ███   ▀  ▄███▄▄▄         ███   ▀  ▄███▄▄▄▄██▀ ███▌   ███        ",
		" ███   ███   ███ ▀▀███▀▀▀     ▀▀███ ████▄  ▀███████████          ███     ▀▀███▀▀▀         ███     ▀▀███▀▀▀▀▀   ███▌ ▀███████████ ",
		" ███   ███   ███   ███    █▄    ███    ███   ███    ███          ███       ███    █▄      ███     ▀███████████ ███           ███ ",
		" ███   ███   ███   ███    ███   ███    ███   ███    ███          ███       ███    ███     ███       ███    ███ ███     ▄█    ███ ",
		"  ▀█   ███   █▀    ██████████   ████████▀    ███    █▀          ▄████▀     ██████████    ▄████▀     ███    ███ █▀    ▄████████▀  ",
		"                                                                                                                                 ",
		"                              ▀█████████▄     ▄████████    ▄████████  ▄███████▄   ▄█   ▄█                                        ",
		"                                ███    ███   ███    ███   ███    ███ ██▀     ▄██ ███  ███                                        ",
		"                                ███    ███   ███    ███   ███    ███       ▄███▀ ███▌ ███                                        ",
		"                               ▄███▄▄▄██▀   ▄███▄▄▄▄██▀   ███    ███  ▀█▀▄███▀▄▄ ███▌ ███                                        ",
		"                              ▀▀███▀▀▀██▄  ▀▀███▀▀▀▀▀   ▀███████████   ▄███▀   ▀ ███▌ ███                                        ",
		"                                ███    ██▄ ▀███████████   ███    ███ ▄███▀       ███  ███                                        ",
		"                                ███    ███   ███    ███   ███    ███ ███▄     ▄█ ███  ███▌    ▄                                  ",
		"                              ▄█████████▀    ███    ███   ███    █▀   ▀████████▀ █▀   █████▄▄██                                  "
	};

	int loadingTextLength = sizeof(loadingText) / sizeof(loadingText[0]);
	int startY = (consoleHeight - loadingTextLength) / 2;

	system("cls");
	// Slowly display the loading text
	for (int i = 0; i < loadingTextLength; ++i) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		printCenteredText(loadingText[i], startY + i, consoleWidth);
		std::this_thread::sleep_for(std::chrono::milliseconds(10)); // Typing effect faster
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(time));
}

void exitAction() {
	system("cls");
	const char* goodbyeText[] = {
		" _    _                    _            __                       _                _               ",
		"| |  | |                  | |          / _|                     | |              (_)              ",
		"| |_ | |__    __ _  _ __  | | __ ___  | |_   ___   _ __   _ __  | |  __ _  _   _  _  _ __    __ _ ",
		"| __|| '_ \\  / _` || '_ \\ | |/ // __| |  _| / _ \\ | '__| | '_ \\ | | / _` || | | || || '_ \\  / _` |",
		"| |_ | | | || (_| || | | ||   < \\__ \\ | |  | (_) || |    | |_) || || (_| || |_| || || | | || (_| |",
		" \\__||_| |_| \\__,_||_| |_||_|\\_\\|___/ |_|   \\___/ |_|    | .__/ |_| \\__,_| \\__, ||_||_| |_| \\__, |",
		"                                                         | |                __/ |            __/ |",
		"                                                         |_|               |___/            |___/ "
	};
	const char* heart = "<3";
	int goodbyeTextLength = sizeof(goodbyeText) / sizeof(goodbyeText[0]);

	// Get console dimensions
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	int consoleHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	int startY = (consoleHeight - goodbyeTextLength) / 2;

	// Slowly display the loading text
	for (int i = 0; i < goodbyeTextLength; ++i) {
		printCenteredText(goodbyeText[i], startY + i, consoleWidth);
		std::this_thread::sleep_for(std::chrono::milliseconds(10)); // Typing effect faster
	}

	// Loop to change text color rapidly and display goodbye message for 3 seconds
	auto startTime = std::chrono::steady_clock::now();
	while (std::chrono::steady_clock::now() - startTime < std::chrono::seconds(3)) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), rand() % 15 + 1); // Change color rapidly
		// Display the goodbye text
		for (int i = 0; i < goodbyeTextLength; ++i) {
			printCenteredText(goodbyeText[i], startY + i, consoleWidth);
		}
		// Randomly display multiple "<3" symbols on the screen
		for (int i = 0; i < 5; ++i) {
			int heartX = rand() % consoleWidth;
			int heartY = rand() % consoleHeight;
			gotoxy(heartX, heartY);
			std::cout << heart;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(50)); // Change color every 50 milliseconds
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED); // Reset text color
}

void increaseConsoleWindowSize() {
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 800, 600, TRUE); // Increase console window size
}

void getConsoleDimensions(int& consoleWidth, int& consoleHeight) {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	consoleHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

int handleMenu() {
	increaseConsoleWindowSize();

	int consoleWidth, consoleHeight;
	getConsoleDimensions(consoleWidth, consoleHeight);

	loadingAnimation(consoleWidth, consoleHeight, 1000);

	int selected = 0;
	bool exitMenu = false;

	while (!exitMenu) {
		drawMenu(selected, consoleWidth, consoleHeight);
		switch (_getch())
		{
		case 72: // up arrow
			selected = (selected - 1 + MENU_SIZE) % MENU_SIZE;
			break;
		case 80: // down arrow
			selected = (selected + 1) % MENU_SIZE;
			break;
		case 13: // enter key
			loadingAnimation(consoleWidth, consoleHeight, 300);
			exitMenu = true;
			break;
		default:
			break;
		}
	}
	return selected;
}