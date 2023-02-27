#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <time.h>

#define MAX_DROPS 30
#define DROP_FREQUENCY 25
#define SLEEP_TIME 50000
#define SPEED_INCREASE 10000

int x = 0, y = 0, userX = 0, score = 0, speed = SLEEP_TIME;

struct drop {
    int x, y;
};

struct drop drops[MAX_DROPS];

void update() {
    system("clear");

    // Move the drops down one line and redraw them
    for (int i = 0; i < MAX_DROPS; i++) {
        if (drops[i].y != -1) {
            drops[i].y++;

            if (drops[i].y > 19) {
                drops[i].y = -1;
            } else {
                printf("\033[%d;%dH", drops[i].y, drops[i].x);
                printf("*");
            }
        }
    }

    // Check if the user has been hit
    for (int i = 0; i < MAX_DROPS; i++) {
        if (drops[i].y == 19 && drops[i].x == userX) {
            printf("\033[22;0HYou were hit by a drop!");
            exit(0);
        }
    }

    // Move the user
    printf("\033[20;%dH", userX);
    printf("A");

    // Increase the score and speed
    score++;
    if (score % DROP_FREQUENCY == 0 && speed > 10000) {
        speed -= SPEED_INCREASE;
    }
}

int kbhit() {
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

int getch() {
    int ch;
    struct termios oldt;
    struct termios newt;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return ch;
}

int main() {
    // Initialize random seed
    srand(time(NULL));

    // Set up the drops
    for (int i = 0; i < MAX_DROPS; i++) {
        drops[i].x = rand() % 20 + 1;
        drops[i].y = rand() % 5;
    }

    // Set up the user
    userX = 10;

    // Set the terminal to raw mode
    system("stty raw