#include <stdio.h>

int main() {
    long long totalSeconds;
    int hours, minutes, seconds;

    // Ввод данных пользователем
    printf("Введите количество секунд: ");
    if (scanf("%lld", &totalSeconds) != 1 || totalSeconds < 0) {
        printf("Ошибка: введено некорректное значение.\n");
        return 1;
    }

    // Вычисление часов, минут и секунд
    hours = totalSeconds / 3600;

    long long remainingSeconds = totalSeconds % 3600;
    minutes = remainingSeconds / 60;
    seconds = remainingSeconds % 60;

    // Вывод результата с учетом условия про часы
    if (hours > 0) {
        // Если часы есть, выводим их вместе с минутами и секундами
        printf("%d час(ов), %d минута(ы), %d секунда(ы)\n", hours, minutes, seconds);
    }
    else {
        // Если часов нет (0), выводим только минуты и секунды
        printf("%d минута(ы), %d секунда(ы)\n", minutes, seconds);
    }

    return 0;
}
