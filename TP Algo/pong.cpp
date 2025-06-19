#include <stdio.h>
#include <conio.h>
#include <windows.h>

// Define the game dimensions
#define WIDTH 40
#define HEIGHT 20

// Ball position
int ballX, ballY;
// Ball direction
int ballDirX, ballDirY;

// Paddle positions
int paddle1Y, paddle2Y;
const int paddleHeight = 4;

// Player scores
int score1 = 0, score2 = 0;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void drawBorders() {
    system("cls");
    for (int i = 0; i < WIDTH + 2; i++) printf("#");
    printf("\n");

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH + 2; j++) {
            if (j == 0 || j == WIDTH + 1)
                printf("#");
            else
                printf(" ");
        }
        printf("\n");
    }

    for (int i = 0; i < WIDTH + 2; i++) printf("#");
    printf("\n");
}

void drawPaddlesAndBall() {
    gotoxy(ballX + 1, ballY + 1);
    printf("O");

    // Draw paddle 1
    for (int i = 0; i < paddleHeight; i++) {
        gotoxy(1, paddle1Y + i + 1);
        printf("|");
    }

    // Draw paddle 2
    for (int i = 0; i < paddleHeight; i++) {
        gotoxy(WIDTH, paddle2Y + i + 1);
        printf("|");
    }

    // Display the score
    gotoxy(WIDTH / 2 - 2, 0);
    printf("%d - %d", score1, score2);
}

void moveBall() {
    // Erase the previous ball
    gotoxy(ballX + 1, ballY + 1);
    printf(" ");

    // Update ball position
    ballX += ballDirX;
    ballY += ballDirY;

    // Ball collision with the top or bottom wall
    if (ballY == 0 || ballY == HEIGHT - 1) {
        ballDirY = -ballDirY;
    }

    // Ball collision with the paddles
    if (ballX == 1 && ballY >= paddle1Y && ballY < paddle1Y + paddleHeight) {
        ballDirX = -ballDirX;
    }

    if (ballX == WIDTH - 1 && ballY >= paddle2Y && ballY < paddle2Y + paddleHeight) {
        ballDirX = -ballDirX;
    }

    // Ball goes out of bounds
    if (ballX == 0) {
        score2++;
        ballX = WIDTH / 2;
        ballY = HEIGHT / 2;
        ballDirX = 1;
        ballDirY = 1;
    } else if (ballX == WIDTH) {
        score1++;
        ballX = WIDTH / 2;
        ballY = HEIGHT / 2;
        ballDirX = -1;
        ballDirY = -1;
    }
}

void movePaddle1(char input) {
    if (input == 'w' && paddle1Y > 0) {
        paddle1Y--;
    } else if (input == 's' && paddle1Y < HEIGHT - paddleHeight) {
        paddle1Y++;
    }
}

void movePaddle2(char input) {
    if (input == 'o' && paddle2Y > 0) {
        paddle2Y--;
    } else if (input == 'l' && paddle2Y < HEIGHT - paddleHeight) {
        paddle2Y++;
    }
}

int main() {
    char input;

    // Initialize positions
    ballX = WIDTH / 2;
    ballY = HEIGHT / 2;
    ballDirX = -1;
    ballDirY = -1;
    paddle1Y = HEIGHT / 2 - paddleHeight / 2;
    paddle2Y = HEIGHT / 2 - paddleHeight / 2;

    drawBorders();

    while (1) {
        // Draw paddles and ball
        drawPaddlesAndBall();

        // Check if a key is pressed
        if (_kbhit()) {
            input = _getch();
            movePaddle1(input);  // Control paddle 1 with 'w' and 's'
            movePaddle2(input);  // Control paddle 2 with 'o' and 'l'
        }

        moveBall();

        // Delay to slow down the game
        Sleep(50);
    }

    return 0;
}

