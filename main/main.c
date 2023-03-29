// Esta es la version 2

#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

#define LED_R 15
#define LED_A 2
#define LED_V 0

void Tarea_LED_R(void *);
void Tarea_LED_A(void *);
void Tarea_LED_V(void *);

#define STACK_SIZE 2048

TaskHandle_t Handle_LED_R;
TaskHandle_t Handle_LED_A;
TaskHandle_t Handle_LED_V;

const char * TAG = "LED_TASK";

void app_main(void)
{
    xTaskCreate(Tarea_LED_R, "Tarea_LED_R", STACK_SIZE, NULL, 1, &Handle_LED_R);
    xTaskCreate(Tarea_LED_A, "Tarea_LED_A", STACK_SIZE, NULL, 1, &Handle_LED_A);
    xTaskCreate(Tarea_LED_V, "Tarea_LED_V", STACK_SIZE, NULL, 1, &Handle_LED_V);

    while(1)
    {
        printf("Bucle Main\r\n");
        vTaskDelay(10000/portTICK_PERIOD_MS);
    }
}

void Tarea_LED_R(void *p)
{
    gpio_reset_pin(LED_R);
    gpio_set_direction(LED_R, GPIO_MODE_OUTPUT);
    gpio_set_level(LED_R, 0);

    while(1)
    {
        ESP_LOGE(TAG, "Tarea LED R");
        gpio_set_level(LED_R, 1);
        vTaskDelay(1000/portTICK_PERIOD_MS);

        gpio_set_level(LED_R, 0);
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
}

void Tarea_LED_A(void *p)
{
    gpio_reset_pin(LED_A);
    gpio_set_direction(LED_A, GPIO_MODE_OUTPUT);
    gpio_set_level(LED_R, 0);

    while(1)
    {
        ESP_LOGW(TAG, "Tarea LED A");        
        gpio_set_level(LED_A, 1);
        vTaskDelay(2000/portTICK_PERIOD_MS);

        gpio_set_level(LED_A, 0);
        vTaskDelay(2000/portTICK_PERIOD_MS);
    }
}

void Tarea_LED_V(void *p)
{
    gpio_reset_pin(LED_V);
    gpio_set_direction(LED_V, GPIO_MODE_OUTPUT);
    gpio_set_level(LED_V, 0);

    while(1)
    {
        ESP_LOGI(TAG, "Tarea LED V");
        gpio_set_level(LED_V, 1);
        vTaskDelay(4000/portTICK_PERIOD_MS);

        gpio_set_level(LED_V, 0);
        vTaskDelay(4000/portTICK_PERIOD_MS);
    }
}