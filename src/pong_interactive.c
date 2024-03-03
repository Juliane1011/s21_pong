#include <stdio.h>
#include <unistd.h>

// Define это директива препроцессора, здесь она используется для создания макроса, с помощью него можно легко менять размеры поля
// WIDTH - Ширина
// HEIGHT - Высота
#define WIDTH 82
#define HEIGHT 27

// Функция для очистки терминала
void clearScreen() {
    printf("\033[2J"); // Очистка экрана
    printf("\033[H"); // Перемещение курсора в верхний левый угол
}

// Функция borderPlayingField отрисовывает границы нашего игрового поля
void borderPlayingField(int ballCenterX, int ballCenterY, int leftPaddleX, int rightPaddleX) {
    // Цикл отрисовывающий границу по ширине
    for (int i = 0; i < WIDTH; i++) {
        printf("_");
    }
    printf("\n");
    // Цикл отрисовывающий границу по высоте
    for (int i = 0; i < HEIGHT - 2; i++) {
        printf("|");
        // Цикл заполняющий пустоту внутри поля
        for (int j = 0; j < WIDTH - 2; j++) {
            if (i + 1 == ballCenterY && j + 1 == ballCenterX) {
                printf("☠︎"); // Выводим символ '☠︎' для шарика
            } else if (j == leftPaddleX && i >= ballCenterY - 1 && i <= ballCenterY + 1) {
                printf("⌻"); // Выводим символ '⌻' для левой ракетки
            } else if (j == rightPaddleX && i >= ballCenterY - 1 && i <= ballCenterY + 1) {
                printf("⌻"); // Выводим символ '⌻' для правой ракетки
            } else {
                printf(" ");
            }
        }
        printf("|\n");
    }
    // Цикл отрисовывающий границу по ширине
    for (int i = 0; i < WIDTH; i++) {
        printf("_");
    }
    printf("\n");
}

int main() {
    int ballCenterX = WIDTH / 2;
    int ballCenterY = HEIGHT / 2;
    int leftPaddleX = 1; // Позиция левой ракетки по оси X
    int rightPaddleX = WIDTH - 4; // Позиция правой ракетки по оси X
    int ballVelocityX = 1; // Скорость перемещения мяча по оси X
    int ballVelocityY = 1; // Скорость перемещения мяча по оси Y

    

    while (1) {
        // Очищаем терминал перед перерисовкой поля
        clearScreen();

        // Обновляем позицию мяча
        ballCenterX += ballVelocityX;
        ballCenterY += ballVelocityY;

        // Проверяем, не достиг ли мяч границ поля по оси X
        if (ballCenterX <= 1 || ballCenterX >= WIDTH - 2) {
            ballVelocityX = -ballVelocityX; // Изменяем направление по оси X
        }

        // Проверяем, не достиг ли мяч границ поля по оси Y
        if (ballCenterY <= 1 || ballCenterY >= HEIGHT - 2) {
            ballVelocityY = -ballVelocityY; // Изменяем направление по оси Y
        }

        // Отрисовываем игровое поле с обновленными координатами мяча
        borderPlayingField(ballCenterX, ballCenterY, leftPaddleX, rightPaddleX);

        // Задержка для создания эффекта движения мяча
        usleep(100000);
    }

    return 0;
}
