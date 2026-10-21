#include <stdio.h>

// Функция для правильного склонения слова "час"
const char* getHoursWord(int h) {
    if (h % 10 == 1 && h % 100 != 11) return "час";
    if ((h % 10 >= 2 && h % 10 <= 4) && !(h % 100 >= 12 && h % 100 <= 14)) return "часа";
    return "часов";
}

// Функция для правильного склонения слова "минута"
const char* getMinutesWord(int m) {
    if (m % 10 == 1 && m % 100 != 11) return "минута";
    if ((m % 10 >= 2 && m % 10 <= 4) && !(m % 100 >= 12 && m % 100 <= 14)) return "минуты";
    return "минут";
}

// Функция для правильного склонения слова "секунда"
const char* getSecondsWord(int s) {
    if (s % 10 == 1 && s % 100 != 11) return "секунда";
    if ((s % 10 >= 2 && s % 10 <= 4) && !(s % 100 >= 12 && s % 100 <= 14)) return "секунды";
    return "секунд";
}

int main() {
    long long totalSeconds;
    int hours, minutes, seconds;

    printf("Введите количество секунд: ");

    // Проверка ввода
    if (scanf("%lld", &totalSeconds) != 1 || totalSeconds < 0) {
        printf("Ошибка: введено некорректное значение.\n");
        return 1; // Возвращаем 1 как код ошибки
    }

    // Вычисления
    hours = (int)(totalSeconds / 3600);
    long long remainingSeconds = totalSeconds % 3600;

    minutes = (int)(remainingSeconds / 60);
    seconds = (int)(remainingSeconds % 60);

    // Вывод результата
    if (hours > 0) {
        // Если есть часы, выводим всё полностью с правильным склонением
        printf("%d %s, %d %s, %d %s\n",
            hours, getHoursWord(hours),
            minutes, getMinutesWord(minutes),
            seconds, getSecondsWord(seconds));
    }
    else {
        // Если часов нет, выводим только минуты и секунды
        printf("%d %s, %d %s\n",
            minutes, getMinutesWord(minutes),
            seconds, getSecondsWord(seconds));
    }

    return 0;
}