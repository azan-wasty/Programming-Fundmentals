#pragma comment(lib, "winmm.lib")
#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include <fstream>
#include <chrono>
#include "snakehelp.h"

using namespace std;

const int MAX_HIGH_SCORES = 5; // Number of top high scores 
struct HighScore {
    string playerName;
    int score;
};


HighScore infiniteScores[MAX_HIGH_SCORES];
HighScore levelScores[MAX_HIGH_SCORES];
HighScore customScores[MAX_HIGH_SCORES];

const string INFINITE_FILE = "infinite_high_scores.txt";
const string LEVEL_FILE = "level_high_scores.txt";
const string CUSTOM_FILE = "custom_high_scores.txt";


void displayHighScores() {
    system("CLS");
    gotoxy(10, 2);
    cout << "HIGH SCORES\n";

    gotoxy(10, 4);
    cout << "Endless Mode:\n";
    for (int i = 0; i < MAX_HIGH_SCORES; i++) {
        gotoxy(12, 5 + i);
        if (!infiniteScores[i].playerName.empty()) {
            cout << i + 1 << ". " << infiniteScores[i].playerName << " - " << infiniteScores[i].score;
        }
        else {
            cout << i + 1 << ". ---";
        }
    }

    gotoxy(10, 10);
    cout << "Level Mode:\n";
    for (int i = 0; i < MAX_HIGH_SCORES; i++) {
        gotoxy(12, 11 + i);
        if (!levelScores[i].playerName.empty()) {
            cout << i + 1 << ". " << levelScores[i].playerName << " - " << levelScores[i].score;
        }
        else {
            cout << i + 1 << ". ---";
        }
    }

    gotoxy(10, 16);
    cout << "Custom Mode:\n";
    for (int i = 0; i < MAX_HIGH_SCORES; i++) {
        gotoxy(12, 17 + i);
        if (!customScores[i].playerName.empty()) {
            cout << i + 1 << ". " << customScores[i].playerName << " - " << customScores[i].score;
        }
        else {
            cout << i + 1 << ". ---";
        }
    }

    gotoxy(10, 23);
    cout << "Press Enter to return to the main menu...";
    cin.get();
    cin.ignore();
   
    Sleep(500);

}

void loadHighScores(const string& fileName, HighScore scores[]) {
    ifstream file(fileName);
    if (!file.is_open()) return;

    for (int i = 0; i < MAX_HIGH_SCORES && file; ++i) {
        getline(file, scores[i].playerName);
        file >> scores[i].score;
        file.ignore(); 
    }
    file.close();
}


void saveHighScores(const string& fileName, HighScore scores[]) {
    ofstream file(fileName);
    if (!file.is_open()) return;

    for (int i = 0; i < MAX_HIGH_SCORES; ++i) {
        if (!scores[i].playerName.empty()) {
            file << scores[i].playerName << endl;
            file << scores[i].score << endl;
        }
    }
    file.close();
}
void updateHighScores(HighScore scores[], const string& playerName, int score) {
    for (int i = 0; i < MAX_HIGH_SCORES; ++i) {
        if (score > scores[i].score) {
            // Sort
            for (int j = MAX_HIGH_SCORES - 1; j > i; --j) {
                scores[j] = scores[j - 1];
            }
          
            scores[i] = { playerName, score };
            break;
        }
    }
}

