#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_sleep.h"
#include "esp_log.h"
#include "esp32/rom/uart.h"
#include "esp_timer.h"



void app_main()
{
    uint64_t tempo_sleep = 5000000; // configura o tempo do timer na variável tempo_sleep

    esp_timer_early_init(); /* inicializa o timer básico do chip, após declarar isso apenas funções do tipo get_time são aceitas */

    esp_sleep_enable_timer_wakeup(tempo_sleep); // define o tempo de acordo com a variável tempo_sleep

    printf("Iniciando modo sleep... \n"); // mensagem informativa

    int64_t inicio = esp_timer_get_time(); // registro de tempo 1

    esp_light_sleep_start(); // iniciando modo sleep

    int64_t fim = esp_timer_get_time(); // registro de tempo 2

    printf("Modo sleep durou %lld milisegundos.\n", (fim - inicio) / 1000); // expõe na saída o tempo gasto dormindo
}
