#include <stdio.h>

int main() {
    int scoreOne = 0;
    int scoreTwo = 0;
    int leftPlayer = 11;
    int rightPlayer = 11;
    int ball = 39;
    int ball_j = ball;
    int ball_i = 12;
    int move_vector_i = 1;
    int move_vector_j = -1;
    while (1) {
        for (int i = 0; i < 25; i++) {
            for (int j = 0; j < 80; j++) {
                if ((j == 1 && (i == leftPlayer || i == leftPlayer + 1 || i == leftPlayer + 2)) ||
                    (j == 78 && (i == rightPlayer || i == rightPlayer + 1 || i == rightPlayer + 2))) {
                    printf("|");
                } else if (i == 0 || i == 24) {
                    printf("=");
                } else if (j == ball_j && i == ball_i) {
                    printf("o");
                } else if (j == 0 || j == 79) {
                    printf(":");
                } else if (j == 38 || j == 39) {
                    printf("|");
                } else if (j == 32 && i == 3) {
                    printf("%d", scoreOne);
                } else if (j == 45 && i == 3) {
                    printf("%d", scoreTwo);
                } else
                    printf(" ");
            }
            printf("\n");
        }

        if (ball_i == 1 || ball_i == 23) {
            move_vector_i *= -1;
        }
        if (ball_j == 2 && (ball_i == leftPlayer || ball_i == leftPlayer + 1 || ball_i == leftPlayer + 2)) {
            move_vector_j *= -1;
        }
        if (ball_j == 77 &&
            (ball_i == rightPlayer || ball_i == rightPlayer + 1 || ball_i == rightPlayer + 2)) {
            move_vector_j *= -1;
        }
        ball_i += move_vector_i;
        ball_j += move_vector_j;

        if (ball_j < 2) {
            scoreTwo += 1;
            ball_j = ball;
            ball_i = 12;
        }
        if (ball_j > 77) {
            scoreOne += 1;
            ball_j = ball;
            ball_i = 12;
        }
        if (scoreTwo == 21) {
            printf("First player won!");
            break;
        }
        if (scoreOne == 21) {
            printf("Second player won!");
            break;
        }

        char start = getchar();

        if (start == 'z') {
            if (leftPlayer + 2 < 23) leftPlayer++;
        }

        if (start == 'a') {
            if (leftPlayer > 1) leftPlayer--;
        }

        if (start == 'm') {
            if (rightPlayer + 2 < 23) rightPlayer++;
        }

        if (start == 'k') {
            if (rightPlayer > 1) rightPlayer--;
        }

        if (start == 'q') {
            break;
        }
    }
    return 0;
}