int main() {
    
    loadHighScores(INFINITE_FILE, infiniteScores);
    loadHighScores(LEVEL_FILE, levelScores);
    loadHighScores(CUSTOM_FILE, customScores);


    int mode = 0;
    int speed;
    srand(time(0));
    int score = 0;
   
    

    while (true) {
        int m = rand() % 3; 

        if (m == 0) {
            PlaySound(TEXT("C:\\Users\\WASTY\\Downloads\\Aria-Math.wav"), NULL, SND_FILENAME | SND_ASYNC);
        }   
        else if (m == 1) {
            PlaySound(TEXT("C:\\Users\\WASTY\\Downloads\\Moog-City.wav"), NULL, SND_FILENAME | SND_ASYNC);
        }
        else if (m == 2) {
            PlaySound(TEXT("C:\\Users\\WASTY\\Downloads\\c418-sweden-minecraft-volume-alpha.wav"), NULL, SND_FILENAME | SND_ASYNC);
        }

        ;
        mode = mainMenu();

        if (mode == 5) { // Exit the game
            system("CLS");
            cout << "Thanks for visiting!";
            break;
        }
        else if (mode == 4) { // Display high scores

            displayHighScores();
            continue;


        }
    
    resetGame(score);
    system("CLS");

    string playerName;
    cout << "Enter your name: ";
    cin >> playerName;
    Sleep(100);




    int selectedIndex = 0; 
    int key;
    bool running = true;
    system("CLS");
    while (running) {
        

        // Draw title
        drawChooseSnake();

        // snake
        myRect2(400, 280, 600, 300, R[selectedIndex], G[selectedIndex], B[selectedIndex]);

        // Handle input
        if (isCursorKeyPressed(key)) {
            if (key == 1) { // Left key
                selectedIndex = (selectedIndex - 1 + 11) % 11; //  left with wrap-around
            }
            else if (key == 2) { // Right key
                selectedIndex = (selectedIndex + 1) % 11; // right with wrap-around
            }

            Sleep(100); 
            while (isCursorKeyPressed(key)) {
                Sleep(30); 
            }
        }

        
        if (GetAsyncKeyState(VK_RETURN) & 0x8000) { // Enter key
            Sleep(100); 
            while (GetAsyncKeyState(VK_RETURN) & 0x8000) {
                Sleep(30);
            }
            Sleep(100); 
            running = false;
        }

      
    }
    system("CLS");






    
    if (mode == 1) { // Infinite mode
        int x = 400, y = 300, direction = 0, score = 0, speed = 10;
        snakeBody[0][0] = x;
        snakeBody[0][1] = y;
        snakeLength = 1;

        while (true) {
            int x = 400, y = 300;
            int W = 0, w;


            snakeBody[0][0] = x;
            snakeBody[0][1] = y;



            while (true) {
                if (foodX == -1 && foodY == -1) {
                    spawnFoodI();
                }

                myEllipse(foodX + 2, foodY + 2, foodX + 10, foodY + 10, 255, 255, 0);

                if (isCursorKeyPressed(w)) {
                    W = w;
                }

                updateSnakeInfinite(x, y, W);
                cout << "Endless |" << "Score: " << score << "    \r";
                if (checkFoodCollisionI(x, y)) {
                    score += 1;
                    snakeLength += 2;

                    spawnFoodI();
                }

                renderSnakeI(R[selectedIndex], G[selectedIndex], B[selectedIndex]);

                if (checkSelfCollisionI()) {

                    system("CLS");


                    break;
                }

                
                
                system("CLS");
               
            }

            break;

        }
        gameOver(score);
        updateHighScores(infiniteScores, playerName, score);
        saveHighScores(INFINITE_FILE, infiniteScores);
    }
    else if (mode == 2) { // Level mode
        int type;
        type = Menu2();
        Sleep(30);
        
        

        if (type == 1) {
            int level = 1; 
            const int menuOptions = 3; 



            while (true) {
                system("CLS"); // Clear the screen

                
                setConsoleColor(255, 255, 0); // Yellow
                cout << "\n\n\n\n\n                                ==================================\n";
                cout << "                                     SELECT LEVEL\n";
                cout << "                                ==================================\n";
                setConsoleColor(255, 255, 255); // white 

                for (int i = 1; i <= menuOptions; i++) {
                    string optionText = "Level " + to_string(i);

                    // selected level
                    if (i == level) {
                        setConsoleColor(0, 255, 255); // Bright cyan
                        cout << "                                  > " << optionText << " <\n";
                    }
                    else {
                        setConsoleColor(255, 255, 255); // white 
                        cout << "                                    " << optionText << "\n";
                    }
                }

                
                if (GetAsyncKeyState(VK_UP) & 0x8000) { // Up Arrow Key
                    level = (level - 2 + menuOptions) % menuOptions + 1; 
                    Sleep(150); 
                }
                if (GetAsyncKeyState(VK_DOWN) & 0x8000) { // Down Arrow Key
                    level = (level) % menuOptions + 1; 
                    Sleep(150); 
                }

               
                if (GetAsyncKeyState(VK_RETURN) & 0x8000) { // Enter key
                    setConsoleColor(255, 255, 255); 

                    
                    while (GetAsyncKeyState(VK_RETURN) & 0x8000) {
                        Sleep(30); 
                    }

                    system("CLS");
                    cout << "Level " << level << " Selected. Press Enter to Continue." << endl;
                    Sleep(20);
                    cin.get();
                    cin.ignore();
                   
                    break;
                }

                Sleep(30); // smoother input handling
            }

            int x = 475, y = 237, W = 0; 
            score = 0;
            snakeLength = 1;
            snakeBody[0][0] = x;
            snakeBody[0][1] = y;
            foodX = -1;
            foodY = -1;

            system("CLS");

            while (true) {
                drawLevel(level, R[selectedIndex], G[selectedIndex], B[selectedIndex]);

                if (foodX == -1 && foodY == -1) {
                    spawnFood();
                }

                myEllipse(foodX + 2, foodY + 2, foodX + 10, foodY + 10, 255, 255, 0);

                if (isCursorKeyPressed(W)) {
                    // Direction updated via isCursorKeyPressed
                }

                updateSnake(x, y, W);

                if (checkFoodCollision(x, y)) {
                     
                    score++;
                    snakeLength++;
                    spawnFood();
                }

                renderSnake(R[selectedIndex], G[selectedIndex], B[selectedIndex]);

                gotoxy(1, 1);
                cout << "Level: " << level << " | Score: " << score;

                if ((level == 1 && checkCollision(x, y)) ||
                    (level == 2 && checkCollision2(x, y)) ||
                    (level == 3 && checkCollision3(x, y)) ||
                    checkSelfCollision()) {
                    cout << "\nGame Over!\n";
                    break;
                }

                Sleep(100); // Control game speed
            }
            gameOver(score);
        }

        else if (type == 2) {
            system("CLS");
            int x = 475, y = 237, w = 0, W = 0;
            score = 0;
            int level = 1;
            const int maxWalls = 50;
            int walls = 2;
            int x1[maxWalls], x2[maxWalls], y1[maxWalls], y2[maxWalls];
            int speed = 5;
            clock_t levelStartTime = clock();

            snakeBody[0][0] = x;
            snakeBody[0][1] = y;

            // Initialize walls
            for (int i = 0; i < walls; i++) {
                x1[i] = 310 + rand() / 2 % 340;
                y1[i] = 130 + rand() / 2 % 230;
                if (rand() % 2) {
                    x2[i] = x1[i];
                    y2[i] = 130 + rand() / 2 % 230;
                }
                else {
                    y2[i] = y1[i];
                    x2[i] = 310 + rand() / 2 % 340;
                }
            }


            bool gameRunning = true;
            while (gameRunning) {
                myRect1(300, 120, 650, 360, R[selectedIndex], G[selectedIndex], B[selectedIndex]);
                for (int i = 0; i < walls; i++) {
                    myLine3(x1[i], y1[i], x2[i], y2[i], 134, 145, 134);
                }

                if (foodX == -1 && foodY == -1) {
                    spawnFood4(x1, y1, x2, y2, walls);
                }
                myEllipse(foodX + 2, foodY + 2, foodX + 10, foodY + 10, 255, 255, 0);

                if (isCursorKeyPressed(w)) {
                    W = w;
                }

                updateSnakeC(x, y, W, speed);

                if (checkFoodCollision(x, y)) {
                     
                    score++;
                    snakeLength++;
                    gotoxy(1, 1);
                    cout << " Survive 30 seconds or gain 10 score to level up!";
                    gotoxy(1, 2);
                    cout << "Infinite Survival | Level: " << level << " | Score: " << score << "\b";

                    spawnFood4(x1, y1, x2, y2, walls);
                }

                renderSnake(R[selectedIndex], G[selectedIndex], B[selectedIndex]);

                // Check for wall collisions
                for (int i = 0; i < walls; i++) {
                    if (checkCollision4(x, y, x1, y1, x2, y2, walls, i)) {
                        cout << "\nCollision detected! Game Over!" << " Final score: " << score << endl;
                        gameRunning = false; // End the game
                        break;
                    }
                }

                // Check for self-collision
                if (gameRunning && checkSelfCollision()) {
                    cout << "\nSelf-collision! Game Over!" << " Final score: " << score << endl;
                    gameRunning = false; // End the game
                }
                if ((clock() - levelStartTime) / CLOCKS_PER_SEC >= 25) {
                    gotoxy(1, 3); cout << " Levelling up soon";

                }
                // Level progression based on score or time
                if (gameRunning && (score >= 10 * level || (clock() - levelStartTime) / CLOCKS_PER_SEC >= 30)) {
                    level++;
                    score += 5;
                    walls += 1;
                    speed += 1;
                    foodX = -1;
                    foodY = -1;
                    gotoxy(2, 2);
                    cout << "Level up! Level: " << level << " | Score: " << score << endl;

                    // Generate new walls for the next level
                    for (int i = walls - 2; i < walls; i++) {
                        x1[i] = 300 + rand() % 350;
                        y1[i] = 120 + rand() % 240;
                        if (rand() % 2) {
                            x2[i] = x1[i];
                            y2[i] = 120 + rand() % 240;
                        }
                        else {
                            y2[i] = y1[i];
                            x2[i] = 300 + rand() % 350;
                        }
                    }

                    // Display the new level layout
                    system("CLS");
                    cout << "Level " << level << " - Preview" << endl;
                    myRect1(300, 120, 650, 360, R[selectedIndex], G[selectedIndex], B[selectedIndex]);

                    for (int i = 0; i < walls; i++) {
                        myLine3(x1[i], y1[i], x2[i], y2[i], 134, 145, 134);
                        renderSnake(R[selectedIndex], G[selectedIndex], B[selectedIndex]);
                    }

                    cout << "Press an arrow key to start Level " << level << "...";

                    // Wait for user input to start the level
                    W = 0;
                    while (true) {
                        if (isCursorKeyPressed(w)) {
                            W = w;
                            break;
                        }
                    }

                    // Reset the level start time and clear the screen
                    levelStartTime = clock();
                    system("CLS");
                }
                Sleep(50);
            }
        }
        gameOver(score);
        updateHighScores(levelScores, playerName, score);
        saveHighScores(LEVEL_FILE, levelScores);
    }
    else if (mode == 3) { // Custom mode

        system("CLS");

        int x = 400, y = 300;
        int W = 0, w;
        score = 0;

        snakeBody[0][0] = x;
        snakeBody[0][1] = y;

        int Flag = 1; 
        int Walls;
        int x1[100], x2[100], y1[100], y2[100];

        // Wall customization
        cout << "Enter the Amount of Walls You Would Like To Add:\n";

       
        do {
            cin >> Walls;

            if (cin.fail() || Walls < 0) { 
                cin.clear(); 
                cin.ignore(10000, '\n'); 

                cout << "Invalid Option. Try again.\n";
            }
            else {
                break; // Exit the loop when valid input is provided
            }
        } while (true);

        cout << "You entered " << Walls << " walls.\n";

        if (Walls != 0) {
            cout << "Range of Coordinates for walls: x (300-650) and y (120-360).\n"
                << "Remember: One axis must remain constant for each wall.\n";
        }
        for (int i = 0; i < Walls; i++) {
            do {
                system("CLS");
                myRect1(300 + 50, 120 + 50, 650 + 50, 360 + 50, R[selectedIndex], G[selectedIndex], B[selectedIndex]);

                for (int j = 0; j < i; j++) {
                    myLine3(x1[j] + 50, y1[j] + 50, x2[j] + 50, y2[j] + 50, 134, 145, 134);
                }
                cout << "Range of Coordinates for walls: x (300-650) and y (120-360)."
                    << "Remember: One axis must remain constant for each wall.\n";
                cout << "Enter the coordinates for wall " << i + 1 << ":\n";
                cout << "Start point (x1, y1): ";
                cin >> x1[i] >> y1[i];
                cout << "End point (x2, y2): ";
                cin >> x2[i] >> y2[i];

                if ((x1[i] < 300 || x1[i] > 650) || (y1[i] < 120 || y1[i] > 360) ||
                    (x2[i] < 300 || x2[i] > 650) || (y2[i] < 120 || y2[i] > 360) ||
                    (x1[i] != x2[i] && y1[i] != y2[i])) {
                    cout << "Invalid wall coordinates. Please try again.\n";
                }
                else {
                    break; 
                }
            } while (true);

            system("CLS");
        }
        myRect1(300 + 50, 120 + 50, 650 + 50, 360 + 50, R[selectedIndex], G[selectedIndex], B[selectedIndex]);

        for (int j = 0; j < Walls; j++) {
            
            myLine3(x1[j] + 50, y1[j] + 50, x2[j] + 50, y2[j] + 50, 134, 145, 134);
        }
        cout << "Press enter to continue...";
        cin.get();
        cin.ignore();
        
        
        do {
            cout << "Enter the speed of the snake (5 = slow, 10 = medium, 15 = fast, or higher): ";
            cin >> speed;
            if (speed <= 0) cout << "Speed must be positive. Try again.\n";
            system("CLS");
        } while (speed <= 0);

        while (Flag) {
            myRect1(300, 120, 650, 360, R[selectedIndex], G[selectedIndex], B[selectedIndex]);

            for (int i = 0; i < Walls; i++) {
                myLine3(x1[i], y1[i], x2[i], y2[i], 134, 145, 134);
            }

            if (foodX == -1 && foodY == -1) {
                spawnFood4(x1, y2, x2, y1, Walls);
            }
            myEllipse(foodX, foodY, foodX + 10, foodY + 10, 255, 255, 0);

            if (isCursorKeyPressed(w)) {
                W = w;
            }

            updateSnakeC(x, y, W, speed);

            if (checkFoodCollision(x, y)) {
                 
                score++;
                cout << "\rCustom | Score: " << score << "   ";
                snakeLength++;
                spawnFood4(x1, y2, x2, y1, Walls);
            }

            renderSnake(R[selectedIndex], G[selectedIndex], B[selectedIndex]);

            
            for (int i = 0; i < Walls; i++) {
                if (checkCollision4(x, y, x1, y1, x2, y2, Walls, i)) {
                    cout << "\nCollision detected! Game Over!\nFinal score: " << score << endl;
                    Flag = 0;
                    break;
                }
            }

            
            if (checkSelfCollision()) {
                cout << "\nSelf-collision! Game Over!\nFinal score: " << score << endl;
                Flag = 0;
                break;
            }

            Sleep(70);
        }
        gameOver(score);
        
        updateHighScores(customScores, playerName, score);
        saveHighScores(CUSTOM_FILE, customScores);
    }

  


}
    

    return 0;
}
