#include <time.h>
#include <stdio.h>

int main() {
    timer_t t;
    printf("monotonic: %d\n", timer_create(CLOCK_MONOTONIC, NULL, &t));
    printf("realtime: %d\n", timer_create(CLOCK_REALTIME, NULL, &t));
}